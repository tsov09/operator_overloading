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

	void print_lvalue(A obj) {
		std::cout << "lvalue " << obj.x << std::endl;
	}
	void print_lvalue_ref(A& obj) {
		std::cout << "lvalue reference " << obj.x << std::endl;
	}
	void print_const_lvalue_ref(const A & obj) {
		std::cout << "const lvalue reference " << obj.x << std::endl;
	}
	void print_rvalue_ref(A&& obj) {
		std::cout << "rvalue reference " << obj.x << std::endl;
	}
	void print_const_rvalue_ref(const A&& obj) {
		std::cout << "const rvalue reference " << obj.x << std::endl;
	}
private:
	int x, y;
};


int main() {

	A ptr(4, 4);
	ptr.print_lvalue(ptr);
	ptr.print_lvalue_ref(ptr);
	ptr.print_const_lvalue_ref(ptr);
	//ptr.print_rvalue_ref(ptr);
	//ptr.print_const_rvalue_ref(ptr);

}