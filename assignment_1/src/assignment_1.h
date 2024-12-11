#pragma once
#include <iostream>
#include <stdio.h>
#include <cstddef>

#define SORTEDLIST_MAX_SIZE 20

class SortedList{
private:
    float* arr;
    size_t size;

public:
    SortedList() : arr(nullptr), size(0) {} // default constructor to initialize the array to nullptr and size to 0

    SortedList(float* lis, size_t s): arr(lis), size(s){
        order();    // no matter how to array is given, it will be sorted
    }
    
    void order();   // helper function to sort the array
    void copy(const SortedList& other);
    void printArray(const SortedList& list);
    float index(size_t ind);
    size_t insert(float number);
    float remove(size_t index);
    size_t find(float number);
};