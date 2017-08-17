#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// the solution exists in setting the argument of srand() as the systems current time in seconds.
// the time() function in ctime library gives the time in seconds.
int main ()
{
  srand(time(0)); // time(0) returns the current second count.

  for (int x = 1; x <= 18; x++)  // every time the program runs, srand() will have a diff. argument and so rand() will
                                 // have a diff. seed value. This results in generating truly random numbers.
  {
    cout << 1 + (rand() % 15) << endl;
  }

  return 0;
}
