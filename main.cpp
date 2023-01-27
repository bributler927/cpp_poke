#include <iostream>
#include <vector>
#include <typeinfo>
#include <fstream>
#include <sstream>
#include "global.h"

using namespace std;

std::vector<string> get_pokemon(int pokedexnum) {
    // File pointer
    std::ifstream pokefile("pokemon.csv");

    std::vector<string> stats;

    //pokedex # is 33 I think
    // Open the file
    if(!pokefile.is_open()) throw std::runtime_error("Could not open file");

    // Get the pokedex number
    // of which the data is required
    int pokedex2, count = 0;

    // Read the Data from the file
    // as String Vector
    vector<string> row;
    string line, word, tmp;

    while (getline(pokefile, line)) {

        row.clear();

        // used for breaking words
        stringstream s(line);

        // read every column data of a row and
        // store it in a string variable, 'word'
        while (getline(s, word, ',')) {
            cout << word;
            // add all the column data
            // of a row to a vector
            row.push_back(word);           

        }
        cout << row.size();
        // check that you've got a valid record
            if(row.size() < 40)
                throw std::runtime_error("invalid record size (" +
                                         std::to_string(row.size()) + ")");

        // convert string to integer for comparision
        pokedex2 = stoi(row[32]);
  
        // Compare the roll number
        if (pokedex2 == pokedexnum) {

            // add pokemon stats to vector
            count = 1;
            stats.push_back(row[32]);

            string chosen_name = row[30];
            stats.push_back(chosen_name);

            string chosen_type1 = row[36];
            stats.push_back(chosen_type1);

            string chosen_type2 = row[37];
            stats.push_back(chosen_type2);

            string chosen_hp = row[28];
            stats.push_back(chosen_hp);

            break;
        }

    }
    
    if (count == 0)
        cout << "Record not found\n";

    return stats;
}

std::vector<string> start_game() {
    string starter;

    std::vector<string> starter_stats;

    //bulbasaur, charmander, squirtle
    int bulbasaur = 1;
    int charmander = 4;
    int squirtle = 7;

    int pokedexnum;
    cout << "Enter the pokedex number of the pokemon to display details: ";
    cin >> pokedexnum;

    starter_stats = get_pokemon(pokedexnum);

    starter = starter_stats.front();

    for (string p: starter_stats)
        cout << p << "\n";

    return starter_stats;
}

int main() {
    std::vector<string> pokemon;

    pokemon = start_game();

    return 0;
}