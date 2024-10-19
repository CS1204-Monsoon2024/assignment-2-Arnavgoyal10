#include "HashTable.cpp"

int main()
{
    int initialSize = 16; // Set initial size to 16 as per the expected output
    HashTable ht(initialSize);

    // Insert elements and print the table after each insertion as per the expected output
    ht.insert(13);
    ht.printTable(); // Should match the first line in the expected output

    ht.insert(3);
    ht.printTable(); // Should match the second line in the expected output

    ht.insert(20);
    ht.printTable(); // Should match the third line

    ht.insert(4);
    ht.printTable(); // Fourth line

    ht.insert(21);
    ht.printTable(); // Fifth line

    int find = ht.search(22);                       // Search for a number that is not present
    std::cout << "Found at: " << find << std::endl; // Should return -1

    find = ht.search(21);                           // Search for a number that is present
    std::cout << "Found at: " << find << std::endl; // Should return 5

    return 0;
}
