#include<iostream>
int main() {
	int num{};
	int count = { 0 };
	while (std::cin >> num ) {
		if (num == 0) {
			break;
		}
		else if (num < 0) {
			continue;
		}
		else {
			count++;
		}
	}
	std::cout << count<< std::endl;
	return 0;
}