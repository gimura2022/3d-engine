#pragma once
#include <vector>

#include "color.h"
#include "geometry.h"

class Texture
{
public:
	Texture(int width, int height);
	~Texture();

	void fill(Color color);
	void set_pix(int x, int y, Color color);
	bool load_texture_in_file(std::string path);
	Color get_pix(int x, int y);
	
	std::vector<Color> image;
	int width, height;
};