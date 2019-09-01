#ifndef LOAD_PLAYER
#define LOAD_PLAYER
#include "../../classes/player/player.hpp"
#include "../create_player/create_player.hpp"
#include "../edit_player/edit_player.hpp"
#include "../../common/io_utilities/io_utilities.hpp"
#include "../../classes/player/player.hpp"


void display_player_saves(vector<string> &player_saves)
{
	clear_screen();
	print_item("Choose Save File Or Create New Player", "", "\n");
	for (int i = 0; i < player_saves.size(); i++)
	{
		int selection_number = i + 1;
		print_item(selection_number, "", ". ");
		print_item(player_saves[i], "", "\n");
	}
	print_item(player_saves.size() + 1, "", ". New Game\n");
}

Player load_player(string path = "./data/")
{
	Player player;
	string file_name;
	int user_selection;
	file_name = path;
	vector<string> player_saves = get_files_of_type(".dat", file_name);
	if (player_saves.size() <= 0)
		return create_player();

	display_player_saves(player_saves);
	user_selection = get_menu_selection();

	if (user_selection < 1 || user_selection > player_saves.size() )
		return create_player();

	file_name.append(player_saves[user_selection - 1]);
	load_object(player, file_name);
	return player;
}

#endif // LOAD_PLAYER