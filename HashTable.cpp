#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>
#include <vector>

class HashTable
{
private:
    struct HashEntry
    {
        int key;
        bool deleted;

        HashEntry(int k) : key(k), deleted(false) {}
    };

    std::vector<HashEntry *> table; // Use pointers to handle empty entries
    int capacity;
    int size;

    int hash(int key)
    {
        return key % capacity;
    }

public:
    HashTable(int initial_capacity = 8) : capacity(initial_capacity), size(0), table(initial_capacity, nullptr) {}

    ~HashTable()
    {
        for (auto entry : table)
        {
            delete entry; // Clean up dynamically allocated memory
        }
    }

    void insert(int key)
    {
        int index = hash(key);
        int i = 0;
        while (table[(index + i) % capacity])
        {
            if (table[(index + i) % capacity]->key == key)
            {
                table[(index + i) % capacity]->deleted = false; // Restore if it was deleted
                return;
            }
            i++;
        }

        table[(index + i) % capacity] = new HashEntry(key); // Insert new entry
        size++;
    }

    int search(int key)
    {
        int index = hash(key);
        int i = 0;
        while (table[(index + i) % capacity])
        {
            if (table[(index + i) % capacity]->key == key && !table[(index + i) % capacity]->deleted)
            {
                return (index + i) % capacity; // Return the index
            }
            i++;
        }
        return -1; // Return -1 if not found
    }

    bool remove(int key)
    {
        int index = hash(key);
        int i = 0;
        while (table[(index + i) % capacity])
        {
            if (table[(index + i) % capacity]->key == key && !table[(index + i) % capacity]->deleted)
            {
                table[(index + i) % capacity]->deleted = true;
                size--;
                return true;
            }
            i++;
        }
        return false;
    }

    void printTable()
    {
        for (int i = 0; i < capacity; i++)
        {
            if (table[i] && !table[i]->deleted)
            {
                std::cout << table[i]->key << " ";
            }
            else
            {
                std::cout << "- ";
            }
        }
        std::cout << std::endl;
    }
};

#endif
