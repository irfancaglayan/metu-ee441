#include "assignment_1.h"
#include <stdexcept>

int main() {
    float arr1[] = {1.0, 3.0, 4.0, 2.0, 5.0};   // order() function automatically sorts the array
    SortedList l1(arr1, 5);
    std::cout << "Initial list l1: ";
    l1.printArray(l1);

    // testing index() function
    try {
        float value = l1.index(2);
        std::cout << "Value at chosen index: " << value << std::endl;
    } catch (const std::out_of_range& e) {
        std::cout << e.what() << std::endl;
    }

    // throwing "out of range" error for index() function
    try {
        int indexToShow = 10;
        float value = l1.index(indexToShow);
        std::cout << "Value at index " << indexToShow << ": " << value << std::endl;
    } catch (const std::out_of_range& e) {
        std::cout << e.what() << std::endl;
    }

    // testing insert() function
    try {
        float numberToInsert = 3.5;
        size_t insertPosition = l1.insert(numberToInsert);
        std::cout << "Inserted " << numberToInsert << " at position: " << insertPosition << std::endl;
        std::cout << "List after insertion: ";
        l1.printArray(l1);
    } catch (const std::length_error& e) {
        std::cout << e.what() << std::endl;
    }

    // throwing "size exceeds the maximum" error
    float arr2[] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0, 11.0, 12.0, 13.0, 14.0, 15.0, 16.0, 17.0, 18.0, 19.0, 20.0};
    SortedList l2(arr2, 20);
    try {
        float numberToInsert = 3.5;
        size_t insertPosition = l2.insert(numberToInsert);
        std::cout << "Inserted " << numberToInsert << " at position: " << insertPosition << std::endl;
        std::cout << "List after insertion: ";
        l1.printArray(l2);
    } catch (const std::length_error& e) {
        std::cout << e.what() << std::endl;
    }

    // testing remove() function
    try {
        int indexToRemove = 5;
        float removed = l1.remove(indexToRemove);
        std::cout << "Removed value at index "<< indexToRemove << ": " << removed << std::endl;
        std::cout << "List after removal: ";
        l1.printArray(l1);
    } catch (const std::out_of_range& e) {
        std::cout << e.what() << std::endl;
    }

    // throwing "out of range" error for remove() function
    try {
        int indexToRemove = 10;
        float removed = l1.remove(indexToRemove);
        std::cout << "Removed value at index "<< indexToRemove << ": " << removed << std::endl;
        std::cout << "List after removal: ";
        l1.printArray(l1);
    } catch (const std::out_of_range& e) {
        std::cout << e.what() << std::endl;
    }

    // testing find() function
    try {
        float numberToFind = 3.5;
        size_t foundIndex = l1.find(numberToFind);
        std::cout << "Found " << numberToFind << " at index: " << foundIndex << std::endl;
    } catch (const std::domain_error& e) {
        std::cout << e.what() << std::endl;
    }

    // throwing "not found" error
    try {
        float numberToFind = 6.0;
        size_t notFoundIndex = l1.find(numberToFind);
        std::cout << "Found " << numberToFind << " at index: " << notFoundIndex << std::endl;
    } catch (const std::domain_error& e) {
        std::cout << e.what() << std::endl;
    }

    // testing copy() function
    SortedList l3;
    l3.copy(l1);
    std::cout << "Copied list l3 from l1: ";
    l3.printArray(l3);

    // throwing "empty list" error
    SortedList l4;
    l4.printArray(l4);

    return 0;
}