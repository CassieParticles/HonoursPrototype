#pragma once
#include <GameObjects/GameObject.h>

#include "MarchingSquaresPhysics.h"
#include "MarchingSquaresRenderable.h"
#include "VoxelGrid.h"



class MarchingSquaresObject : public GameObject
{
public:
    MarchingSquaresObject();
    ~MarchingSquaresObject();

    void SetGrid(float* data, int width, int height);
    void SetGrid(VoxelGrid* grid);
    void SetDynamic(bool isDynamic);

    void Init() override;

    void Update() override;

    void Render(sf::RenderWindow* window) override;//Overwrite with new array//Overwrite with new array
private:
    void Generate(bool dynamic = false);

    VoxelGrid* voxelGrid;
    std::vector<Triangle> triangles;
    bool isDynamic;

    MarchingSquaresRenderable renderable;
    MarchingSquaresPhysics physics;

    //Indices of triangles in each case, 8 means no more triangles, CW order, starting at lowest
    constexpr static int indexTable[16][10]
    {
        {8,8,8,8,8,8,8,8,8,8},//0
        {0,7,1,8,8,8,8,8,8,8},
        {1,3,2,8,8,8,8,8,8,8},
        {0,7,3,0,3,2,8,8,8,8},
        {3,5,4,8,8,8,8,8,8,8},//4
        {0,7,1,3,5,4,8,8,8,8},
        {1,4,2,1,5,4,8,8,8,8},
        {0,7,2,2,7,5,2,5,4,8},
        {5,7,6,8,8,8,8,8,8,8},//8
        {0,5,1,0,6,5,8,8,8,8},
        {1,3,2,5,7,6,8,8,8,8},
        {0,3,2,0,5,3,0,6,5,8},
        {3,7,4,4,7,6,8,8,8,8},//12
        {0,6,1,1,6,3,3,6,4,8},
        {1,4,2,1,7,4,4,7,6,8},
        {0,4,2,0,6,4,8,8,8,8}
    };

    inline float normalise(float a, float b, float v) { return (v - a) / (b - a); }
    inline sf::Vector2f findMidpointX(sf::Vector2f a, sf::Vector2f b, float aVal, float bVal) { return sf::Vector2f(a.x + normalise(aVal, bVal, 0) * (b.x - a.x), a.y); }
    inline sf::Vector2f findMidpointY(sf::Vector2f a, sf::Vector2f b, float aVal, float bVal) { return sf::Vector2f(a.x, a.y + normalise(aVal, bVal, 0) * (b.y - a.y)); }
};
