#include<iostream>
int main() {
	int data[2][3] = { {10, 20, 30}, {40, 50, 60} };
	int (*row)[3] = &data[0];
	*row++;
	std::cout << (*row)[1] << std::endl;
	return 0;
}