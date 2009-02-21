#include "nrand.h"
#include <cstdlib>

using namespace std;

// Return a random integer in the range [0, n)
int nrand(int n)
{
  if (n <= 0 || n > RAND_MAX)
    return -1;

  const int bucket_size = RAND_MAX / n;
  int r;

  do r = rand() / bucket_size;
  while (r >= n);

  return r;
}
