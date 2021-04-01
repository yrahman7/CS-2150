// Yumna Rahman, yr6by
// November 18, 2020

#include <iostream>
#include "puzzle.h"

using namespace std;

int main() {
  Puzzle goalState;
  Puzzle initialState;
  
  int num;

  cout << "Enter puzzle" << endl;
  for (int i = 0; i < 9; i++) {
    cin >> num;
    initialState.slot[i] = num;
  }
  cout << "Solving puzzle" << endl;
  if (inversions(initialState) % 2 == 0) {
    minStepsToSolve(initialState, finalState);
  }
  else
    cout << "IMPOSSIBLE" << endl;

  return 0;
}
