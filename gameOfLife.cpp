#include <iostream>
#include <vector>
#include <unistd.h>
#include <stdlib.h>
using namespace std;


// Controls our game of life
class GameOfLife {
  private:
  std::vector<std::vector<bool>> current;
  std::vector<std::vector<bool>> next;

  public:
  GameOfLife() {
    std::vector<std::vector<bool>> init(40, vector<bool>(160, false));
    srand(4);

    for (int i = 0; i < init.size(); i++) {
      for (int j = 0; j < init[0].size(); j++) {
        init[i][j] = rand() % 2 == 0;
      }
    }
    
    current = init;
    next = current;
  }
  void printCurrent() {
    for (int i = 0; i < current.size(); i++) {
      for (int j = 0; j < current[0].size(); j++) {
        char symbol = current[i][j] ? 'x' : ' ';
        std::cout << symbol;
      }
      std::cout << std::endl;
    }
    std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
  }


  void update() {

    for (int i = 0; i < current.size(); i++) {
      for (int j = 0; j < current[0].size(); j++) {
        updateCell(i,j);
      }
    }

    current = next;
  }
  void updateCell(int x, int y) {
    int numAlive = numAliveNeighbors(x, y);
    bool alive = current[x][y];
    bool nextState = alive;

    if (!alive) {
      nextState = numAlive == 3;
    } else {
      nextState = (numAlive == 2 || numAlive == 3);
    }

    next[x][y] = nextState;
  }
  int numAliveNeighbors(int x, int y) {
    int numAlive = 0;
    // iterate around this cell and check its neighbors for aliveness
    for (int i = x-1; i <= x+1; i++) {
      for (int j = y-1; j <= y+1; j++) {
        if (!onBoard(i, j) || (i == x && j == y)) { continue; } 
        
        if (current[i][j]) {
          numAlive++;
        }
      }
    }

    return numAlive;

  }

  bool onBoard(int x, int y) {
    return (x >= 0 && x < current.size()) && (y >= 0 && y < current[0].size());
  }

  int currentPopulation() {
    int pop = 0;
    for (int i = 0; i < current.size(); i++) {
      for (int j = 0; j < current[0].size(); j++) {
        pop += current[i][j] ? 1 : 0;
      }
    }
    return pop;
  }
  

};

int main() {
  GameOfLife* gol = new GameOfLife();
  bool playing = true;
  int iteration = 0;

  while (playing) {

    std::cout << "Iteration: " << iteration << std::endl;
    std::cout << "Population: " << gol->currentPopulation() << std::endl;
    gol->printCurrent();
    gol->update();
    iteration++;
    usleep(1000000);

  }


  delete gol;
}
