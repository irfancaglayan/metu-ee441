#pragma once
#include <iostream>

// Define your Tile struct
class Tile {
public:
    char m_suit;
    int m_number;

    // Default constructor
    Tile() {
		//throw std::logic_error("Function \"default constructor\" is not implemented!");
        m_number = 0;
        m_suit = ' ';
	}

    // Parameterized constructor
    Tile(char s, int n) {
		//throw std::logic_error("Function \"destructor\" is not implemented!");
        if (!(s == 'B' || s == 'C' || s == 'D')) {
            throw std::invalid_argument("Invalid suit. Suits must be B, C, or D."); // check for valid suits
        }
        m_suit = s;
        if (n < 1 || n > 9) {
            throw std::out_of_range("Invalid number. Numbers must be between 1 and 9."); // check for valid numbers
        }
        m_number = n;
	}

    // Comparison operator for equality
    bool operator==(const Tile& other) const {
        //throw std::logic_error("Function \"==\" is not implemented!");
        return (m_suit == other.m_suit && m_number == other.m_number);  // check if both suits and numbers are equal
        }
    
    // Overload less-than operator
    bool operator<(const Tile& other) const {
        //throw std::logic_error("Function \"<\" is not implemented!");
        return (m_suit < other.m_suit || (m_suit == other.m_suit && m_number < other.m_number)); // first compare the suits, then compare the numbers
    }

    // Overload greater-than operator
    bool operator>(const Tile& other) const {
        //throw std::logic_error("Function \">\" is not implemented!");
        return (m_suit > other.m_suit || (m_suit == other.m_suit && m_number > other.m_number)); // first compare the suits, then compare the numbers
    }

    bool operator<=(const Tile& other) const {
        //throw std::logic_error("Function \"<=\" is not implemented!");
        return (*this < other || *this == other);   // first compare the suits, then compare the numbers; use the previously overloaded operators
    }

    bool operator>=(const Tile& other) const {
        //throw std::logic_error("Function \">=\" is not implemented!");
        return (*this > other || *this == other);   // first compare the suits, then compare the numbers; use the previously overloaded operators
    }

    bool operator!=(const Tile& other) const {
        //throw std::logic_error("Function \"!=\" is not implemented!");
        return (!(*this == other)); // check directly using == operator
    }

    // Friend function to overload << operator for output
    friend std::ostream& operator<<(std::ostream& os, const Tile& tile) {
        os << tile.m_suit << tile.m_number;
        return os;
    }
};