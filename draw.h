#pragma once
#include "geometry.h"
#include "model.h"
#include "color.h"

void setPix(int x, int y, Color color, HDC hDC, int width, int height);
void line(int x0, int y0, int x1, int y1, Color color, HDC hDC, int width, int height);
void triangle(Vec2i t0, Vec2i t1, Vec2i t2, Color color, HDC hDC, int width, int height);
void render(Model* model, int width, int height, Vec3f light_vector, float ambient_light, Color model_color, int mode, HDC hDC);