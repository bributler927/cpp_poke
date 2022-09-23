#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

int main() {
    // File pointer
    fstream pokefile;

    //pokedex # is 33 I think
    // Open the file
    pokefile.open("pokemon.csv", ios::in);

    // Get the pokedex number
    // of which the data is required
    int pokedexnum, pokedex2, count = 0;
    cout << "Enter the pokedex number "
         << "of the pokemon to display details: ";
    cin >> pokedexnum;

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
  
            // Print the found data
            count = 1;
            cout << "Pokedex #: " << row[32] << "\n";
            cout << "Name: " << row[30] << "\n";
            cout << "Type 1: " << row[36] << "\n";
            cout << "Type 2: " << row[37] << "\n";
            break;
        }

    }
    if (count == 0)
        cout << "Record not found\n";

    // Close the file
    pokefile.close();

    return 0;
}