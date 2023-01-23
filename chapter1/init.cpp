#include <iostream>
#include <map>
#include <vector>
#include <initializer_list>

template<typename T>
using U = T;

class foo {
	int	a_;
	double b_;
	public:
		foo(): a_(0), b_(0){}
		foo(int a, double b = 0.0): a_(a), b_(b){}
		friend std::ostream& operator<<(std::ostream& os, const foo& f);
};

std::ostream& operator<<(std::ostream& os, const foo& f)
{
	os << f.a_ << " " << f.b_ << "\n";
	return os;
}

struct bar
{
	int		a_;
	double	b_;
};


void example1() {
	std::string s1("test"); // direct init
	std::string s2 = "test"; // copy init
	// uniform init
	U<std::string>	object {s1}; // direct list init
	U<std::string>	object2 = {s2}; // copy list init

	std::vector<int> v {1,2,3,4,5};
	std::map<int, std::string> m { {1, "one"}, {2, "two"}}; 
	int	arr[3]{1,2,3};
	int* arr_d = new int[3]{1,2,3};
	int	i {42};
	double d { 1.3};

	foo f1{};
	foo f2{42, 1.2};
	foo f3{42};
	foo f4 = 43;
	std::cout << f1;
	std::cout << f2;
	std::cout << f3;
	std::cout << f4;
	bar	b{42, 1.2};
	std::cout << b.a_ << " " << b.b_ << "\n";

	bar a = {22, 1.5}; // POD (plain old data) init
}

/**
 * @brief  std::initializer_list<T>. 
 * This is basically a lightweight proxy over an array of elements of the type T const
 * 
 * • The compiler resolves the types of the elements in the initialization list
 * (all the elements must have the same type).
 * • The compiler creates an array with the elements in the initializer list.
 * • The compiler creates an std::initializer_list<T> object to wrap the previously created array.
 * • The std::initializer_list<T> object is passed as an argument to the constructor.
 */

class boo {
	int a_;
	int b_;
	public:
		boo() :a_(0), b_(0) {}
		boo(int a, int b = 0) :a_(a), b_(b) {}
		boo(std::initializer_list<int> l) {
			if(l.size() == 2) {
				std::initializer_list<int>::iterator it = l.begin();
				a_ = *it++;
				b_ = *it;
			}
		}
		friend std::ostream& operator<<(std::ostream& os, const boo& n);
};

std::ostream& operator<<(std::ostream& os, const boo& b)
{
	os << b.a_ << " " << b.b_ << "\n";
	return os;
}

void	example2() {
	boo b{ 1, 2 }; // calls constructor with initializer_list<int>
	std::cout << b << "\n";

	std::vector<int> v1 {5}; // init_list with value of 5 - vector with 1 element
	std::vector<int> v2 (5); // inits vector with 5 elements

	std::cout << v1.size() << "\n";
	std::cout << v2.size() << "\n";

	auto a = {42}; // std::initializer_list<int> 
	auto b {42}; // std::initializer_list<int> 
	auto c = {4, 2}; // std::initializer_list<int> 
	auto d{4, 2}; // std::initializer_list<int>

	// New rules (c++17)
	auto a = {42}; // std::initializer_list<int> 
	auto b{42}; // int
	auto c = {4, 2}; // std::initializer_list<int> 
	auto d{4, 2}; // error, too many
}

int main() {
	example1();
	std::cout << std::endl;
	example2();
}
