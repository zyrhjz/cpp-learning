#include<iostream>
class counter {
private:
	int value = { 7 };
	inline static int created = { 0 };
public:
	counter() {
		created++;
	}
friend int readvalue(const counter& value);
~counter(){
	std::cout << created << std::endl;
}
};
int readvalue(const counter& obj) {
	return obj.value;
}
int main() {
	counter a;
	{
		counter b;
	}
	std::cout << readvalue(a) << std::endl;
}