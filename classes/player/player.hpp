#ifndef PLAYER
#define PLAYER

#include <iostream>
using namespace std;

#define PLAYER_DATA_PATH "./data/player/"

class Player
{
	string name;
	string race;
	string gender;
	string age;
	string data_path;

public:
	Player(
			string new_name = "unknown",
			string new_age = "unknown",
			string new_gender = "unknown",
			string new_race = "unknown")
	{
		name = new_name;
		race = new_race;
		gender = new_gender;
		age = new_age;
		data_path = PLAYER_DATA_PATH;
	}

	void set_name(string new_name)
	{
		if (new_name != "")
		{
			name = new_name;
		}
	}
	void set_race(string new_race)
	{
		if (new_race != "")
			race = new_race;
	}
	void set_gender(string new_gender)
	{
		if (new_gender != "")
			gender = new_gender;
	}
	void set_age(string new_age)
	{
		if (new_age != "")
			age = new_age;
	}

	void set_data_path(string new_data_path) { 
		if(new_data_path != "")
			data_path = new_data_path; 
	}

	string get_name(void) { return name; }
	string get_race(void) { return race; }
	string get_gender(void) { return gender; }
	string get_age(void) { return age; }
	string get_data_path(void) { return data_path; }

	friend ostream &operator<<(ostream &o_stream, const Player &player)
	{
		o_stream << player.name << "\n"
						 << player.race << "\n"
						 << player.age << "\n"
						 << player.gender << endl;
		return o_stream;
	}

	friend istream &operator>>(std::istream &i_stream, Player &player)
	{
		i_stream >> player.name;
		i_stream >> player.race;
		i_stream >> player.age;
		i_stream >> player.gender;
		return i_stream;
	}
};
#endif // PLAYER