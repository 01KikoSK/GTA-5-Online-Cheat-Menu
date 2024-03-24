#include <iostream>
#include <string>
#include <map>
#include <functional>

using namespace std;

// Dummy Game namespace
namespace Game
{
    struct Player
    {
        int WantedLevel = 0;
        int Money = 0;

        bool IsInAnyVehicle() { return true; }
    };

    struct Input
    {
        string GetInput() { return ""; }
    };

    void ConsoleOutput(string message) { cout << message << endl; }
}

int main()
{
    // Set up the admin commands
    map<string, function<void()>> commands =
    {
        { "setrank", [] {
            // Set the player's rank
            if (Game::Player.IsInAnyVehicle())
            {
                int rank = 0;

                // Parse rank from input
                if (cin >> rank)
                {
                    Game::Player.WantedLevel = rank;
                    Game::ConsoleOutput("Rank set to " + to_string(rank) + ".");
                }
                else
                {
                    Game::ConsoleOutput("Invalid rank value.");
                }

                // Clear input buffer
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }},
        { "givemoney", [] {
            // Give the player money
            if (Game::Player.IsInAnyVehicle())
            {
                int amount = 0;

                // Parse amount from input
                if (cin >> amount)
                {
                    Game::Player.Money = amount;
                    Game::ConsoleOutput("Money set to " + to_string(amount) + ".");
                }
                else
                {
                    Game::ConsoleOutput("Invalid money value.");
                }

                // Clear input buffer
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }},
    };

    // Loop forever
    while (true)
    {
        // Get the user's input
        string input = "";
        cout << "> ";
        getline(cin, input);

        // Check if the input is an admin command
        if (commands.count(input) > 0)
        {
            // Execute the command
            commands[input]();
        }
    }
}