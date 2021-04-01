#include "puzzle.h"

Puzzle::Puzzle() {
  //initialize goal state
  for (int i = 0; i < 9; ++i) {
    slot[i] = i;
  }
  slot[9] = 0;
  
  parent = NULL;
  edge = NULL;
}

int Puzzle::inversions(Puzzle puzzle) {
  int count = 0;
  for (int i = 0; i < 9 - 1l i++) {
    for (int j = i + 1; j < 9; j++) {
      if (puzzle.slot[j] && puzzle.slot[i] && puzzle.slot[i] > puzzle.slot[j])
	count++;
    }
  }
  return count;
}

int Puzzle::minStepsToSolve(Puzzle start, Puzzle end) {
  Queue q(NUM_VERTICES);
  Vertex v, w;
  q.enqueue(s);
  s.dist = 0;

  while (!q.isEmpty()) {
    generateNeighbors(Puzzle* state);
    v = q.dequeue();
    for each w adjacent to v
      // each edge examined at most once,
      // if adjacency lists are used
      if (w.dist == INFINITY) {
        w.dist = v.dist + 1;
        w.path = v;
        q.enqueue(w); // each vertex added at most once
      }
    }
  }
  

  check if neighrbor has been searched (hashTable)
		       yes >> discard
  add to graph and BFS queue

 
}

Puzzle* generateNeighbors() {
}
