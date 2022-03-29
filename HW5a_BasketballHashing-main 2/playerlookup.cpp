#include "player.h"

int main(int argc, char** argv) {
    Map* m = new HashTable(100);
    loadPlayers(m);
    // TODO: Fill this in.  Query m for a player corresponding
    // to the passed in arguments, and print out their informatio
    string firstName = argv[1];
    string lastName = argv[2];
    string fullName = firstName + " " + lastName;
    HashableString playerKey(fullName);
    if (m->containsKey(&playerKey)){
        Player* play ((Player*)m->get(&playerKey));
        play->printPlayer();
    } else {
        cout << "not found";
    }
    delete m;
    return 0;
}

