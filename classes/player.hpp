#include <iostream>
using namespace std;

class Player 
{
	string name;
	string race;
	string gender;
	string age;

	public:
		Player(
			string new_name = "unknown", 
			string new_race = "unknown", 
			string new_gender = "unknown", 
			string new_age = "unknown")
		{
			name = new_name;
			race = new_race;
			gender = new_gender;
			age = new_age;
		}
		string get_name(void) { return name; }
		string get_race(void) { return race; }
		string get_gender(void) { return gender; }
		string get_age(void) { return age; }
};