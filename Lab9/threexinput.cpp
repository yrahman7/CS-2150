#include <iostream>
#include "timer.h"

extern "C" int threexplusone(int x);

int main() {
  //1. Ask for an input value, x, which is the positive integer to pass to the subroutine.
  //2. Ask for an input value, n, which is the number of times to call the subroutine.
  unsigned int x, n;
  cout << "Enter a number: ";
  cin >> x;
  cout << "Enter iterations of subroutine: ";
  cin >> n;

  //3. Run the subroutine once and store the result.
  int result = threexplusone(x);
  cout << "Iterations: " << result << endl;

  //4. Run the subroutine n times with the parameter x as the input.
  //Use the timer to guage the average time it took to run each subroutine call in step 4.
  timer t;
  t.start();
  for (int i = 0; i < n; i++) {
    threexplusone(x);
  }
  t.stop();
  
  return 0;
}
