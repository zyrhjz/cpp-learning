#include<iostream>
int main() {
	int age{};
	if (!(std::cin >> age)) {
		std::cout << "invalid" << std::endl;
		return 1;
	}
	if (age < 0 || age>150) {
		std::cout << "invalid" << std::endl;
		return 1;
	}
	else if(age<18) {
		std::cout << "minor" << std::endl;
	}
	else if (age >= 18 && age <= 59) {
		std::cout << "adult" << std::endl;
	}
	else {
		std::cout << "senior" << std::endl;
	}
	return 0;
}