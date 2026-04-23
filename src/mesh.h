#pragma once
#include <GL/glew.h>
#include <vector>

class Mesh {
public:
    Mesh() : VAO(0), VBO(0), vertexCount(0) {}
    void upload(const std::vector<float>& verts); // verts = x,y,z, ...
    void draw() const;
    ~Mesh();
private:
    GLuint VAO, VBO;
    GLsizei vertexCount;
};
