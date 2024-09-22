#pragma once

#include <array>
#include <iostream>

#include "card.h"

class Deck {
    private:
    static constexpr int SIZE{52};

    std::array<Card, SIZE> cards{};

    public:
    Deck() {
        for (int suit{0}; suit < Card::max_suits; ++suit) {
            for (int rank{0}; rank < Card::max_ranks; ++rank) {
                int i{suit * (Card::max_ranks - 1) + rank};
                cards[i] = Card{static_cast<Card::Suit>(suit), static_cast<Card::Rank>(rank)};

                std::cout << cards[i] << ' ';
            }
        }
        std::cout << '\n';
    }

    void shuffle(int iterations = SIZE) {
        for (int i{0}; i < iterations; ++i) {
            //shuf
        }
    }
};
