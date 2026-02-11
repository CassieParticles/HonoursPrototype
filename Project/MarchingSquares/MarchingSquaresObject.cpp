#include "../MarchingSquares/MarchingSquaresObject.h"

#include "Triangle.h"

MarchingSquaresObject::MarchingSquaresObject(float* data, int width, int height, bool dynamic):voxelGrid(data,width,height), renderable(&transform), physics(&transform)
{
    //Voxel grid needs -ve values on it's edges
    voxelGrid.AddBorder(-1.0f);
    voxelGrid.PrintValues();

    Generate(dynamic);
}

void MarchingSquaresObject::Render(sf::RenderWindow* window)
{
    renderable.Render(window);
}

void MarchingSquaresObject::Generate(bool dynamic)
{
    int width = voxelGrid.getWidth();
    int height = voxelGrid.getHeight();

    MarchingSquaresRenderable::MSRenderableBuilder graphicsBuilder = renderable.GetBuilder();
    MarchingSquaresPhysics::MSPhysicsBuilder physicsBuilder = physics.GetBuilder();
    physicsBuilder.SetDynamic(dynamic);

    triangles.clear();
    for(int y=0;y<height - 1; ++y)
    {
        for(int x=0;x<width - 1; ++x)
        {
            //Get the values for each of the 4 corners
            float cornerValues[4]
            {
                voxelGrid.getVoxel(x,y),
                voxelGrid.getVoxel(x+1,y),
                voxelGrid.getVoxel(x+1,y+1),
                voxelGrid.getVoxel(x,y+1)
            };

            //Get which case the cell is
            int index{};
            for(int i=0;i<4;++i)
            {
                index += (cornerValues[i] > 0) << i;
            }

            //Get the indices of the case
            const int* indexSet = indexTable[index];

            //Get the vertex position of each corner
            sf::Vector2f vertices[8];
            vertices[0] = sf::Vector2f(static_cast<float>(x + voxelGrid.getX()), static_cast<float>(y + voxelGrid.getY()) );
            vertices[2] = sf::Vector2f(static_cast<float>(x + 1 + voxelGrid.getX()), static_cast<float>(y + voxelGrid.getY()) );
            vertices[4] = sf::Vector2f(static_cast<float>(x + 1 + voxelGrid.getX()), static_cast<float>(y + 1 + voxelGrid.getY()) );
            vertices[6] = sf::Vector2f(static_cast<float>(x + voxelGrid.getX()), static_cast<float>(y + 1 + voxelGrid.getY()) );

            //Calculate the vertex position of each midpoint (lerp between positions)
            vertices[1] = findMidpointX(vertices[0],vertices[2],cornerValues[0],cornerValues[1]);
            vertices[3] = findMidpointY(vertices[2],vertices[4],cornerValues[1],cornerValues[2]);
            vertices[5] = findMidpointX(vertices[6],vertices[4],cornerValues[3],cornerValues[2]);
            vertices[7] = findMidpointY(vertices[0],vertices[6],cornerValues[0],cornerValues[3]);

            //Assemble triangles from indices using vertices
            for(int i=0;indexSet[i] != 8;i+=3)
            {
                triangles.emplace_back(
                    vertices[indexSet[i + 0]],
                    vertices[indexSet[i + 1]],
                    vertices[indexSet[i + 2]]
                );

                graphicsBuilder.AddTriangle({vertices[indexSet[i + 0]],
                    vertices[indexSet[i + 1]],
                    vertices[indexSet[i + 2]]});

                physicsBuilder.AddTriangle({vertices[indexSet[i + 0]],
                    vertices[indexSet[i + 1]],
                    vertices[indexSet[i + 2]]});
            }
        }
    }


    graphicsBuilder.Build();
    physicsBuilder.Build();
}
