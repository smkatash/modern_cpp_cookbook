#include <iostream>
#include <vector>
#include <map>
using namespace std;

vector<int>	getRates() {
	return vector<int> {1,2,3,4,5,6,7,8,9};
}

multimap<int, bool>	getRatesM() {
	return multimap<int, bool> {
		{11,true},
		{12,true},
		{13,true},
		{14,false},
		{15,true},
		{16,true},
		{17,true},
	};
}

void	example1() {
	auto rates = getRates();
	for (int rate : rates)
		cout << rate << " ";
	cout << endl;
	for (int& rate : rates)
		rate *= 2;
	for (int rate : rates)
		cout << rate << " ";
	cout << endl;
	cout << endl;
	for (auto& rate : getRates())
		cout << rate << " ";
	cout << endl;
	for (auto&& rate : rates)
		rate *= 2;
	for (auto const & rate : rates)
		cout << rate << " ";
	cout << endl;
	for (auto&& [rate, flag] : getRatesM())
		cout << rate << boolalpha << ": " << flag << " ";
	cout << endl;
}

template<typename T, size_t const Size>
class foo {
	T	data[Size] = {};

	public:
		T const& getAt(size_t const index) const {
			if (index < Size) 
				return data[index];
			else
			throw out_of_range("index out of range");
		}

		void	setAt(size_t const index, T const& val) {
			if (index < Size)
				data[index] = val;
			else
				throw out_of_range("index out of range");
		}
		size_t	getSize() const { return Size; }
};

template<typename T, typename C, size_t const Size>
class biterator {
	size_t	index;
	C&	collection;
	public:
		biterator(C& collection, size_t const index): index(index), collection(collection) {}

		bool operator != (biterator const& other) const { return index != other.index; }
		T const& operator*() const { return collection.getAt(index); }
		biterator& operator++() { ++index; return *this; }
		biterator operator++(int) {
			auto temp = *this;
			++(*temp);
			return temp;
		}
};

template<typename T, size_t const Size>
using foo_iterator = biterator<T, foo<T, Size>, Size>;

template<typename T, size_t const Size>
using foo_const_iterator = biterator<T, foo<T, Size> const, Size>;

template<typename T, size_t const Size>
inline foo_iterator<T, Size> begin(foo<T, Size>& collection) { return foo_iterator<T, Size>(collection, 0); }

template<typename T, size_t const Size>
inline foo_iterator<T, Size> end(foo<T, Size>& collection) {
	return foo_iterator<T, Size>(collection, collection.getSize());
}

template<typename T, size_t const Size>
inline foo_const_iterator<T, Size> begin(foo<T, Size> const& collection) {
	return foo_const_iterator<T, Size>(collection, 0);
}

template<typename T, size_t const Size>
inline foo_const_iterator<T, Size> end(foo<T, Size> const& collection) {
	return foo_const_iterator<T, Size>(collection, collection.getSize());
}

template<typename T, const size_t Size>
void	print_foo(foo<T, Size> const& arr) {
	for (auto&& e : arr) {
		cout << e << " ";
	}
	cout << endl;
}

void	example2() {
	foo<int, 5>	arr;

	arr.setAt(0, 19);
	arr.setAt(1, 28);
	arr.setAt(2, 37);
	arr.setAt(3, 45);
	arr.setAt(4, 45);

	// for (auto&& e: arr) // error
	// 	cout << e << " ";
	print_foo(arr);

}

int main() {
	example1();
	example2();
}

