#ifndef __MODEL_H__
#define __MODEL_H__

#include <vector>

#include "geometry.h"
#include "image.h"
#include "color.h"

class Model {
private:
	std::vector<Vec3f> verts_;
	std::vector<std::vector<Vec3i> > faces_;
	std::vector<Vec3f> norms_;
	std::vector<Vec2f> uv_;
	Texture diffusemap_ = Texture(64, 64);
	void load_texture(std::string filename, const char* suffix, Texture& img);
public:
	Model(const char* filename);
	~Model();
	int nverts();
	int nfaces();
	Vec3f vert(int i);
	Vec2i uv(int iface, int nvert);
	Color diffuse(Vec2i uv);
	std::vector<int> face(int idx);
};

#endif //__MODEL_H__