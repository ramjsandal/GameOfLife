#pragma once
#include <vector>

class GameOfLife {
  private:
    // buffer holding the current state of the game
    std::vector<std::vector<bool>> current;

    // buffer holding the next state of the game
    std::vector<std::vector<bool>> next;

    // updates the cell at the given x y
    void updateCell(int x, int y);

    // count the number of alive neighbors at this cell
    int numAliveNeighbors(int x, int y); 

    // check if a square is on the board
    bool onBoard(int x, int y);

  public:
    
    // default constructor
    GameOfLife(); 

    // prints the current state of the game
    void printCurrent();

    // updates the state of the game
    void update();

    // return the current population of the board
    int currentPopulation();
};
