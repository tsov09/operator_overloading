#include <iostream>

class A {
public:
	A(int x, int y) {
		this->x = x;
		this->y = y;
	}
	A operator ++ () {
		A temp = *this;
		this->x++;
		this->y++;
		std::cout << "in post " << this->x << " " << this->y << std::endl;
		std::cout << "in post temp " << temp.x << " " << temp.y << std::endl;
		return temp;
	}
	A& operator ++ (int x) {
		this->x++;
		this->y++;
		std::cout << "in pre " << this->x << " " << this->y << std::endl;
		return *this;
	}
	void f() {
		std::cout << "in f " << this->x << " " << this->y << std::endl;
	}
private:
	int x, y;
};

int main() {
	A ptr(4,4);
	A ptr_1(7,7);
	(++ptr).f();
	std::cout << std::endl;
	(ptr_1++).f();
	return 0;
}