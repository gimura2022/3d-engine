#include <windows.h>
#include <vector>
#include <iostream>

#include "draw.h"
#include "model.h"
#include "color.h"


void setPix(int x, int y, Color color, HDC hDC, int width, int height) {
    SetPixel(hDC, width - x, height - y, RGB(color.r, color.g, color.b));
}

void line(int x0, int y0, int x1, int y1, Color color, HDC hDC, int width, int height) {
    bool steep = false;
    if (std::abs(x0 - x1) < std::abs(y0 - y1)) {
        std::swap(x0, y0);
        std::swap(x1, y1);
        steep = true;
    }
    if (x0 > x1) {
        std::swap(x0, x1);
        std::swap(y0, y1);
    }

    for (int x = x0; x <= x1; x++) {
        float t = (x - x0) / (float)(x1 - x0);
        int y = y0 * (1. - t) + y1 * t;
        if (steep) {
            setPix(y, x, color, hDC, width, height);
        }
        else {
            setPix(x, y, color, hDC, width, height);
        }
    }
}


void triangle(Vec2i t0, Vec2i t1, Vec2i t2, Color color, HDC hDC, int width, int height) {
    if (t0.y == t1.y && t0.y == t2.y) return;
    if (t0.y > t1.y) std::swap(t0, t1);
    if (t0.y > t2.y) std::swap(t0, t2);
    if (t1.y > t2.y) std::swap(t1, t2);

    int total_height = t2.y - t0.y;

    for (int i = 0; i < total_height; i++) {
        bool second_half = i > t1.y - t0.y || t1.y == t0.y;
        int segment_height = second_half ? t2.y - t1.y : t1.y - t0.y;
        float alpha = (float)i / total_height;
        float beta = (float)(i - (second_half ? t1.y - t0.y : 0)) / segment_height;

        Vec2i A = t0 + (t2 - t0) * alpha;
        Vec2i B = second_half ? t1 + (t2 - t1) * beta : t0 + (t1 - t0) * beta;

        if (A.x > B.x) std::swap(A, B);
        for (int j = A.x; j <= B.x; j++) {
            setPix(j, t0.y + i, color, hDC, width, height);
        }
    }
}

void render(Model* model, int width, int height, Vec3f light_vector, float ambient_light, Color model_color, int mode, HDC hDC) {
    for (int i = 0; i < model->nfaces(); i++) {
        std::vector<int> face = model->face(i);

        Vec2i screen_coords[3];
        Vec3f world_coords[3];

        for (int j = 0; j < 3; j++) {
            Vec3f v = model->vert(face[j]);

            screen_coords[j] = Vec2i((v.x + 1.) * width / 2., (v.y + 1.) * height / 2.);
            world_coords[j] = v;
        }

        Vec3f n = (world_coords[2] - world_coords[0]) ^ (world_coords[1] - world_coords[0]);
        n.normalize();

        float scal = n * Vec3f(0, 0, -1);

        if (scal <= 0) continue;

        if (mode == 0 || mode == 1) {
            Color color = Color(
                model_color.r * scal,
                model_color.g * scal,
                model_color.b * scal
            );

            triangle(screen_coords[0], screen_coords[1], screen_coords[2], color, hDC, width, height);
        }
        else {
            for (int j = 0; j < 3; j++) {
                Vec3f v0 = model->vert(face[j]);
                Vec3f v1 = model->vert(face[(j + 1) % 3]);

                int x0 = (v0.x + 1.) * width / 2.;
                int y0 = (v0.y + 1.) * height / 2.;
                int x1 = (v1.x + 1.) * width / 2.;
                int y1 = (v1.y + 1.) * height / 2.;

                //            std::cout << "face " << model->nfaces() << "/" << i << std::endl;

                line(x0, y0, x1, y1, Color(255), hDC, width, height);
            }
        }
    }
}
