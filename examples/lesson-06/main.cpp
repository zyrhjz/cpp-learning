#include<iostream>
int main() {
	long long sum = { 0 };
	int i{};
	if (!(std::cin >> i)) {
		std::cout << "invalid" << std::endl;
		return 1;
	}
	if (i < 0 || i>10000) {
		std::cout << "invalid" << std::endl;
		return 1;
	}
	else {
		for (int j =2;j <= i;j++) {
			if (j % 2 == 0) {
				sum += j;
			}
		}
	}
	std::cout << sum << std::endl;
	return 0;

}