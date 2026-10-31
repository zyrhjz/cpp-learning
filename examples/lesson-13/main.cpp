#include<iostream>
class item {
public:
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