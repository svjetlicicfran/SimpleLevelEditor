#pragma once
#include <vector>
#include "const.hpp"
#include "vec2.hpp"
#include "tile.hpp"
#include <raylib.h>

class WorldGrid
{
private:
    int rows;
    int cols;
    std::vector<std::vector<Tile *>> grid; // 2D grid of tile pointers
    Texture2D *texture;                    // Tileset texture

public:
    WorldGrid(int r = Constants::worldRows, int c = Constants::worldCols, Texture2D *defaultTexture = nullptr);
    ~WorldGrid();

    void setTileAt(Vec2 pos, TileType type);
    Tile *getTileAt(Vec2 pos) const;

    void drawGrid() const;
};