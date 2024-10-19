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

    std::vector<HashEntry *> table;
    int capacity;
    int size;

    int hash(int key)
    {
        return key % capacity;
    }

    void resize()
    {
        int old_capacity = capacity;
        capacity *= 2;
        std::vector<HashEntry *> new_table(capacity, nullptr);

        for (const auto &entry : table)
        {
            if (entry && !entry->deleted)
            {
                int index = hash(entry->key);
                int i = 0;
                while (new_table[(index + i) % capacity])
                {
                    i++;
                }
                new_table[(index + i) % capacity] = entry;
            }
        }
        table = std::move(new_table);
    }

public:
    HashTable(int initial_capacity = 8) : capacity(initial_capacity), size(0), table(initial_capacity, nullptr) {}

    ~HashTable()
    {
        for (auto entry : table)
        {
            delete entry;
        }
    }

    void insert(int key)
    {
        if (float(size) / capacity >= 0.8)
        {
            resize();
        }

        int index = hash(key);
        int i = 0;
        while (table[(index + i) % capacity])
        {
            if (table[(index + i) % capacity]->key == key)
            {
                table[(index + i) % capacity]->deleted = false;
                return;
            }
            i++;
        }

        table[(index + i) % capacity] = new HashEntry(key);
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
                return (index + i) % capacity; // Return the index where the key is found
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
