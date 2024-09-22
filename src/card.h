#pragma once

#include <array>
#include <format>
#include <ostream>
#include <string_view>

struct Card {
    public:
    enum Suit {
        heart,
        diamond,
        club,
        spade,
        max_suits,
    };

    enum Rank {
        A,
        two,
        three,
        four,
        five,
        six,
        seven,
        eight,
        nine,
        ten,
        J,
        Q,
        K,
        max_ranks,
    };

    private:
    static constexpr std::array<std::string_view, max_suits> m_suit_names{
        "♥",
        "♦",
        "♠",
        "♣",
    };
    static_assert(m_suit_names.size() == Suit::max_suits, "Suit names must be the same size than Suit");

    static constexpr std::array<std::string_view, max_suits> m_suit_colors{
        "91",
        "31",
        "30",
        "90",
    };
    static_assert(m_suit_colors.size() == Suit::max_suits, "Suit colors must be the same size than Suit");

    static constexpr std::array<std::string_view, max_ranks> m_rank_names{
        "A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K",
    };
    static_assert(m_rank_names.size() == Rank::max_ranks, "Rank names must be the same size than Rank");

    public:
    Suit suit;
    Rank rank;

    friend std::ostream& operator<<(std::ostream& out, const Card& card) {
        return out << std::format("\033[{};107m{}{}\033[0m", m_suit_colors[card.suit], name_of(card.rank), name_of(card.suit));
    }

    static constexpr std::string_view name_of(Suit suit) { return m_suit_names[suit]; }

    static constexpr std::string_view name_of(Rank rank) { return m_rank_names[rank]; }
};
