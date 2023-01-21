# include <iostream>


void	example1() {
	auto i = 42; //int
	auto d = 42.5; // double
	auto s = "text"; // char const*
	auto v = {1, 2, 3} // std::initializer_list<int>
}

void example2() {
	// auto name = type-id{explression}
	auto b = new char[10]{0}; // char *
	auto s1 = std::string["text"] //std::string
	
}

int main() {
	example1();


}
