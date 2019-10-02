// ====================
// Texture.hpp
// Header for Defining a Texture Struct
// A Texture holds a pointer to a color
// array as well as a width and a height.
// Used for holding color info for the GPU
// ====================

#pragma once

#include "szark_core.hpp"

struct Texture
{
    Color* pixels = nullptr;
    uint width = 0;
    uint height = 0;

    Texture() {}
    Texture(uint t_width, uint t_height) : 
        width(t_width), height(t_height) {
        pixels = new Color[width * height];
    }

    void free() { delete[] pixels; }

    void setPixel(uint x, uint y, Color color)
    {
        if (x >= 0 && x < width && y >= 0 && y < height)
            pixels[y * width + x] = color;        
    }
};