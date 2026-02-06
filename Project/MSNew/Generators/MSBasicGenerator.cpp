#include "MSBasicGenerator.h"

#include "../../MarchingSquares/VoxelGrid.h"


void MSBasicGenerator::Generate()
{
    int width = grid->getWidth();
    int height = grid->getHeight();

    for(int y = 0; y < height - 1; y++)
    {
        for(int x = 0; x < width - 1; x++)
        {
            //corner values
            float cornerValues[4]
            {
                grid->getVoxel(x,y),
                grid->getVoxel(x + 1,y),
                grid->getVoxel(x + 1,y + 1),
                grid->getVoxel(x,y + 1)
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
            vertices[0] = sf::Vector2f(static_cast<float>(x + grid->getX()), static_cast<float>(y + grid->getY()));
            vertices[2] = sf::Vector2f(static_cast<float>(x + 1 + grid->getX()), static_cast<float>(y + grid->getY()));
            vertices[4] = sf::Vector2f(static_cast<float>(x + 1 + grid->getX()), static_cast<float>(y + 1 + grid->getY()));
            vertices[6] = sf::Vector2f(static_cast<float>(x + grid->getX()), static_cast<float>(y + 1 + grid->getY()));

            //Calculate the vertex position of each midpoint (lerp between positions)
            vertices[1] = findMidpointX(vertices[0],vertices[2],cornerValues[0],cornerValues[1]);
            vertices[3] = findMidpointY(vertices[2],vertices[4],cornerValues[1],cornerValues[2]);
            vertices[5] = findMidpointX(vertices[6],vertices[4],cornerValues[3],cornerValues[2]);
            vertices[7] = findMidpointY(vertices[0],vertices[6],cornerValues[0],cornerValues[3]);

            //Assemble triangles from indices using vertices
            for(int i=0;indexSet[i] != 8;i+=3)
            {
                Triangle triangle = {
                    vertices[indexSet[i + 0]],
                    vertices[indexSet[i + 1]],
                    vertices[indexSet[i + 2]]
                };

                for(auto* builder : builders)
                {
                    builder->AddTriangle(triangle);
                }
            }
        }
    }
    for(auto* builder: builders)
    {
        builder->Build();
    }
}