#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>
#include <vector>
#include <optional>

class HashTable
{
private:
    struct HashEntry
    {
        int key;
        int value;
        bool deleted;

        HashEntry(int k, int v) : key(k), value(v), deleted(false) {}
    };

    std::vector<std::optional<HashEntry>> table;
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
        std::vector<std::optional<HashEntry>> new_table(capacity);

        for (const auto &entry : table)
        {
            if (entry && !entry->deleted)
            {
                int index = hash(entry->key);
                int i = 0;
                while (new_table[(index + i * i) % capacity])
                {
                    i++;
                }
                new_table[(index + i * i) % capacity] = *entry;
            }
        }
        table = std::move(new_table);
    }

public:
    HashTable(int initial_capacity = 8) : capacity(initial_capacity), size(0), table(initial_capacity) {}

    void insert(int key)
    {
        if (float(size) / capacity >= 0.8)
        {
            resize();
        }

        int index = hash(key);
        int i = 0;
        while (table[(index + i * i) % capacity] && !table[(index + i * i) % capacity]->deleted)
        {
            if (table[(index + i * i) % capacity]->key == key)
            {
                table[(index + i * i) % capacity]->value = key;
                return;
            }
            i++;
        }
        table[(index + i * i) % capacity] = HashEntry(key, key);
        size++;
    }

    std::optional<int> search(int key)
    {
        int index = hash(key);
        int i = 0;
        while (table[(index + i * i) % capacity])
        {
            if (table[(index + i * i) % capacity]->key == key && !table[(index + i * i) % capacity]->deleted)
            {
                return table[(index + i * i) % capacity]->value;
            }
            i++;
        }
        return {};
    }

    bool remove(int key)
    {
        int index = hash(key);
        int i = 0;
        while (table[(index + i * i) % capacity])
        {
            if (table[(index + i * i) % capacity]->key == key && !table[(index + i * i) % capacity]->deleted)
            {
                table[(index + i * i) % capacity]->deleted = true;
                size--;
                return true;
            }
            i++;
        }
        return false;
    }

    void printTable()
    {
        std::cout << "HashTable:\n";
        for (int i = 0; i < capacity; i++)
        {
            if (table[i] && !table[i]->deleted)
            {
                std::cout << "[" << i << "]: " << table[i]->key << std::endl;
            }
            else
            {
                std::cout << "[" << i << "]: empty\n";
            }
        }
        std::cout << std::endl;
    }
};

#endif
