#include <iostream>
#include <list>
#include <vector>
using namespace std;
class HashTable {
private:
    int size;
    vector<list<int>> table;
    int hashFunction(int key) {
        return key % size;
}
public:
    HashTable(int tableSize) {
        size = tableSize;
        table.resize(size);
}
void insert(int key) {
        int index = hashFunction(key);
        table[index].push_back(key);
        cout << "Chen khoa " << key << " vao vi tri " << index << endl;
}
void display() {
        for (int i = 0; i < size; i++) {
            cout << i << ": ";
            for (auto it = table[i].begin(); it != table[i].end(); it++) {
                cout << *it;
                auto next = it;
                next++;
                if (next != table[i].end()) {
                    cout << " -> ";
                }
            }
            cout << endl;
        }
    }
};

int main() {
    HashTable ht(9);
    
    int keys[] = {5, 28, 19, 15, 20, 33, 12, 17, 10};
    int n = sizeof(keys) / sizeof(keys[0]);
    
    for (int i = 0; i < n; i++) {
        ht.insert(keys[i]);
    }
    
    cout << "\nBang bam sau khi chen cac khoa:" << endl;
    ht.display();
    
    return 0;
}
