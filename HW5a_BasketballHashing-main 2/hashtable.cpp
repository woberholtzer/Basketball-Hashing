#include "hashtable.h"

// TODO: Fill in your implementation of the Hash Table here

HashNode::HashNode(Hashable* key, Cloneable* value) {
    this->key = (Hashable*)key->clone();
    this->value = value->clone();
    next = nullptr;
}
HashNode::~HashNode(){
    delete key;
    delete value;
}
HashTable::HashTable(size_t NBins){
    this->NBins = NBins;
    table = new HashNode*[NBins];
    for (int i = 0; i < NBins; i++){
        table[i] = nullptr;
    }
}
HashTable::~HashTable(){
    delete(table);
}
size_t HashTable::getSize(){
    return (size_t)(sizeArray);
}
void HashTable::put(Hashable* key, Cloneable* value){
    size_t hashVal = (size_t)key->getHash();
    int bin = hashVal % NBins;
    if (table[bin] == nullptr){
        table[bin] = new HashNode(key, value);
    } else {
        HashNode* head = table[bin];
        HashNode* newNode = new HashNode(key, value);
        newNode->next = head;
        table[bin] = newNode;
    }
}
void HashTable::remove(Hashable* key){
    int bin = key->getHash() % NBins;
    numOps++;
    HashNode* head = table[bin];
    if (head->key == key){
        head = head->next;
        numOps++;
    } else {
        HashNode* last = head;
        HashNode* toDelete = head->next;
        while (toDelete != nullptr && toDelete->key != key){
            last = toDelete;
            toDelete = toDelete->next;
            numOps++;
        }
        if (toDelete != nullptr){
            last->next = toDelete->next;
            numOps++;
        }
    }
}
Cloneable* HashTable::get(Hashable* key){
    int bin = key->getHash() % NBins;
    numOps++;
    HashNode* head = table[bin];
    HashNode* current = head;
    Cloneable* toReturn = nullptr;
    bool valFound = false;
    while (current != nullptr && valFound == false){
        if (current->key->equals(key)){
            toReturn = current->value;
            valFound = true;
        } else {
            current = current->next;
            numOps++;
        }
    }
    return toReturn;
}
bool HashTable::containsKey(Hashable* key){
    bool keyFound = false;
    int bin = key->getHash() % NBins;
    HashNode* head = table[bin];
    HashNode* current = head;
    while (current != nullptr && !keyFound){
        if (current->key->equals(key)){
            keyFound = true;
        } else {
            current = current->next;
            numOps++;
        }
    }
    return keyFound;
}
Hashable** HashTable::getKeyList(size_t* N){
    sizeArray = 0;
    *N = 1;
    for (int i = 0; i < NBins; i++){
        HashNode* head = table[i];
        HashNode* current = head;
        while (current != nullptr){
            (*N)++;
            current = current->next;
            numOps++;
        }
    }
    Hashable** fullArray = new Hashable*[*N];
    int index = 0;
    for (int i = 0; i < NBins; i++){
        HashNode* head = table[i];
        HashNode* current = head;
        while (current != nullptr){
            fullArray[index] = current->key;
            current = current->next;
            index++;
        }
    }
    return fullArray;
}
