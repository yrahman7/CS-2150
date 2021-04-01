#ifndef PUZZLE_H
#define PUZZLE_H

class Puzzle {
 public:
  Puzzle(); //constructor
  int minStepsToSolve(Puzzle start, Puzzle end);
  int inversions(Puzzle puzzle);

  int slot[9];
  Puzzle* parent;
  Puzzle* edge;

 private:
  Puzzle* generateNeighbors(Puzzle* state);
};

#endif
