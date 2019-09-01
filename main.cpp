#include "classes/player/player.hpp"
#include "common/io_utilities/io_utilities.hpp"
#include "events/edit_player/edit_player.hpp"
#include "events/load_player/load_player.hpp"

int main()
{
	Player player;
	player = load_player(player.get_data_path());
	save_object(player, player.get_data_path());
}