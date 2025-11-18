#pragma once
#include <raylib.h>
#include "vec2.hpp"

class CameraController {
private:
    Camera2D camera;
    Vec2 lastMouse;
    bool dragging;

public:

    CameraController();
    Camera2D& getCamera() const;
    void updateCamera();

    // Optionally, add setters/getters for camera params if needed
    void setTarget(const Vec2& t) { camera.target = t; }
    void setOffset(const Vec2& o) { camera.offset = o; }
    void setZoom(float z) { camera.zoom = z; }
    void setRotation(float r) { camera.rotation = r; }
    Vec2 getTarget() const { return camera.target; }
    Vec2 getOffset() const { return camera.offset; }
    float getZoom() const { return camera.zoom; }
    float getRotation() const { return camera.rotation; }
};