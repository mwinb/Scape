#include <iostream>
#include <sstream>
#include "io_utilities.hpp"
#include "../../classes/player/player.hpp"

using namespace std;

int passed = 0;
int total = 0;

void it_prints_an_item(void);
void it_prints_with_leading_string(void);
void it_prints_with_trailing_string(void);
void it_reads_a_directory(void);
void it_saves_an_object_to_a_file(void);
void it_creates_an_object_from_a_dat_file(void);
void it_gets_files_of_specified_extension(void);

int main()
{
	it_prints_an_item();
	it_prints_with_leading_string();
	it_prints_with_trailing_string();
	it_reads_a_directory();
	it_saves_an_object_to_a_file();
	it_creates_an_object_from_a_dat_file();
	it_gets_files_of_specified_extension();
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

void it_reads_a_directory(void)
{
	total++;
	vector<std::string> test_files;
	read_directory("./", test_files);
	// for (int i = 0; i < test_files.size(); i++)
	// {
	// 	print_item(test_files[i], "", "\n");
	// }
	assert(test_files.size() > 0);
	passed++;
}

void it_saves_an_object_to_a_file(void)
{
	total++;
	string save_file;
	vector<string> files;
	Player player("test_name", "test_age", "test_gender", "test_race");
	save_object(player, "./");
	read_directory("./", files);
	for (int i = 0; i < files.size(); i++)
		if (files[i] == "test_name.dat")
			save_file = files[i];
	assert(save_file == "test_name.dat");
	passed++;
}

void it_creates_an_object_from_a_dat_file(void)
{
	total++;
	string save_file = "./test_name.dat";
	Player player;
	load_object(player, save_file);
	assert(player.get_name() == "test_name");
	assert(player.get_age() == "test_age");
	assert(player.get_gender() == "test_gender");
	assert(player.get_race() == "test_race");
	passed++;
}

void it_gets_files_of_specified_extension(void)
{
	total++;
	vector<string> dat_files = get_files_of_type(".dat", "./");
	print_item(dat_files[0], "", "\n");
	assert(dat_files.size() > 0);
	passed++;
}
