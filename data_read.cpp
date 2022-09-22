#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

int main() 
{
    // File pointer
    fstream poke_file;

    // Open the file
    poke_file.open("pokemon.csv", ios::in);

    // Close the file
    poke_file.close();
  
}