#include <iostream>
#include <grandtheftauto/api.h>

#define GTA_V_ONLINE

#ifdef GTA_V_ONLINE
GTA_V::game_initialization_data init_data = GTA_V::initialize_game();
#else
GTA_V::game_initialization_data init_data = GTA_V::initialize_game_standalone();
#endif

if (init_data == GTA_V::game_initialization_data())
{
    std::cout << "Error: Failed to initialize the game." << std::endl;
    return 1;
}

GTA_V::game_game game = GTA_V::game::start(init_data);

if (game == GTA_V::game_game())
{
    std::cout << "Error: Failed to start the game." << std::endl;
    return 1;
}

#ifdef GTA_V_ONLINE
const std::string game_name = "GTA Online";
#else
const std::string game_name = "GTA V Standalone";
#endif

std::cout << "Cheat Menu Running for " << game_name << "!" << std::endl;

while (game.is_running())
{
    if (GTA_V::is_key_pressed(GTA_V::keys::F4))
    {
        GTA_V::player player = GTA_V::player::player_id();
        GTA_V::player_ped player_ped = player.ped();
        player_ped.set_invincible(true);
    }

    if (GTA_V::is_key_pressed(GTA_V::keys::F5))
    {
        GTA_V::player player = GTA_V::player::player_id();
        GTA_V::player_character character = player.character();
        character.add_money(1000000);
    }

    GTA_V::wait(0);
}

cleanup:
GTA_V::game::shutdown();

std::cout << "Cheat Menu Shutdown!" << std::endl;

return 0;