#pragma once

#include <raylib.h>
#include "const.hpp"
#include "vec2.hpp"

class Tile {
private:
    Rectangle sourceRect; // Source rectangle in the tileset
    Vec2 position;        // Position to draw the tile
    Texture2D* texture;   // Pointer to the tileset texture
    TileType tileType;    // Type of the tile (e.g., Brick, Stone)


public:
    Tile(TileType _type, const Vec2& pos, Texture2D* tex);

    Tile(TileType _type, Texture2D* tex);

    void drawTile() const;
    
    void drawTile(const Vec2& pos) const;

    TileType getTileType() const { return tileType; }

};