#include<iostream>
class counter {
public:
	int value{};
};
int main() {
	counter a;
	a.value = 5;
	counter b;
	std::cout << a.value << std::endl;
	std::cout << b.value << std::endl;
	return 0;
}