#include <stdio.h>
#include <string>
#include <iostream>
#include <fstream>
#include "hashable.h"
#include "cloneable.h"
#include "hashtable.h"
#include "linkedmap.h"
#include "player.h"


void compareMaps() {
    // TODO: Fill this in
    // 1. Create a map m1 of type LinkedMap and a map m2 of type HashMap
    // and fill them with the players.
    LinkedMap* m1 = new LinkedMap();
    loadPlayers(m1);
    HashTable* m2 = new HashTable(100);
    loadPlayers(m2);
    // 2. Reset the operation counts of each map
    m1->numOps = 0;
    m2->numOps = 0;
    // 3. Loop through all of the keys in m1 and make sure they're in m2
    //    by calling the containsKey() method.  If they're not, print out
    //    the ones that are missing to help you debug
    size_t N;
    Hashable** arr(m2->getKeyList(&N));
    for (int i = 0; i < N-1; i++){
        if (!m1->containsKey(arr[i])){
            cout << arr[i] << endl;
        }
    }
    // 4. Loop through all of the keys in m2 and make sure they're in m1
    //    by calling the containsKey() method.  If they're not, print out
    //    the ones that are missing to help you debug
    Hashable** arr2(m1->getKeyList(&N));
    for (int i = 0; i < N-1; i++){
        if (!m2->containsKey(arr2[i])){
            cout << arr2[i] << endl;
        }
    }
    // 5. Report the number of operations in steps 3 and 4, and the average
    //    number of operations per player
    printf("%lu players\n", N+1);
    printf("Number of operations in HashTable: %zu\n", m2->numOps);
    printf("Average number of operations per player: %lu\n", m2->numOps/N);
    printf("Number of operations in LinkedMap: %zu\n", m1->numOps);
    printf("Average number of operations per player: %lu\n", m1->numOps/N);
    delete(m1);
    delete(m2);
}

int main() {
    compareMaps();
    return 0;
}
