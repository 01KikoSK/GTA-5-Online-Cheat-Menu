#include <iostream>

// Assuming you have access to the game's functions and objects
if (auto player = GetPlayer()) {
    if (player->WantedLevel > 0) {
        DecreaseWantedLevel(*player);
        std::cout << "Wanted level decreased to " << player->WantedLevel << std::endl;
    } else {
        std::cout << "No wanted level" << std::endl;
    }
} else {
    std::cout << "Error: Could not get player object" << std::endl;
}

// These functions and objects are assumed to be defined elsewhere
auto GetPlayer() -> Player* {
    // Implementation to get the player object
}

void DecreaseWantedLevel(Player& player) {
    // Implementation to decrease the player's wanted level
}