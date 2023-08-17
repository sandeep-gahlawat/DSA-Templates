#include <iostream>
#include <vector>
#include <list>

using namespace std;
// In this implementation, we use an array of linked lists to handle collisions. Each element in the array is a list that contains key-value pairs. The hash function determines the index in the array where the key-value pair should be stored. If there are multiple key-value pairs with the same hash, they are stored in the same list (separate chaining). The hashmap supports insert, get, and remove operations for key-value pairs.
class HashMap {
private:
    static const int SIZE = 100; // Size of the hashmap array

    vector<list<pair<int, int>>> table; // Hashmap array of lists (for separate chaining)

    // Hash function to map the key to an index in the array
    int hash(int key) {
        return key % SIZE;
    }

public:
    HashMap() {
        // Initialize the hashmap array with empty lists
        table.resize(SIZE);
    }

    // Insert a key-value pair into the hashmap
    void insert(int key, int value) {
        int index = hash(key);
        for ( auto& kv : table[index]) {
            if (kv.first == key) {
                // Update the value if the key already exists
                kv.second = value;
                return;
            }
        }
        // If the key doesn't exist, add it to the list
        table[index].push_back(make_pair(key, value));
    }

    // Get the value associated with a given key
    int get(int key) {
        int index = hash(key);
        for (const auto& kv : table[index]) {
            if (kv.first == key) {
                return kv.second; // Return the value if the key is found
            }
        }
        return -1; // Return -1 if the key is not found
    }

    // Remove a key-value pair from the hashmap
    void remove(int key) {
        int index = hash(key);
        for (auto it = table[index].begin(); it != table[index].end(); it++) {
            if (it->first == key) {
                table[index].erase(it); // Remove the key-value pair if the key is found
                return;
            }
        }
    }
};

int main() {
    HashMap myMap;

    myMap.insert(1, 10);
    myMap.insert(2, 20);
    myMap.insert(3, 30);

    cout << "Value for key 2: " << myMap.get(2) << endl; // Output: 20

    myMap.remove(2);
    cout << "Value for key 2 after removal: " << myMap.get(2) << endl; // Output: -1 (not found)

    return 0;
}
