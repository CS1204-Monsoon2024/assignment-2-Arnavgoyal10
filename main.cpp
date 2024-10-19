#include "HashTable.cpp"

int main()
{
    int initialSize = 7;
    HashTable ht(initialSize);

    // Example test case
    ht.insertElement(1);
    ht.displayTable();
    ht.insertElement(6);
    ht.displayTable();
    ht.insertElement(15);
    ht.displayTable();
    ht.insertElement(25);
    ht.displayTable();
    ht.removeElement(15);
    ht.displayTable();
    ht.insertElement(29);
    ht.displayTable();

    int find = ht.searchElement(22);
    if (find != -1)
        std::cout << "Found at: " << find << std::endl;
    else
        std::cout << "Element not found" << std::endl;

    return 0;
}
