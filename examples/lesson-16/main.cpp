#include<iostream>
#include<memory>
#include<utility>
int main() {
	{
		std::unique_ptr<int> owner = std::make_unique<int>(42);
		std::unique_ptr<int> next = std::move(owner);
		if (owner == nullptr) {
			std::cout << 1 << std::endl;
		}
		else {
			std::cout << 2 << std::endl;
		}
		std::cout << *next << std::endl;
		int* borrowed = next.get();
		std::cout << borrowed << std::endl;
		*borrowed = 99;
		std::cout << *next << std::endl;
	}
	return 0;
}