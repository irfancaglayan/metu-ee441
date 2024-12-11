#pragma once

#include <iostream>

template <class T>
class Stack
{
private:
    size_t m_capacity;
    size_t m_size;
    T* m_data;

public:
    Stack() {
		//throw std::logic_error("Function \"default constructor\" is not implemented!");
        m_capacity = 0;
        m_size = 0;
        m_data = nullptr;
	}
    Stack(size_t capacity)
    {
        //throw std::logic_error("Function \"constructor\" is not implemented!");
        m_capacity = capacity;  // initialize with the parameter
        m_size = 0;
        m_data = new T[m_capacity]; // initialize with the parameter
    }
    ~Stack()
    {
        //throw std::logic_error("Function \"destructor\" is not implemented!");
        delete[] m_data;    // deleting the dynamically allocated array
        m_data = nullptr;   // reassign the pointer to nullptr
        m_capacity = 0;     // reset the capacity
        m_size = 0;         // reset the size
    }

    bool is_empty() const {
        //throw std::logic_error("Function \"is_empty\" is not implemented!");
        return m_size == 0; // check for empty stack
    }

    void clear() {  // works like the destructor
        //throw std::logic_error("Function \"clear\" is not implemented!");
        delete[] m_data;
        m_data = nullptr;
        m_capacity = 0;
        m_size = 0;
    }

    void reserve(size_t new_capacity)
    {
        //throw std::logic_error("Function \"reserve\" is not implemented!");
        T* new_data = new T[new_capacity];  // new pointer array to store the chosen tiles

        size_t elements_to_copy = (new_capacity < m_size) ? new_capacity : m_size;  // check if new capacity is smaller; if so, only that amount of elements will be copied; otherwise, everything up to the size will be copied

        for (size_t i = 0; i < elements_to_copy; i++) {
                new_data[i] = m_data[i];    // copy the tiles to new array
        }
        
        if (new_capacity < m_size) {
            m_size = new_capacity;  // equalize size to new capacity if the new capacity is smaller
        }

        delete [] m_data;   // free the initial array
        m_data = new_data;  // reload the initial array with the new array
        m_capacity = new_capacity;  // reassign the new capacity accordingly
    }

    void push_back(const T& value)
    {
        //throw std::logic_error("Function \"push_back\" is not implemented!");
        if (m_capacity == 0){
            reserve(1); // if the stack size is zero, add a new slot
        }
        else if (m_size == m_capacity){
            reserve(m_capacity * 2);    // if the stack is full, double the capacity
        }

        m_data[m_size] = value; // add the new value to the end of the stack
        m_size++;   // increase the size accordingly
    }

    T pop_back()
    {   
        //throw std::logic_error("Function \"pop_back\" is not implemented!");
        if (is_empty()){
            throw std::out_of_range("The stack is empty, nothing to pop."); // check for empty stack
        }

        T temp = m_data[m_size - 1];    // store the final tile, -1 is there because of the indexing starts from 0
        m_size--;   // decrease the size accordingly
        return temp;    // return the popped value
    }

    // Friend function to overload << operator for output
    friend std::ostream& operator<<(std::ostream& os, const Stack& stack)
    {
        os << "[ ";
        for (size_t i = 0; i < stack.m_size; ++i) {
            os << stack.m_data[i] << ' ';
        }
        os << ']';
        return os;
    }
};