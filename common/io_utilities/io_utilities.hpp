#ifndef IO_UTILS
#define IO_UTILS

#include <iostream>
#include <sstream>
#include <iostream>
#include <fstream>
#include <vector>
#include <sys/types.h>
#include <dirent.h>

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

void get_line(string &item, istream &is = cin)
{
	getline(is, item);
}

template <class T>
void get_input(
		T &item,
		istream &is = cin)
{
	is >> item;
}

void clear_input_stream(istream &is = cin)
{
	is.clear();
	is.ignore();
}

void read_directory(const string &name, vector<std::string> &file_names)
{
	DIR *dirp = opendir(name.c_str());
	struct dirent *dp;
	while ((dp = readdir(dirp)) != NULL)
	{
		file_names.push_back(dp->d_name);
	}
	closedir(dirp);
}

vector<string> get_files_of_type(const string &extension, const string &path)
{
	vector<std::string> all_files;
	vector<string> requested_files;
	read_directory(path, all_files);
	for(int i = 0; i < all_files.size(); i++)
	{
		if(all_files[i].find(extension) != -1)
			requested_files.push_back(all_files[i]);
	}
	return requested_files;
}

void clear_screen()
{
	for (int i = 0; i < 100; i++)
		print_item('\n');
}

template <class T>
void save_object(T &ob_to_save, string path = "./data/")
{
	string full_path("");
	full_path.append(path).append(ob_to_save.get_name()).append(".dat");
	ofstream out(full_path);
	if (!out)
		print_item(full_path, "Invalid File path: ", "\n");
	else
		out << ob_to_save;
	out.close();
}

template <class T>
void load_object(T &ob_to_load, string path = "./data")
{
	ifstream in(path);
	if (!in)
		print_item(path, "Invalid File Path: ", "\n");
	else
		in >> ob_to_load;
	in.close();
}

#endif // IO_UTILS