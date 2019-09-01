#include "classes/player/player.hpp"
#include "common/io_utilities/io_utilities.hpp"
#include "events/edit_character/edit_character.hpp"

int main()
{
	Player player;
	edit_character(player);
	save_object(player, player.get_data_path());
}