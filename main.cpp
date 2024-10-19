#include "HashTable.cpp"

int main()
{
    int initialSize = 7;
    HashTable ht(initialSize);

    // Example test case
    ht.insert(1);
    ht.printTable();
    ht.insert(6);
    ht.printTable();
    ht.insert(15);
    ht.printTable();
    ht.insert(25);
    ht.printTable();
    ht.remove(15);
    ht.printTable();
    ht.insert(29);
    ht.printTable();

    auto find = ht.search(22);
    if (find.has_value())
    {
        std::cout << "Found value: " << find.value() << std::endl;
    }
    else
    {
        std::cout << "Key 22 not found." << std::endl;
    }

    return 0;
}
