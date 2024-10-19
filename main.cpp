#include "HashTable.cpp"

int main()
{
    int initialSize = 7;
    HashTable ht(initialSize);

    // Example test case
    ht.addKey(1);
    ht.displayTable();
    ht.addKey(6);
    ht.displayTable();
    ht.addKey(15);
    ht.displayTable();
    ht.addKey(25);
    ht.displayTable();
    ht.deleteKey(15);
    ht.displayTable();
    ht.addKey(29);
    ht.displayTable();

    int find = ht.findKey(22);
    std::cout << "Found at: " << find << std::endl;

    return 0;
}
