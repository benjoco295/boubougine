#pragma once
#include <array>

class Camera {
public:
    Camera() { for(int i=0;i<16;i++) m[i] = (i%5==0)?1.0f:0.0f; }
    const float* getMatrix() const { return m.data(); }
    void setOrtho(float l,float r,float b,float t,float n,float f);
    void setZoom(float z);       // positionne le zoom (1.0 = 100%)
    void addZoom(float dz);      // incrémente le zoom
    float getZoom() const { return zoom; }
private:
    void updateOrtho();          // recalcul interne de la matrice
    std::array<float,16> m;
    float left = -1.0f, right = 1.0f, bottom = -1.0f, top = 1.0f, nearP = -1.0f, farP = 1.0f;
    float zoom = 1.0f;
};
