#include <iostream>
#include <vector>
#include "global.h"
#include "player.h"

using namespace std;

std::vector<string> start_game() {
    string starter;

    std::vector<string> starter_stats;

    //bulbasaur, charmander, squirtle
    int bulbasaur = 1;
    int charmander = 4;
    int squirtle = 7;

    int pokedexnum = 0;
    cout << "Enter the pokedex number "
         << "of the pokemon to display details: ";
    cin >> pokedexnum;
    starter_stats = Player::get_pokemon(pokedexnum);

    starter = starter_stats.front();

    for (string p: starter_stats)
        std::cout << p << "\n";

    return starter_stats;
}

int main() {
    std::vector<string> pokemon;

    pokemon = start_game();

    return 0;
}