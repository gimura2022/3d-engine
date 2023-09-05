#include <fstream>
#include <string>

#include "image.h"

Texture::Texture(int width_, int height_) : width(width_), height(height_) { image = std::vector<Color>(Texture::width * Texture::height, Color(217, 9, 232)); }
Texture::~Texture() { image.clear(); }

void Texture::fill(Color color) {
	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) {
			image[i + j * width] = color;
		}
	}
}

void Texture::set_pix(int x, int y, Color color) {
	image[x + y * width] = color;
}

std::vector<std::string> split(std::string str, const char a) {
	int j = 0;
	std::string temp;
	std::vector<std::string> out;

	for (int i = 0; i < str.length(); i++) {
		if (str[i] == a) out[j] = temp; j++; temp.clear(); continue;
		temp += str[i];
	}

	return out;
}

bool Texture::load_texture_in_file(std::string path) {
	std::ifstream file;
	file.open(path);
	
	int i = 0;
	std::string temp;

	while (std::getline(file, temp)) {
		std::vector<std::string> colors = split(temp, ',');
		image[i] = Color(
			std::stoi(colors[0]),
			std::stoi(colors[1]),
			std::stoi(colors[2]),
			std::stoi(colors[3])
		);

		temp.clear();
		i++;
	}

	return true;
}

Color Texture::get_pix(int x, int y) {
	return image[x + y * width];
}