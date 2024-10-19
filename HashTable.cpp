#include <vector>
#include <cmath>
#include <iostream>

class HashTable
{
private:
    std::vector<int> hashTableArray;
    int tableCapacity;
    int totalElements;
    double loadFactorLimit;

    // Hash function
    int generateHash(int element)
    {
        return element % tableCapacity;
    }

    int findNextPrime(int number)
    {
        while (true)
        {
            bool primeCheck = true;
            for (int i = 2; i <= std::sqrt(number); i++)
            {
                if (number % i == 0)
                {
                    primeCheck = false;
                    break;
                }
            }
            if (primeCheck)
                return number;
            number++;
        }
    }

    void resizeTable()
    {
        int updatedCapacity = findNextPrime(tableCapacity * 2);
        std::vector<int> resizedArray(updatedCapacity, -1);

        for (int i = 0; i < tableCapacity; i++)
        {
            if (hashTableArray[i] != -1 && hashTableArray[i] != -2)
            { // -2 represents a deleted slot
                int element = hashTableArray[i];
                int newIndex = element % updatedCapacity;
                int probeCounter = 0;
                while (resizedArray[(newIndex + probeCounter * probeCounter) % updatedCapacity] != -1)
                {
                    probeCounter++;
                }
                resizedArray[(newIndex + probeCounter * probeCounter) % updatedCapacity] = element;
            }
        }
        hashTableArray = resizedArray;
        tableCapacity = updatedCapacity;
    }

public:
    HashTable(int initialCapacity = 5)
    {
        tableCapacity = findNextPrime(initialCapacity);
        hashTableArray = std::vector<int>(tableCapacity, -1);
        totalElements = 0;
        loadFactorLimit = 0.8;
    }

    // Insert an element
    void insertElement(int element)
    {
        if (totalElements >= loadFactorLimit * tableCapacity)
        {
            resizeTable();
        }
        int hashedIndex = generateHash(element);
        int probeCounter = 0;

        while (probeCounter < tableCapacity)
        {
            int calculatedIndex = (hashedIndex + (probeCounter * probeCounter)) % tableCapacity;
            if (hashTableArray[calculatedIndex] == element)
            {
                std::cout << "Duplicate key insertion is not allowed\n";
                return;
            }
            if (hashTableArray[calculatedIndex] == -1 || hashTableArray[calculatedIndex] == -2)
            {
                hashTableArray[calculatedIndex] = element;
                totalElements++;
                return;
            }
            probeCounter++;
        }
        std::cout << "Max probing limit reached!\n";
    }

    void removeElement(int element)
    {
        int hashedIndex = generateHash(element);
        int probeCounter = 0;

        while (probeCounter < tableCapacity)
        {
            int calculatedIndex = (hashedIndex + (probeCounter * probeCounter)) % tableCapacity;
            if (hashTableArray[calculatedIndex] == element)
            {
                hashTableArray[calculatedIndex] = -2;
                totalElements--;
                return;
            }
            else if (hashTableArray[calculatedIndex] == -1)
            {
                std::cout << "Element not found\n";
                return;
            }
            probeCounter++;
        }
        std::cout << "Element not found\n";
    }

    int searchElement(int element)
    {
        int hashedIndex = generateHash(element);
        int probeCounter = 0;

        while (probeCounter < tableCapacity)
        {
            int calculatedIndex = (hashedIndex + (probeCounter * probeCounter)) % tableCapacity;
            if (hashTableArray[calculatedIndex] == element)
            {
                return calculatedIndex;
            }
            else if (hashTableArray[calculatedIndex] == -1)
            {
                return -1;
            }
            probeCounter++;
        }
        return -1;
    }

    void displayTable()
    {
        for (int i = 0; i < tableCapacity; i++)
        {
            if (hashTableArray[i] == -1)
            {
                std::cout << "- ";
            }
            else if (hashTableArray[i] == -2)
            {
                std::cout << "- ";
            }
            else
            {
                std::cout << hashTableArray[i] << " ";
            }
        }
        std::cout << "\n";
    }
};
