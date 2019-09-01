#include "../../common/io_utilities/io_utilities.hpp"
#include "edit_player.hpp"

void it_returns_zero_when_menu_selection_not_int(void);
void it_prompts_based_on_selection(void);
void it_handles_default_prompt_based_on_selection(void);
void it_returns_user_input_after_prompt(void);
void it_sets_player_attribute(void);
void it_allows_you_to_edit_player(void);
int total = 0;
int passed = 0;

int main()
{
	it_returns_zero_when_menu_selection_not_int();
	it_prompts_based_on_selection();
	it_handles_default_prompt_based_on_selection();
	it_returns_user_input_after_prompt();
	it_sets_player_attribute();
	// it_allows_you_to_edit_player();
	cout << "edit_player: passes " << passed << "/" << total << " tests\n";
}

void it_returns_zero_when_menu_selection_not_int(void)
{
	total++;
	int selection;
	istringstream i_stream("asdf;lkj");
	ostringstream o_stream;
	selection = get_menu_selection(o_stream, i_stream);
	assert(selection == 0);
	passed++;
}

void it_prompts_based_on_selection(void)
{
	total++;
	ostringstream o_stream;
	istringstream i_stream("Test");
	prompt_based_on_selection(1, o_stream, i_stream);
	assert(o_stream.str() == "Enter New Name: ");
	o_stream.str("");
	i_stream.str("Test");
	prompt_based_on_selection(2, o_stream, i_stream);
	assert(o_stream.str() == "Enter New Age: ");
	passed++;
}

void it_handles_default_prompt_based_on_selection(void)
{
	total++;
	ostringstream o_stream;
	istringstream i_stream("Test");
	prompt_based_on_selection(0, o_stream, i_stream);
	assert(o_stream.str() == "--Invalid Selection--\n");
	passed++;
}

void it_returns_user_input_after_prompt(void)
{
	total++;
	ostringstream o_stream;
	istringstream i_stream("Test_Attribute");
	string selection = prompt_based_on_selection(1, o_stream, i_stream);
	assert(selection == "Test_Attribute");
	passed++;
}

void it_sets_player_attribute(void)
{
	total++;
	Player player;
	string new_attribute = "Test Name";
	int selection = 1;
	set_player_attribute(player, selection, new_attribute);
	assert(player.get_name() == new_attribute);
	passed++;
}

void it_allows_you_to_edit_player(void)
{
	Player player;
	edit_player(player);
}
