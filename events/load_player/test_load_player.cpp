#include "load_player.hpp"
#include "../../common/io_utilities/io_utilities.hpp"
#include "../../classes/player/player.hpp"

int main()
{
	Player player;
	player = load_player("./");
	assert(player.get_name() == "test_name");
}