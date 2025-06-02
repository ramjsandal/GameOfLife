#include "../include/GameOfLife.hpp"
#include <iostream>
#include <unistd.h>
#include <stdlib.h>
using namespace std;

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
