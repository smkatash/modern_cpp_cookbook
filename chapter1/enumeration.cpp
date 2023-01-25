#include <iostream>
using namespace std;

/**
 * The enum class and enum struct declarations are equivalent
 */
enum class Status { Unknown, Created, Connected};

void	example1() {
	Status s = Status::Created;
	using Status::Unknown;
	Status s = Unknown;
}

struct foo
{
	enum class fStatus { Unknown, Created, Connected};
	fStatus s_;

	foo(fStatus s): s_(s) {}
	using enum fStatus;
	void	process(fStatus const s) {
		switch (s)
		{
		case Unknown:
			/* code */
			break;
		case Created:
			/* code */
			break;
		case Connected:
			/* code */
			break;
		default:
			break;
		}
	}
};

void	example2() {
	foo::fStatus fs = foo::Connected;
	foo f(fs);
	f.process(f.s_);
}

enum class Codes: unsigned int {
	OK = 0,
	Failure = 1,
	Unknown = 0xFFFF0000U
};

void	example3() {
	Codes c1 = Codes::OK;
	int	c2 = Codes::Failure; // error
	int c3 = static_cast<int>(Codes::Failure);
}


int main() {
	example1();
	example2();
	example3();
}