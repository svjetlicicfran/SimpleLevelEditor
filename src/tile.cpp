#include <raylib.h>
#include "../include/tile.hpp"

Tile::Tile(TileType _type, const Vec2& pos, Texture2D* tex) : position(pos), texture(tex), tileType(_type) {
    sourceRect = {  static_cast<float>(Constants::tileMap[tileType].first * Constants::tileSize), 
                    static_cast<float>(Constants::tileMap[tileType].second * Constants::tileSize),
                    static_cast<float>(Constants::tileSize), 
                    static_cast<float>(Constants::tileSize) };
}


Tile::Tile(TileType _type, Texture2D* tex) : texture(tex), tileType(_type) {

    position = Vec2{0,0};

    sourceRect = {  static_cast<float>(Constants::tileMap[tileType].first * Constants::tileSize), 
                    static_cast<float>(Constants::tileMap[tileType].second * Constants::tileSize),
                    static_cast<float>(Constants::tileSize),
                    static_cast<float>(Constants::tileSize) };
}

void Tile::drawTile() const {
    if (texture) {
        DrawTextureRec(*texture, sourceRect, position, WHITE);
    }
}

void Tile::drawTile(const Vec2& pos) const {
    if (texture) {
        DrawTextureRec(*texture, sourceRect, pos, WHITE);
    }
}