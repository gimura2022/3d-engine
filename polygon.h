#pragma once
#include <vector>

#include "color.h"
#include "geometry.h"

struct Polygon3D
{
	union
	{
		struct
		{
			Vec3f p1;
			Vec3f p2;
			Vec3f p3;

			Color color;
		};
	};

	Polygon3D(Vec3f p1_, Vec3f p2_, Vec3f p3_, Color color_) : p1(p1_), p2(p2_), p3(p3_), color(color_) {}
};

void add_polygon_to_buffer(std::vector<Polygon3D>& zbuffer, Polygon3D polygon);