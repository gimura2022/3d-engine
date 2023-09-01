#include "polygon.h"
#include "math.h"

float get_polygon_z_pos(Polygon3D polygon) {
	std::vector<float> zpoints = { polygon.p1.z, polygon.p2.z, polygon.p3.z };

	return get_average_value<float>(zpoints);
}

void add_polygon_to_buffer(std::vector<Polygon3D>& zbuffer, Polygon3D polygon) {
	if (zbuffer.size() == 0) zbuffer.push_back(polygon); return;

	if ((get_polygon_z_pos(zbuffer[0]) - get_polygon_z_pos(polygon)) < (get_polygon_z_pos(zbuffer[zbuffer.size() - 1]) - get_polygon_z_pos(polygon))) {
		for (int i = 0; i < zbuffer.size() - 1; i++) {
			if (get_polygon_z_pos(zbuffer[i]) > get_polygon_z_pos(zbuffer[i + 1])) zbuffer.insert(zbuffer.begin() + i, polygon); return;
		}
		zbuffer.push_back(polygon); return;
	}
	else {
		for (int i = zbuffer.size(); i > 0 - 1; i--) {
			if (get_polygon_z_pos(zbuffer[i]) < get_polygon_z_pos(zbuffer[i - 1])) zbuffer.insert(zbuffer.begin() + i, polygon); return;
		}
		zbuffer.insert(zbuffer.begin(), polygon); return;
	}
}