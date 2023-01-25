#include <iostream>
using namespace std;
/**
 * Always use the override special identifier after 
 * the declarator part of a virtual function's declaration 
 * or definition:
 */
class Base {
	protected:
		string			name_;
		const string	defname_ = "Base";
	public:
		Base() {}
		Base(string name): name_(name) {
			cout << defname_ << ": Creating " << name_ << endl;
		}
		virtual void foo() = 0;
		virtual	void bar(){
			cout << defname_ << ": This is bar" << endl;
		}
		virtual void foobar() = 0;
};

void Base::foobar(){}

class Derived1: public Base {
	protected:
		string	defname_;
		const	string		myname_ = "Derived1";
	public:
		Derived1(): Base("Derived1") {
			cout << myname_ << " is created." << endl;
		}
		Derived1(string name): Base(name), defname_(name) {
			cout << myname_ << ": Creating " << defname_<< endl;
		}

		virtual void foo() override = 0;
		virtual void bar() override {
			cout << myname_ << ": This is bar" << endl;
		}
		virtual void foobar() final {
			cout << myname_ << ": This is foobar" << endl;
		}
};

class Derived2: public Derived1 {
	 // virtual void foo() override {}
	// Eliminate further function overriding
	protected:
		string	defname_;
		const	string		myname_ = "Derived2";
	public:
		Derived2(): Derived1("Derived2") {
			cout << myname_ << " is created." << endl;
		}
		Derived2(string name): Derived1(name), defname_(name) {
			cout << myname_ << ": Creating " << defname_<< endl;
		}
		virtual void foo() final {
			cout << myname_ << ": This is foo" << endl;
		}
};

// Eliminate further class derivations
class Derived3 final : public Derived2 {
	protected:
		const	string		myname_ = "Derived3";
	public:
		Derived3(): Derived2("Derived3") {
			cout << myname_ << " is created." << endl;
		}
		virtual void bar() final {
			cout << myname_ << ": This is bar" << endl;
		}
};

int main() {
	Derived2	d2;

	d2.bar();
	d2.foo();
	d2.foobar();
	cout << endl;
	cout << endl;

	Derived3	d3;
	d3.bar();
	d3.foo();
	d3.foobar();
}