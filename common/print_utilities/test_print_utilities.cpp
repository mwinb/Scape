#include <iostream>
#include <sstream>
#include "print_utilities.cpp"
using namespace std;
int passed = 0;
int total = 0;

void it_prints_an_item(void);
void it_prints_with_leading_string(void);
void it_prints_with_trailing_string(void);

int main()
{
	it_prints_an_item();
	it_prints_with_leading_string();
	it_prints_with_trailing_string();
	cout << "print_utils: Passed " << passed << "/" << total << " tests\n";
}

void it_prints_an_item(void)
{
	total++;
	ostringstream stream;
	print_item("test", "", "", stream);
	assert(stream.str() == "test");
	passed++;
}

void it_prints_with_leading_string(void)
{
	total++;
	ostringstream stream;
	print_item(10, "Leading", "", stream);
	assert(stream && stream.str() == "Leading10");
	passed++;
}

void it_prints_with_trailing_string(void)
{
	total++;
	ostringstream stream;
	print_item(10.5, "", "\n", stream);
	assert(stream && stream.str() == "10.5\n");
	passed++;
}