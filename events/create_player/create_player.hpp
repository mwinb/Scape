#ifndef CREATE_PLAYER
#define CREATE_PLAYER
#include "../../classes/player/player.hpp"
#include "../edit_player/edit_player.hpp"
#include "../../common/io_utilities/io_utilities.hpp"

Player create_player(void)
{
	Player player;
	print_item("New PLayer", "", "\n");
	edit_player(player);
	save_object(player, player.get_data_path());
	return player;
}

#endif // CREATE_PLAYER