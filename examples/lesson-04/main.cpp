#include<iostream>
#include<iomanip>
int main() {
	int a{};
	int b{};
	if (!(std::cin >> a >> b)) {
		std::cout << "input error!" << std::endl;
		return 1;
	}
	if (a<-10000 || a > 10000 || b < -10000 || b>10000) {
		std::cout << "range error!" << std::endl;
		return 1;
	}
	if (b == 0) {
		std::cout << "zero" << std::endl;
		return 1;
	}
	std::cout << std::fixed << std::setprecision(2);
	std::cout << static_cast<double>(a)/b<< std::endl;
	std::cout << a % b << std::endl;
	return 0;
}