#include "MarchingSquaresPhysicsDecimate.h"

#include <iostream>
#include <Physics/PhysicsWorld.h>

MarchingSquaresPhysicsDecimate::MarchingSquaresPhysicsDecimate(Transform* transform):transform(transform) {}
MarchingSquaresPhysicsDecimate::~MarchingSquaresPhysicsDecimate()
{
    if(b2Body_IsValid(bodyId))
    {
        b2DestroyBody(bodyId);
    }
}



void MarchingSquaresPhysicsDecimate::MSPhysicsBuilder::SetDynamic(bool isDynamic) {this->isDynamic=isDynamic;}
void MarchingSquaresPhysicsDecimate::MSPhysicsBuilder::AddLine(Line line, int x, int y, int lineNo)
{
    int lineIndex = getIndex(x,y,lineNo);
    lineArray[lineIndex] = line;
    lineCount++;
}

void MarchingSquaresPhysicsDecimate::MSPhysicsBuilder::Build()
{
    b2BodyDef bodyDef = b2DefaultBodyDef();
    bodyDef.position = object->transform->GetPositionb2();
    bodyDef.rotation = object->transform->GetRotationb2();

    bodyDef.type = isDynamic ? b2_dynamicBody : b2_staticBody;
    object->bodyId = b2CreateBody(PhysicsWorld::GetWorldId(),&bodyDef);

    b2ShapeDef shapeDef = b2DefaultShapeDef();
    Line defaultLine = {};

    //Assemble into groups
    int linesAdded{};

    while(linesAdded < lineCount)
    {
        //Create group
        lineGroups.emplace_back();
        LineGroup& group = lineGroups.at(lineGroups.size()-1);

        //Get initial vertex
        sf::Vector2i currentCell = getInitialLine();
        Line* line = lineArray + getIndex(currentCell.x,currentCell.y,0);
        sf::Vector2f startingVertex = line->A;
        sf::Vector2f currentVertex = line->B;

        constexpr sf::Vector2i directions[4]
        {
            {0,-1},
            {0,1},
            {-1,0},
            {1,0},
        };

        group.AddVertex(startingVertex);
        while(currentVertex!=startingVertex)
        {
            //Check neighbors for shared vertex
            Line* lines[8];

            //Up
            lines[0] = lineArray + getIndex(currentCell.x,currentCell.y-1,0);
            lines[1] = lineArray + getIndex(currentCell.x,currentCell.y-1,1);
            //Down
            lines[2] = lineArray + getIndex(currentCell.x,currentCell.y+1,0);
            lines[3] = lineArray + getIndex(currentCell.x,currentCell.y+1,1);
            //Left
            lines[4] = lineArray + getIndex(currentCell.x-1,currentCell.y,0);
            lines[5] = lineArray + getIndex(currentCell.x-1,currentCell.y,1);
            //Right
            lines[6] = lineArray + getIndex(currentCell.x+1,currentCell.y,0);
            lines[7] = lineArray + getIndex(currentCell.x+1,currentCell.y,1);

            for(int i=0;i<8;++i)
            {
                //Shared vertex
                if(lines[i]->A == currentVertex)
                {
                    group.AddVertex(currentVertex);
                    currentVertex = lines[i]->B;
                    *line = {};
                    line = lines[i];
                    currentCell+=directions[i / 2];
                    linesAdded++;
                    break;
                }
                else if(lines[i]->B == currentVertex)
                {
                    group.AddVertex(currentVertex);
                    currentVertex = lines[i]->A;
                    *line = {};
                    line = lines[i];
                    currentCell+=directions[i / 2];
                    linesAdded++;
                    break;
                }
            }
        }
        *line = {};
        group.AddVertex(startingVertex);
        linesAdded++;


        group.DouglasPeucker(0.5f);
    }


}

MarchingSquaresPhysicsDecimate::MSPhysicsBuilder::MSPhysicsBuilder(MarchingSquaresPhysicsDecimate* object, int gridWidth, int gridHeight)
    :object(object),gridWidth(gridWidth),gridHeight(gridHeight),isDynamic(false),lineCount(0)
{
    //2 lines per cell
    lineArray = new Line[gridWidth * gridHeight * 2];
}

sf::Vector2i MarchingSquaresPhysicsDecimate::MSPhysicsBuilder::getInitialLine()
{
    Line defaultLine{};
    for(int y=0;y<gridHeight;y++)
    {
        for(int x=0;x<gridWidth;x++)
        {
            Line* line = lineArray + getIndex(x,y,0);
            //Line is something
            if(*line!=defaultLine)
            {
                return {x,y};
            }
        }
    }
    return {-1,-1};
}

MarchingSquaresPhysicsDecimate::MSPhysicsBuilder MarchingSquaresPhysicsDecimate::GetBuilder(int gridWidth, int gridHeight)
{
    return {this,gridWidth,gridHeight};
}
