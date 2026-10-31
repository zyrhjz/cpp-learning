#include<iostream>
void swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}
int main() {
	int a{};
	int b{};
	if (!(std::cin >> a >> b)) {
		std::cout << "invalid" << std::endl;
		return 1;
	}
	swap(a, b);
	std::cout << "a:" << a << std::endl;
	std::cout << "b:" << b << std::endl;
	return 0;
}
