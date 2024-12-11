#include "assignment_1.h"
#include <stdexcept>

void SortedList::order(){
    for (size_t i = 0; i < size; i++){
        for (size_t j = i + 1; j < size; j++){
            if (arr[i] > arr[j]){
                float temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void SortedList::copy(const SortedList& other){
    if (this == &other) {
        return; // self-assignment check
    }

    if (other.size > SORTEDLIST_MAX_SIZE){
        throw std::out_of_range("Size exceeds the maximum.");   // error for size incompatiblity
    }

    size = other.size;
    for (size_t i = 0; i < size; i++){
        arr[i] = other.arr[i];  // the copying function
    }
}

void SortedList::printArray(const SortedList& list){
    if (list.size == 0){
        std::cout << "The list is empty." << std::endl;
    } else {
        for (size_t i = 0; i < list.size; i++){
            std::cout << list.arr[i] << " ";    // printing the array with spaces
        }
        std::cout << std::endl;
    }
}

float SortedList::index(size_t ind){
    if (ind < 0 || ind >= size){
        throw std::out_of_range("Index out of range.");
    }
    else{
        return arr[ind];    // returning the value at the index
    }
}

size_t SortedList::insert(float number){
    if (size >= SORTEDLIST_MAX_SIZE){
        throw std::length_error("Size exceeds the maximum.");   // upper bound before insertion
    }
    
    size_t pos = 0;
    while (pos < size && arr[pos] < number){    // finding the position to insert
        pos++;
    }

    for (size_t i = size; i > pos; i--){
        arr[i] = arr[i - 1];    // shifting the elements to the right to make space
    }

    arr[pos] = number;  // inserting the number
    size++; // updating the size

    return pos;
}

float SortedList::remove(size_t index){
    if (index < 0 || index >= size){
        throw std::out_of_range("Index out of range."); // invalid index check
    }
    else {
        float temp = arr[index];    // storing the removed value
        for (size_t i=size; i>index; i--){
            arr[i-1] = arr[i];  // shifting the elements to the left after removal
        }
        size--; // updating the size
        return temp;
    }
}

size_t SortedList::find(float number){  // binary search function similar to the implementation in lecture notes
    int mid;    // mid index
    float midvalue; // value at mid index
    int low = 0;    // initializing a lower bound
    int high = size - 1;    // initializing an upper bound
    while(low <= high){
        mid = (low + high) / 2; // finding the mid index
        midvalue = arr[mid];    // finding the value at mid index
        if (number == midvalue){
            return mid;
        }
        else if (number < midvalue){
            high = mid - 1; // updating the upper bound if not found
        }
        else{
            low = mid + 1;  // updating the lower bound if not found
        }
    }
    throw std::domain_error("Value not found.");
}