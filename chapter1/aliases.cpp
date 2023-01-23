#include <iostream>
#include <vector>

/**
 * @brief type alias is a name for another already declared type,
 * and an alias template is a name for another already declared
 * template.
 */

// identfier = type_id
using byte = unsigned char;
using byte_ptr = unsigned char *;
using array_t = int[10];
using fn = void(byte, double);

void	func(byte b, double d) {
	/*...*/
}

template<class T>
class custom_allocator{ /*...*/};

template<typename T>
using vec_t = std::vector<T, custom_allocator>>;

void	example1() {
	byte	b{42};
	byte_ptr	pb = new byte[10]{0};
	array_t		{0,1,2,3,4,5,6,7,8,9};
	fn	*f = func;

	vec_t<int>			vi;
	vec_t<std::string>	vs;
}

/**
 * @brief A typedef declaration introduces a synonym (an alias, in other words) for a type.
 * It does not introduce another type (like a class, struct, union, or enum declaration).
 */

typedef	unsigned char	byte_t;
typedef	unsigned char*	byte_ptr_t;
typedef	int				array_tt[10];
typedef	void(*fn_t)(byte_t, double);

template<typename T>
class foo {
	typedef	T	value;
};

typedef	std::vector<int>	vint_t;

int main() {
	example1();
}