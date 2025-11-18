#include "../include/menuTile.hpp"

MenuTile::MenuTile(TileType type, const Vec2 &pos, Texture2D *tex) : position(pos), texture(tex), tileType(type)
{
    sourceRect = {static_cast<float>(Constants::tileMap[tileType].first * Constants::tileSize),
                  static_cast<float>(Constants::tileMap[tileType].second * Constants::tileSize),
                  static_cast<float>(Constants::tileSize),
                  static_cast<float>(Constants::tileSize)};
}

void MenuTile::drawTile() const
{
    if (texture)
    {
        DrawTexturePro(*texture, sourceRect, {position.x, position.y, Constants::menuTileSize, Constants::menuTileSize}, {0, 0}, 0.0f, WHITE);
    }
}
