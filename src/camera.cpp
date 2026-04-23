#include "camera.h"

void Camera::setOrtho(float l,float r,float b,float t,float n,float f){
    left=l; right=r; bottom=b; top=t; nearP=n; farP=f;
    updateOrtho();
}

void Camera::setZoom(float z){
    zoom = (z > 0.01f) ? z : 0.01f; // clamp minimal
    updateOrtho();
}

void Camera::addZoom(float dz){
    setZoom(zoom + dz);
}

void Camera::updateOrtho(){
    // applique le zoom centré : on réduit/augmente l/t/b/r autour du centre
    float cx = (left + right) * 0.5f;
    float cy = (top + bottom) * 0.5f;
    float hw = (right - left) * 0.5f / zoom;
    float hh = (top - bottom) * 0.5f / zoom;
    float l = cx - hw;
    float r = cx + hw;
    float b = cy - hh;
    float t = cy + hh;
    m = { 2.0f/(r-l),0,0,0, 0,2.0f/(t-b),0,0, 0,0,-2.0f/(farP-nearP),0, -(r+l)/(r-l),-(t+b)/(t-b),-(farP+nearP)/(farP-nearP),1 };
}
