#include<iostream>
class item {
public:
	//用来记录生成了几个对象//
	static int created;
	item() { created += 1; }
};
int item::created = 0;
int main() {
	item a;
	std::cout << item::created << std::endl;
	item b;
	std::cout << item::created << std::endl;
	return 0;
}