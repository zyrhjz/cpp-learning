#include<iostream>
void swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}
int main() {
	int a{};
	int b{};
	std::cin >> a >> b;
	swap(a, b);
	std::cout << "a:" << a << std::endl;
	std::cout << "b:" << b << std::endl;
	return 0;
}
