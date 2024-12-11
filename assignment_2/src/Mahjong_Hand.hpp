#pragma once
#include <algorithm>
#include "Tile.hpp"

#define MAX_HAND_SIZE 14
class Hand {
private:
    Tile* m_tiles[MAX_HAND_SIZE];        // Array of pointers to Tile objects
    size_t m_handSize;       // Current hand size

    void insert_before(size_t index, Tile* new_tile) {
        //throw std::logic_error("Function \"insert_before\" is not implemented!");
        if (m_handSize > MAX_HAND_SIZE){
            throw std::out_of_range("Your hand is full already!");  // check if insertion is possible
        }
        
        if (index > m_handSize) {
            throw std::out_of_range("Invalid index for insertion."); // check if index is valid
        }

        for (size_t i=m_handSize; i > index; i--){
            m_tiles[i] = m_tiles[i-1];  // shift tiles to right for insertion before
        }
        m_tiles[index] = new_tile; // insert the tile
        m_handSize++; // increase the hand size to indicate new tile inserted
    };

    Tile * pop(size_t index) {
        //throw std::logic_error("Function \"pop\" is not implemented!");
        if (index >= m_handSize){
            throw std::out_of_range("Invalid index for pop.");  // check if index is valid
        }
        
        Tile* temp = m_tiles[index];    // store the tile to be deleted for later return
        for (size_t i = index; i < m_handSize - 1; i++){
            m_tiles[i] = m_tiles[i + 1];    // overwrite the tiles starting from the deleted index, thus the chosen tile is popped and hand is shifted to left as needed
        }

        m_tiles[m_handSize - 1] = nullptr;  // reassign the empty space obtained in array after shifting operation to nullptr
        m_handSize--;   // reduce the hand size to indicate a tile is popped
        
        return temp;    // return the popped tile
    };
public:
    // Constructors and Destructor
    Hand() {
        //throw std::logic_error("Function \"default constructor\" is not implemented!");
        m_handSize = 0; // start with an empty hand

        for (size_t i=0; i < MAX_HAND_SIZE; ++i){
            m_tiles[i] = nullptr;   // assign all pointers to nullptr for initialization
        }
    };
    ~Hand() {
        //throw std::logic_error("Function \"destructor\" is not implemented!");
        for (size_t i = 0; i < MAX_HAND_SIZE; i++){
            delete m_tiles[i];  // free the memory all tiles individually
            m_tiles[i] = nullptr; // reassign all pointers to nullptr
        }
    };

    // Member Functions
    void clear() {
        //throw std::logic_error("Function \"clear\" is not implemented!");
        for (size_t i = 0; i < m_handSize; i++){
            delete m_tiles[i];  // free the memory all tiles individually
            m_tiles[i] = nullptr;   // reassign all pointers to nullptr
        }

        m_handSize = 0; // reset the hand size
    };

    void add_tile(Tile* tile) {
        //throw std::logic_error("Function \"add_tile\" is not implemented!");
        size_t temp_index = 0;  // initialize the index to be assigned for insertion
        for (size_t i=0; i < m_handSize; i++){
            if (*tile < *m_tiles[i]){
                break;  // break the loop after finding the index to insert
            }
        temp_index++;   // increase the index if not found yet
        }
        insert_before(temp_index, tile);    // insert the new tile to found index
    };

    Tile* discard_tile(void) {
        //throw std::logic_error("Function \"discard_tile\" is not implemented!");
        if (m_handSize == 0) {
           throw std::logic_error("Cannot discard from an empty hand.");    // handle if there is an empty hand
        }

        int copies = 0; // initialize copies counter for each tile
        int highest_count = 0;  // initialize a counter result storage for comparison later
        size_t discard_index = 0;   // initialize an index for the tile to be discarded

        for (size_t i = 0; i < m_handSize; i++){
            if (i < m_handSize - 1 && *m_tiles[i] == *m_tiles[i + 1]){  // if a tile and the next tile are the same, increase the copy count
                copies++; // this works because the tiles are sorted and all copies are located next to each other
            }
            else {
                int total_copies = copies + 1; // add the initial copy to obtain total count for a certain tile

                // quadruples
                if (total_copies == 4 && total_copies > highest_count){ // if there are 4 copies of a certain tile, and the highest_count is not 4
                    highest_count = total_copies;   // change the highest_count to be 4
                    discard_index = i; // store the index to later discard one of the quadruples
                }
                // singles
                else if (total_copies == 1 && highest_count < 4){   // if there is a single tile and there are no quadruples found earlier
                    highest_count = total_copies;   // change the highest_count to be 1
                    discard_index = i; // store the index to later discard the single tile
                }
                // pairs
                else if (total_copies == 2 && highest_count < 2){   // if there are no single tiles or quadruples, and no pairs have been found before
                    highest_count = total_copies;   // change the highest_count to be 2
                    discard_index = i; // store the index to later discard one of the pairs
                }

                copies = 0; // reset counter for the next tile group
            }
        }

        if (highest_count == 0) {
            throw std::logic_error("No valid tile to discard.");    // this case is only possible if the hand is not initialized properly and left empty
        }

        return pop(discard_index); // remove and return the discarded tile
    };

    bool check_win_condition() const {
        //throw std::logic_error("Function \"check_win_condition\" is not implemented!");
        int copies = 0; // initialize copies counter for each tile
        int triplets = 0; // initialize triplets counter
        int pairs = 0; // initialize pairs counter

        for (size_t i = 0; i < m_handSize; i++){
            if (i < m_handSize - 1 && *m_tiles[i] == *m_tiles[i + 1]){  // same logic as in discard_tile()
                copies++;
            }
            else {
                int total_copies = copies + 1;

                if (total_copies == 3){ // if there are 3 of the same tile, increment the triplets counter
                    triplets++;
                }
                else if (total_copies == 2){ // if there are 2 of the same tile, increment the pairs counter
                    pairs++;
                }

                copies = 0; // reset the copies counter for each tile group
            }
        }

        return(triplets == 4 && pairs == 1);    // if there are 4 triplets and 1 pair in your hand, you win
    };

    // Display Function
    void display_hand() const {
        //throw std::logic_error("Function \"display_hand\" is not implemented!");    
        for(size_t i = 0; i < m_handSize; i++){
            if (m_tiles[i] != nullptr){
                std::cout << *m_tiles[i] << " ";    // this utilizes the << operator overloaded in Tile.hpp
            }
        }
        std::cout << std::endl;
    };
};
