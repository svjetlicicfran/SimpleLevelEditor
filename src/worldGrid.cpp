#include "../include/worldGrid.hpp"

WorldGrid::WorldGrid(int r, int c, Texture2D *defaultTexture) : rows(r), cols(c), texture(defaultTexture)
{
    grid.resize(rows, std::vector<Tile *>(cols, nullptr));

    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            grid[i][j] = new Tile(TileType::Air, texture); // Default to Air tile with default texture
        }
    }
}

WorldGrid::~WorldGrid()
{
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            delete grid[i][j];
        }
    }
}

void WorldGrid::setTileAt(Vec2 pos, TileType type)
{
    int x = static_cast<int>(pos.x);
    int y = static_cast<int>(pos.y);
    if (x >= 0 && x < cols && y >= 0 && y < rows)
    {
        delete grid[y][x]; // Free existing tile memory
        grid[y][x] = new Tile(type, texture);
    }
}

void WorldGrid::drawGrid() const
{
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            if (grid[i][j])
            {
                
                Vec2 pos(j * Constants::tileSize, i * Constants::tileSize);
                grid[i][j]->drawTile(pos);
                DrawRectangleLinesEx((Rectangle){pos.x, pos.y, Constants::tileSize, Constants::tileSize}, 0.25f, (Color){255, 255, 255, 100}); // Optional: Draw gridlines
            }
        }
    }
}