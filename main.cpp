#include "HashTable.cpp"

int main()
{
    int initialSize = 16; // Use the initial size as given in the expected output
    HashTable ht(initialSize);

    // Example test case as per the expected output
    ht.insert(13);
    ht.printTable(); // Should match first row in expected output

    ht.insert(3);
    ht.printTable(); // Second row

    ht.insert(20);
    ht.printTable(); // Third row

    ht.insert(4);
    ht.printTable(); // Fourth row

    ht.insert(21);
    ht.printTable(); // Fifth row

    int find = ht.search(22);                       // Search for a number not present in the table
    std::cout << "Found at: " << find << std::endl; // Should print -1

    find = ht.search(21);                           // Search for a number that is present
    std::cout << "Found at: " << find << std::endl; // Should print the index of 21 (which is 5)

    return 0;
}
