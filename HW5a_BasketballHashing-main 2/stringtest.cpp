#include "hashable.h"
#include <iostream>
using namespace std;

int main(){
    HashableString hw("Computers rock");
    size_t hashHW = hw.getHash();
    cout << hashHW << endl; 
    return 0;
}
