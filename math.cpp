#include <iostream>
#include <algorithm>

#include "math.h"

template <class T> void bobble_sort<T>(std::vector<T>& arr, bool ascending) {
	for (int i = 0; i < arr.size() - 1; i++) {
		for (int j = 0; j < arr.size(); j++) {
			if (ascending) {
				if (arr[i] > arr[i + 1]) std::swap(arr[i], arr[i + 1]);
			}
			else {
				if (arr[i] < arr[i + 1]) std::swap(arr[i], arr[i + 1]);
			}
		}
	}
}

int get_min_run(int n) {
	int r = 0;
	while (n >= 64) {
		r |= n & 1;
		n >>= 1;
	}
	return n + r;
}

void sort_z_coord(std::vector<float>& zbuffer, std::vector<int>& facebuffer) {
	int n = zbuffer.size();
	int min_run = get_min_run(n);
}

template <class T> T get_average_value<T>(std::vector<T> arr) {
	T a = 0;
	for (int i = 0; i < arr.size(); i++) a += arr[i];
	return a / arr.size();
}