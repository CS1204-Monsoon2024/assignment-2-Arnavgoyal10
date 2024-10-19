#include <vector>
#include <cmath>
#include <iostream>

class HashTable
{
private:
    std::vector<int> table;
    int size;
    int count;
    double loadFactorThreshold;

    int computeHash(int key)
    {
        return key % size;
    }

    int findNextPrime(int n)
    {
        while (true)
        {
            bool isPrime = true;
            for (int i = 2; i <= std::sqrt(n); i++)
            {
                if (n % i == 0)
                {
                    isPrime = false;
                    break;
                }
            }
            if (isPrime)
                return n;
            n++;
        }
    }

    void expandTable()
    {
        int newSize = findNextPrime(size * 2);
        std::vector<int> newTable(newSize, -1);

        for (int i = 0; i < size; i++)
        {
            if (table[i] != -1 && table[i] != -2)
            { // -2 represents a deleted slot
                int key = table[i];
                int index = key % newSize;
                int j = 0;
                while (newTable[(index + j * j) % newSize] != -1)
                {
                    j++;
                }
                newTable[(index + j * j) % newSize] = key;
            }
        }
        table = newTable;
        size = newSize;
    }

public:
    HashTable(int initSize = 5)
    {
        size = findNextPrime(initSize);
        table = std::vector<int>(size, -1); // -1 represents an empty slot
        count = 0;
        loadFactorThreshold = 0.8;
    }

    void addKey(int key)
    {
        if (count >= loadFactorThreshold * size)
        {
            expandTable();
        }
        int index = computeHash(key);
        int j = 0;

        while (j < size)
        {
            int probeIndex = (index + (j * j)) % size;
            if (table[probeIndex] == key)
            {
                std::cout << "Duplicate key insertion is not allowed\n";
                return;
            }
            if (table[probeIndex] == -1 || table[probeIndex] == -2)
            {
                table[probeIndex] = key;
                count++;
                return;
            }
            j++;
        }
        std::cout << "Max probing limit reached!\n";
    }

    void deleteKey(int key)
    {
        int index = computeHash(key);
        int j = 0;

        while (j < size)
        {
            int probeIndex = (index + (j * j)) % size;
            if (table[probeIndex] == key)
            {
                table[probeIndex] = -2;
                count--;
                return;
            }
            else if (table[probeIndex] == -1)
            {
                std::cout << "Element not found\n";
                return;
            }
            j++;
        }
        std::cout << "Element not found\n";
    }

    int findKey(int key)
    {
        int index = computeHash(key);
        int j = 0;

        while (j < size)
        {
            int probeIndex = (index + (j * j)) % size;
            if (table[probeIndex] == key)
            {
                return probeIndex;
            }
            else if (table[probeIndex] == -1)
            {
                return -1;
            }
            j++;
        }
        return -1;
    }

    void displayTable()
    {
        for (int i = 0; i < size; i++)
        {
            if (table[i] == -1)
            {
                std::cout << "- ";
            }
            else if (table[i] == -2)
            {
                std::cout << "- ";
            }
            else
            {
                std::cout << table[i] << " ";
            }
        }
        std::cout << "\n";
    }
};
