#pragma once
#include <GL/glew.h>
#include <string>

class Shader {
public:
    Shader() : id(0) {}
    bool loadFromStrings(const std::string& vsSrc, const std::string& fsSrc);
    void use() const { glUseProgram(id); }
    void setMat4(const char* name, const float* data) const;
    GLuint getId() const { return id; }
    ~Shader();
private:
    GLuint id;
    GLuint compile(GLenum type, const std::string& src) const;
};
