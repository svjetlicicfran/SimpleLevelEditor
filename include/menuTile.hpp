#pragma once
#include <raylib.h>
#include "const.hpp"
#include "vec2.hpp"

class MenuTile
{

private:
    Rectangle sourceRect; // Source rectangle from the tileset
    Vec2 position;        // Position to draw the tile in the menu
    TileType tileType;    // Type of the tile
    Texture2D *texture;   // Pointer to the tileset texture

public:
    MenuTile(TileType type, const Vec2 &pos = (Vec2){0, 0}, Texture2D *tex = nullptr);

    void drawTile() const;

    Rectangle getBoundingBox() const
    {
        return (Rectangle){position.x, position.y, Constants::tileSize * 3.5f, Constants::tileSize * 3.5f};
    }

    TileType getTileType() const
    {
        return tileType;
    }
};