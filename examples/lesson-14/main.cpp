#include<array>
#include<iostream>
int sumarray(const int arrry[], int size) {
	int sum = 0;
	for (int i = 0;i < size; i++) {
		sum += arrry[i];
	}
	return sum;
}
int main() {
	const int array[4] = { 4, -2, 7, 1 };
	constexpr int N = 4;
	int data[N] = { 4, -2, 7, 1 };
	int size = 4;
	std::cout << sumarray(array, size) << std::endl;
	size = 2;
	std::cout << sumarray(array, size) << std::endl;
	return 0;
}
