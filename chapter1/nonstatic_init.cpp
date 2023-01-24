#include <iostream>

enum class TextVerticalAlignment {Middle, Left, Right};

enum class TextHorizontalAlignment{Middle, Left, Right};

struct Control {
	const int defHeight = 14;
	const int defWidth = 80;

	TextVerticalAlignment	valign = TextVerticalAlignment::Middle;
	TextHorizontalAlignment	halign = TextHorizontalAlignment::Left;

	std::string	text;

	Control(std::string const& t): text(t) {}

	Control(std::string const& t, TextVerticalAlignment const va, TextHorizontalAlignment const ha): \
		text(t), valign(va), halign(ha) {} 
};


/**
 * @brief Non-static data members are supposed to be initialized in the constructor's initializer list.
 * The order in which non-static data members are destroyed is the reversed order of construction. 
 */

struct Point
{
	double X, Y;
	Point(double const x = 0.0, double const y = 0.0) : X(x), Y(y) {} 
};

/**
 * @brief Using assignments in the constructor is not efficient, as this can create temporary objects 
 * that are later discarded. If not initialized in the initializer list, non-static members 
 * are initialized via their default constructor and then, when assigned a value in 
 * the constructor's body, the assignment operator is invoked. This can lead to inefficient 
 * work if the default constructor allocates a resource (such as memory or a file) and 
 * that has to be deallocated and reallocated in the assignment operator. 
 */

struct foo {
	std::string	text_;
	foo() { std::cout << "default constructor\n"; }
	foo(std::string const& text): text_(text) { std::cout << "constructor for " << text << "\n"; }
	foo(foo const& other): text_(other.text_) { std::cout << "copy constructor\n"; }
	foo(foo&& other) { std::cout << "move constructor\n"; }
	foo& operator=(foo const& other) { std::cout << "assignment\n"; text_ = other.text_; return *this; }
	foo& operator=(foo&& other) { std::cout << "move assignment\n";  text_ = std::move(other.text_); return *this; }
	~foo() { std::cout << "destructor\n"; }
};

struct bar {
	foo	f;

	// bar(foo const& val) {
	// 	f = val;
	// }
	// Order in case of assignment
	// default constructor
	// default constructor
	// assignment
	// destructor
	// destructor

	bar(foo const& val): f(val) {}
	// constructor for Morning
	// copy constructor
	// destructor
	// destructor
};

void	example1() {
	foo	f("Morning");
	bar	b(f);
}

int main() {
	example1();
}