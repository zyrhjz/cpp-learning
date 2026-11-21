#include<iostream>
#include<string>
int main() {
	std::string x;
	std::getline(std::cin, x);
	int count = 0;
	for (char ch : x) {
		if (ch == 'a') {
			count++;
		}
	}
	std::cout << count << std::endl;
	return 0;
}