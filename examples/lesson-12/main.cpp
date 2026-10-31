#include<iostream>
#include<limits>
class counter {
private:
	int value = { 0 };
public:
	counter(int n) { setvalue(n); }
	counter() {};
	bool crease() {
		if (value == std::numeric_limits<int>::max()) {
			return false;
		}
		value += 1;
		return true;
	}
	int getvalue() const {
		return value;
	}
	bool setvalue(int n) {
		if (n < 0) {
			return false;
		}
		else {
			value = n;
			return true;
		}

	}
	~counter() {
		std::cout << "destroy" << " " << value << std::endl;
	}
};
int main() {
	counter a;
	const counter b(8);
	std::cout << b.getvalue() << std::endl;
	return 0;
}
