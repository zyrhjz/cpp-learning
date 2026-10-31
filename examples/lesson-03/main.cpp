#include<iostream>
int main() {
	int stock = { 10 };
	int before = { stock };
	stock-= 3;
	std::cout << "before:" << before << std::endl;
	std::cout << "stock:" << stock << std::endl;
	const double price = { 2.5 };
	std::cout << 3 * price << std::endl;
	return 0;
}