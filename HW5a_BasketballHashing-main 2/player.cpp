#include "player.h"

Player::Player(string name, string school, int height, int weight, int year) {
    this->name = name;
    this->school = school;
    this->height = height;
    this->weight = weight;
    this->year = year;
}
Cloneable* Player::clone() {
    return new Player(name, school, height, weight, year);
}
void Player::printPlayer() {
    cout << name << endl;
    cout << "Birth Year: " << year << endl;
    cout << "School: " << school << endl;
    cout << "Height: " << height << " cm" << endl;
    cout << "Weight: " << weight << " kg" << endl;
}

/**
 * Populate a map with all of the basketball players in the file 
 * "players.txt"
 * @param map A map to fill
 */
void loadPlayers(Map* map) {
    // TODO: Fill this in.  Load in each player and put
    // them in the map with a HashableString with their name
    // as the key and a player as their value.  Look at Person.cpp
    // for an example of how to put things into a map
    int count = 0;
    ifstream file("players.txt");
    if (file.is_open()) {
        string line;
        string name0;
        int weight1;
        int height2;
        string school3;
        int year4;
        bool isName = true;
        while(getline(file, line)) {
            if (isName){
                name0 = line;
                count++;
                isName = false;
            }
            else if (count == 1){
                weight1 = stoi(line);
                count++;
            }
            else if (count == 2){
                height2 = stoi(line);
                count++;
            }
            else if (count == 3){
                school3 = line;
                count++;
            }
            else if (count == 4){
                year4 = stoi(line);
                Player play(name0, school3, height2, weight1, year4);
                HashableString key(name0);
                map->put(&key, &play);
                count = 0;
                isName = true;
            }
        }
    }
}
