#include <iostream>
#include <vector>
#include <cmath>
#include <windows.h>

#include "model.h"
#include "geometry.h"
#include "draw.h"
#include "color.h"
#include "polygon.h"

const char* path_to_model = "obj/player.obj"; 

const Vec3f light_vector = Vec3f(0, 0, 1);
const float ambient_light = 0.3f;
const Color model_color = Color(200);

const int width = 500;
const int height = 500;

const int mode = 0;

Model *model = NULL;

HWND hWnd = GetConsoleWindow();
HDC hDC = GetDC(hWnd);

int main(int argc, char** argv) {
    std::cout << "loading model..." << std::endl;
    model = new Model(path_to_model);

    std::vector<Polygon3D> zbuffer;

    render(model, width, height, light_vector, ambient_light, model_color, mode, hDC, zbuffer);

    delete model;

    std::cout << "rendering done!" << std::endl;

    getchar();

    return 0;
}