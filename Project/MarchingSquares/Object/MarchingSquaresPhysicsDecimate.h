#pragma once
#include <GameObjects/Transform.h>

#include "LineGroup.h"
#include "../Line.h"

class MarchingSquaresPhysicsDecimate
{
public:
    MarchingSquaresPhysicsDecimate(Transform* transform);
    ~MarchingSquaresPhysicsDecimate();

    class MSPhysicsBuilder
    {
        friend class MarchingSquaresPhysicsDecimate;
    public:
        void SetDynamic(bool isDynamic);

        void AddLine(Line line, int x, int y, int lineNo);

        void Build();
    private:
        MSPhysicsBuilder(MarchingSquaresPhysicsDecimate* object, int gridWidth, int gridHeight);
        MarchingSquaresPhysicsDecimate* object;

        std::vector<LineGroup> lineGroups;

        Line* lineArray;
        int gridWidth;
        int gridHeight;

        int getIndex(int x, int y, int lineNo) {return ((y * gridWidth ) + x) * 2 + lineNo;}
        sf::Vector2i getInitialLine();

        int lineCount;

        bool isDynamic;
    };

    MSPhysicsBuilder GetBuilder(int gridWidth, int gridHeight);
private:
    Transform* transform;

    b2BodyId bodyId;

};
