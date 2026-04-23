#include "renderer.h"

bool Renderer::init() {
    const std::string vs = R"(
    #version 330 core
    layout(location=0) in vec3 aPos;
    uniform mat4 uMVP;
    void main(){ gl_Position = uMVP * vec4(aPos,1.0); })";
    const std::string fs = R"(
    #version 330 core
    out vec4 FragColor;
    void main(){ FragColor = vec4(0.4,0.7,0.9,1.0); })";
    if(!shader.loadFromStrings(vs, fs)) return false;
    glEnable(GL_DEPTH_TEST);
    glClearColor(0.12f,0.12f,0.12f,1.0f);
    return true;
}

void Renderer::render(const Mesh& mesh, const Camera& cam) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    shader.use();
    shader.setMat4("uMVP", cam.getMatrix());
    mesh.draw();
}
