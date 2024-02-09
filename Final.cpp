/*
Arghyo Chakma
Prof. Conrad
CSC-17A Winter 2024
2-8-2024
*/

#include <iostream>
#include <string>
#include <vector>

// Base Class 
class Game {
    protected: 
    std::string title;
    int releaseYear;

    public:
    Game(const std::string& title, int releaseYear) : title(title), releaseYear(releaseYear) {}

    virtual void display() const{
        std::cout<<"Title: " << title << ", Release Year: " << releaseYear; 
    }
};

// SubClass RolePlayGame
class RolePlayGame : public Game {
    public:
    RolePlayGame(const std::string& title, int releaseYear) : Game(title, releaseYear) {}

    void display() const override {
        std::cout << "Role_Play Game - ";
        Game::display();
    }
};

// SubClass2 CardGame
class CardGame : public Game {
    public: 
    CardGame(const std::string& title, int releaseYear) : Game(title, releaseYear) {}

    void display() const override {
        std::cout << "Card Game - ";
        Game::display();
    }
};

// SubClass TradingCardGame that inherits from CardGame and uses a composite class CardPack
class CardPack {
    private:
    int numberOfCards;

    public:
    CardPack(int numberOfCards) : numberOfCards(numberOfCards) {}

    void display() const{
        std::cout << "Number of Cards: " << numberOfCards;
    }
};

class TradingCardGame : public CardGame {
    private:
    CardPack cardPack;

    public:
    TradingCardGame(const std::string& title, int releaseYear, int numberOfCards)
        : CardGame(title, releaseYear), cardPack(numberOfCards){}

    void display() const override {
        CardGame::display();
        std::cout << ",";
        cardPack.display();
    }
};

// Template class GameCollection
template <typename T>
class GameCollection {
    private:
    std::vector<T> games;

    public:
    void addGame(const T& game) {
        games.push_back(game);
    }
    void displayAll() const {
        for (const auto& game : games) {
            game.display();
            std::cout << std::endl;
        }
    }
};

int main() {
    GameCollection<Game> gameCollection;

    // Test the GameCollection
    RolePlayGame rpg("Elden Ring", 2022);
    CardGame cardGame("Poker", 1800);
    TradingCardGame tcg("Magic: The Gathering", 1993, 100);

    gameCollection.addGame(rpg);
    gameCollection.addGame(cardGame);
    gameCollection.addGame(tcg);

    // Display all the games in the collection
    gameCollection.displayAll();

    return 0;
}