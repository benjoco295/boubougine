#pragma once
#include "shader.h"
#include "mesh.h"
#include "camera.h"

class Renderer {
public:
    Renderer() = default;
    bool init(); // compile shader + GL state
    void render(const Mesh& mesh, const Camera& cam);
    ~Renderer() = default;
private:
    Shader shader;
};
