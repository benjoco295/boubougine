#include "shader.h"
#include <iostream>

GLuint Shader::compile(GLenum type, const std::string& src) const {
    GLuint s = glCreateShader(type);
    const char* c = src.c_str();
    glShaderSource(s, 1, &c, nullptr);
    glCompileShader(s);
    GLint ok; glGetShaderiv(s, GL_COMPILE_STATUS, &ok);
    if(!ok){ char buf[1024]; glGetShaderInfoLog(s,1024,nullptr,buf); std::cerr<<buf<<"\n"; }
    return s;
}

bool Shader::loadFromStrings(const std::string& vsSrc, const std::string& fsSrc) {
    GLuint vs = compile(GL_VERTEX_SHADER, vsSrc);
    GLuint fs = compile(GL_FRAGMENT_SHADER, fsSrc);
    id = glCreateProgram();
    glAttachShader(id, vs); glAttachShader(id, fs);
    glLinkProgram(id);
    GLint ok; glGetProgramiv(id, GL_LINK_STATUS, &ok);
    if(!ok){ char buf[1024]; glGetProgramInfoLog(id,1024,nullptr,buf); std::cerr<<buf<<"\n"; glDeleteProgram(id); id=0;}
    glDeleteShader(vs); glDeleteShader(fs);
    return id != 0;
}

void Shader::setMat4(const char* name, const float* data) const {
    GLint loc = glGetUniformLocation(id, name);
    if(loc >= 0) glUniformMatrix4fv(loc, 1, GL_FALSE, data);
}

Shader::~Shader(){ if(id) glDeleteProgram(id); }
