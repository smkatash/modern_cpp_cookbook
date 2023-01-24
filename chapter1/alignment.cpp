#include <iostream>
using namespace std;
struct alignas(4) foo {
	char a;
	char b;
};

struct bar {
	alignas(2) char a;
	alignas(8) int b;
};


void	example1() {
	alignas(8)		int a;
	alignas(256)	long b[4];
	auto align1 = alignof(foo);
	auto align2 = alignof(b);
	cout << align1 << "\n";
	cout << align2 << "\n";
}

// size = 1, alignment = 1 // foo1: +-+
// members: |a|
struct foo1 {
	char a; 
};

// size = 2, alignment = 1 // foo2: +-+-+
// members |a|b|
struct foo2 {
	char a;
	char b; 
};

// size = 8, alignment = 4
// foo3: +----+----+
// members: |a...|bbbb|
// . represents a byte of padding
struct foo3 {
	char a;	
	int b; 
};

// size = 24, alignment = 8
// foo4: +--------+--------+--------+--------+ 
// members: |aaaab...|cccc....|dddddddd|e.......| 
// . represents a byte of padding
struct foo4 {
	int a;
	char b;
	float c;
	double d;
	bool e;
};


struct foo4_
{
	int a; // 4 bytes
	char b; // 1 byte
	char _pad0[3]; // 3 bytes padding to put c on a 8-byte boundary 
	float c; // 4 bytes
	char _pad1[4]; // 4 bytes padding to put d on a 8-byte boundary 
	double d;  // 8 bytes
	bool e; // 1 byte
	char _pad2[7]; // 7 bytes padding to make sizeof struct multiple of 8
};

/**
 * @brief Alignas expression as a type-id, or a parameter pack.
 */
int main() {
	example1();
}