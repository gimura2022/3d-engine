#pragma once
struct Color
{
	union {
		struct { int r, g, b, a; };
		int raw[4];
	};

	Color() : r(0), g(0), b(0), a(0) {}
	Color(int color) : r(color), g(color) ,b(color), a(255) {
		raw[0] = color;
		raw[1] = color;
		raw[2] = color;
		raw[3] = 255;
	}
	Color(int r_, int g_, int b_) : r(r_), g(g_), b(b_), a(255) {
		raw[0] = r;
		raw[1] = g;
		raw[2] = b;
		raw[3] = 255;
	}
	Color(int r_, int g_, int b_, int a_) : r(r_), g(g_), b(b_), a(a_) {
		raw[0] = r;
		raw[1] = g;
		raw[2] = b;
		raw[3] = a;
	}
};