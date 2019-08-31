#include <iostream>
#include <sstream>
using namespace std;

template <class T>
void print_item(
		T item,
		string leading = "",
		string trailing = "",
		ostream &os = cout)
{
	os << leading << item << trailing;
}