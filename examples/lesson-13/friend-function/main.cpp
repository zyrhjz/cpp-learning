#include<iostream>
class counter {
private:
	int value = { 7 };
public:

friend int readvalue(const counter& value);
};
int readvalue(const counter& obj) {
	return obj.value;
}
int main() {
	counter c;
	std::cout << readvalue(c) << std::endl;
}