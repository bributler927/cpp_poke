#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

#include "global.h"
#include "player.h"

using namespace std;

std::vector<string> Player::get_pokemon(int pokedexnum) {
    // File pointer
    fstream pokefile;

    std::vector<string> stats;

    //pokedex # is 33 I think
    // Open the file
    pokefile.open("pokemon.csv", ios::in);

    // Get the pokedex number
    // of which the data is required
    int pokedex2, count = 0;

    // Read the Data from the file
    // as String Vector
    vector<string> row;
    string line, word, tmp;

    int size;
    while (getline(pokefile, line)) {
        row.clear();

        // read an entire row and
        // store it in a string variable 'line'
        // getline(pokefile, line);
  
        // used for breaking words
        stringstream s(line);

        // read every column data of a row and
        // store it in a string variable, 'word'
        while (getline(s, word, ',')) {
  
            // add all the column data
            // of a row to a vector
            row.push_back(word);

        }
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

    // Close the file
    pokefile.close();

    return stats;
}