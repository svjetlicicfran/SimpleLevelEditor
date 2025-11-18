#include "../include/cameraController.hpp"

CameraController::CameraController() : dragging(false)
{
    camera = {0, 0, 0, 0, 0, 0};
    camera.target = Vec2(0, 0);
    camera.offset = Vec2(0, 0);
    camera.rotation = 0.0f;
    camera.zoom = 5.0f;
}

Camera2D &CameraController::getCamera() const
{
    return const_cast<Camera2D &>(camera);
}

void CameraController::updateCamera()
{

    if (IsMouseButtonPressed(MOUSE_MIDDLE_BUTTON))
    {
        dragging = true;
        lastMouse = GetMousePosition();
    }
    if (IsMouseButtonReleased(MOUSE_MIDDLE_BUTTON))
    {
        dragging = false;
    }
    if (dragging)
    {
        Vec2 mouse = GetMousePosition();
        Vec2 delta = mouse - lastMouse;
        camera.target = Vec2(camera.target) - delta * (1.0f / camera.zoom);
        lastMouse = mouse;
    }

    float wheel = GetMouseWheelMove();
    if (wheel != 0)
    {
        float zoomIncrement = 0.1f;
        float prevZoom = camera.zoom;
        camera.zoom += wheel * zoomIncrement * camera.zoom;
        if (camera.zoom < 2.0f)
            camera.zoom = 2.0f;
        if (camera.zoom > 10.0f)
            camera.zoom = 10.0f;

        Vec2 mouseWorldPos = GetScreenToWorld2D(GetMousePosition(), camera);
        camera.target = Vec2(camera.target) + (mouseWorldPos - Vec2(camera.target)) * (1.0f - prevZoom / camera.zoom);
    }
}
