#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

// Function to send a network message to the game
void sendNetworkMessage(const string& message) {
    // Send the request to the game's network handler
    Game.Network.SendNetworkMessage(message.c_str(), message.size());
}

// Function to set the player's rank
void setPlayerRank(int rank) {
    // Check that the rank is within the valid range (1-8000)
    if (rank < 1 || rank > 8000) {
        cerr << "Error: invalid rank value" << endl;
        return;
    }

    // Format the request to the game's network handler
    string request = "CmdPlayerRequestRankUpdate rank:" + to_string(rank);

    // Send the request to the game's network handler
    sendNetworkMessage(request);

    // Output a message to the console
    cout << "Rank set to " << rank << "." << endl;
}

int main() {
    // Set the desired rank (note: max rank is 8000)
    int rank = 8000;

    // Set the player's rank
    setPlayerRank(rank);

    return 0;
}