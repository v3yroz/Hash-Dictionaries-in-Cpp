#include <iostream>
#include <list>
#include <vector>

using namespace std;

class ChainedHashDictionary {
    list<int>* table;
    int size;

    int hash(int key) {
        return key % size;
    }
public:
    ChainedHashDictionary(int size) {
        table = new list<int>[size];
        this->size = size;
    }

    ~ChainedHashDictionary() {
        delete[] table;
    }

    void insert(int key) {
        int index = hash(key);
        for (auto it = table[index].begin(); it != table[index].end(); it++) {
            if (*it == key) {
                return;
            }
        }
        table[index].push_back(key);
    }

    bool find(int key) {
        int index = hash(key);
        for (auto it = table[index].begin(); it != table[index].end(); it++) {
            if (*it == key) {
                return true;
            }
        }
        return false;
    }

    void remove(int key) {
        int index = hash(key);
        for (auto it = table[index].begin(); it != table[index].end(); it++) {
            if (*it == key) {
                table[index].erase(it);
                return;
            }
        }
    }
};

class LinearHashDictionary {
    vector<int> table;
    int size;

    int hash(int key) {
        return key % size;
    }
public:
    LinearHashDictionary(int size) {
        table = vector<int>(size, -1);
        this->size = size;
    }

    void insert(int key) {
        int index = hash(key);
        while (table[index] != -1 && table[index] != key) {
            index = (index + 1) % size;
        }
        if (table[index] == key) {
            return;
        }
        table[index] = key;
    }

    bool find(int key) {
        int index = hash(key);
        while (table[index] != -1) {
            if (table[index] == key) {
                return true;
            }
            index = (index + 1) % size;
        }
        return false;
    }

    void remove(int key) {
        int index = hash(key);
        while (table[index] != -1) {
            if (table[index] == key) {
                table[index] = -1;
                return;
            }
            index = (index + 1) % size;
        }
    }
};
