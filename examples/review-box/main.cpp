#include<iostream>
class box {
private:
	int value;
	static inline int  num= 0;
public:
	box() :value(0) {
		num++;
	}
	box(int x) :value(x){
		num++;
	}
	box(const box& other):value(other.value) {
		num++;
	}
	int getvalue() const{
		return value;
	}
	friend int compare(const box&a ,const box& b) {
		if (a.value > b.value) {
			return a.value;
		}
		else {
			return b.value;
		}
	}
	int getnum() {
		return num;
	}
	~box() {
		num--;
	}
};
int main() {
	box a(7);
	box b(4);
	std::cout << compare(a, b) << std::endl;
	std::cout << a.getnum() << std::endl;
	{
		const box c = a;
		std::cout << c.getvalue() << '\n';
		std::cout << a.getnum() << '\n';
	}
	std::cout << a.getnum() << '\n'; 
}