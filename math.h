#pragma once
#include <vector>

template <class T>
void bobble_sort(std::vector<T>& arr, bool ascending);

void sort_z_coord(std::vector<float>& zbuffer, std::vector<int>& facebuffer);

template <class T>
T get_average_value(std::vector<T> arr);