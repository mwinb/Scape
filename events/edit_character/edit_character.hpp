
#ifndef EDIT_CHARACTER
#define EDIT_CHARACTER
#include "../../classes/player/player.hpp"

enum attributes
{
	EDIT_NAME = 1,
	EDIT_AGE,
	EDIT_GENDER,
	EDIT_RACE,
	EDIT_EXIT
};

void print_menu(Player &player, ostream &o_stream = cout)
{
	clear_screen();
	print_item("Edit Character.", "", "\n", o_stream);
	print_item(player.get_name(), "1.Edit Name: ", "\n", o_stream);
	print_item(player.get_age(), "2.Edit Age: ", "\n", o_stream);
	print_item(player.get_gender(), "3.Edit Gender: ", "\n", o_stream);
	print_item(player.get_race(), "4.Edit Race: ", "\n", o_stream);
	print_item("5.Exit.", "", "\n", o_stream);
}

int get_menu_selection(ostream &o_stream = cout, istream &i_stream = cin)
{
	int selection;
	print_item("Enter Selection: ", "", "", o_stream);
	get_input(selection, i_stream);
	clear_input_stream(i_stream);
	return selection;
}

string prompt_based_on_selection(int selection, ostream &o_stream = cout, istream &i_stream = cin)
{
	string new_attribute;
	switch (selection)
	{
	case EDIT_NAME:
		print_item("Enter New Name: ", "", "", o_stream);
		break;
	case EDIT_AGE:
		print_item("Enter New Age: ", "", "", o_stream);
		break;
	case EDIT_GENDER:
		print_item("Enter New Gender: ", "", "", o_stream);
		break;
	case EDIT_RACE:
		print_item("Enter New Race: ", "", "", o_stream);
		break;
	case EDIT_EXIT:
		print_item("Finished Editing", "--", "\n", o_stream);
		return "";
		break;
	default:
		print_item("Invalid Selection", "--", "--\n", o_stream);
		return "";
		break;
	}
	get_line(new_attribute, i_stream);
	return new_attribute;
}

void set_player_attribute(Player &player, int selection, string new_attribute_string)
{
	switch (selection)
	{
	case EDIT_NAME:
		player.set_name(new_attribute_string);
		break;
	case EDIT_AGE:
		player.set_age(new_attribute_string);
		break;
	case EDIT_GENDER:
		player.set_gender(new_attribute_string);
		break;
	case EDIT_RACE:
		player.set_race(new_attribute_string);
		break;
	default:
		break;
	}
}

void edit_character(Player &player)
{
	int selection = 0;
	while (selection != EDIT_EXIT)
	{
		string new_attribute_string = "";
		print_menu(player);
		selection = get_menu_selection();
		new_attribute_string = prompt_based_on_selection(selection);
		if (new_attribute_string != "")
			set_player_attribute(player, selection, new_attribute_string);
		clear_screen();
	}
}

#endif // EDIT_CHARACTER
