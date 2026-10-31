#include <iostream>
#include <bitset>
#include <limits>
int main() {
	std::cout << std::bitset<8>(26) << std::endl;
	std::cout << std::hex << 26 << std::endl;
	std::cout << std::dec << 42 << std::endl;
	return 0;
}