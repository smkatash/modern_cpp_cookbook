# include <iostream>
# include <vector>
# include <map>
# include<string.h>

// no specific type
template <typename F, typename T>
auto apply(F&& f, T value) {
	return f(value);
};

void	example1() {
	auto i = 42; //int
	auto d = 42.5; // double
	auto s = "text"; // char const*
	auto v = {1, 2, 3}; // std::initializer_list<int>
}

void example2() {
	// auto name = type-id{explression}
	auto b = new char[10]{0}; // char *
	auto s1 = std::string{"text"}; //std::string
	auto v1 = std::vector<int>{1, 2, 3}; // std::vector
	auto p = std::make_shared<int>(42); // std::shared_ptr<int>

	// lambda experssions
	auto upper = [](char const c) { return toupper(c); };
	auto add = [](auto const a, auto const b) { return a + b;};
}

void	example3() {
	auto v = std::vector<int>{1, 2, 3};
	// implicit conversion, possible loss of data
	int size1 = v.size();
	// OK
	auto size2 = v.size();
	// ill-formed (warning in gcc/clang, error in VC++) without casting
	auto size3 = int{ static_cast<int>(v.size()) };
	std::cout << size1 << ", " << size2 << ", " << size3 << std::endl;

	std::map<int, std::string> m;
	for (std::map<int, std::string>::const_iterator it = m.cbegin(); it != m.cend(); ++it) {
		//...
	}
	// OR
	for (auto it = m.cbegin(); it != m.cend(); ++it) {
		//...
	}
}


class foo {
	int x_;
	public:
		foo(int const x = 0): x_{x} {}
		int& get() { return x_; }
};

//auto proxy_get(foo& f) { return f.get(); }
decltype(auto) proxy_get(foo& f) { return f.get(); }

/**
 * @brief The decltype type specifier yields the type of a specified expression. 
 * The decltype type specifier, together with the auto keyword, 
 * is useful primarily to developers who write template libraries. 
 * Use auto and decltype to declare a function template whose return type 
 * depends on the types of its template arguments
 */


void	example4() {
	foo f(42);
	//auto x = f.get();
	auto& x = f.get();
	x = 100;
	std::cout << f.get() << '\n';

	// auto& y = proxy_get(f); // error
 	decltype(auto) y = proxy_get(f);
	y = 200;
	std::cout << proxy_get(f) << '\n';
}

void	example5() {
	auto ai = std::atomic<int>(42); // error
	auto l1 = long long{42}; //error
	
	using llong = long long;
	auto l2 = llong{42}; // work around
	auto l3 = 42LL; // work around
	
	// c++11
	auto func1(int const i) -> int { return 2*i; }
	// c++14
	auto func2(int const i) { return 2*i; }
}

auto ladd = [](auto const a, auto const b) { return a + b; };
struct {
	template<typename T, typename U>
	auto operator() (T const a, U const b) const {
		return a + b; }
} L;

void example6() {
	auto i = ladd(40, 2);
	std::string a = "forty";
	std::string b = "two";
	auto m = ladd(a, b);
	std::cout << i << ", " << m << '\n';
}

int main() {
	example1();
	example2();
	example3();
	example4();
	example5();
	example6();
}
