#include <iostream>
#include <vector>
#include <sys/time.h>

#define ORD 1 << 27 // size of array

using namespace std;

int main()
{
    // instantiate vectors and attribute values
    vector<float> x, y;
    float r, elmnt;
    srand(time(NULL)); // random number generator seed
    for (int i = 0; i < ORD; i++)
    {
        r = rand() % RAND_MAX;         // get a random integer
        elmnt = float(r) / (RAND_MAX); // normalize it
        x.push_back(elmnt);            // x is noise
        y.push_back(1.0);              // y is just ones
    }
    float a = 2.0; // scalar multiplier (y -> a*x + y)

    // stopwatch to measure time
    struct timeval startT, stopT, elapsedT;

    // perform SAXPY
    gettimeofday(&startT, NULL); // trigger stopwatch
    for (int i = 0; i < x.size(); i++)
    {
        y[i] = a * x[i] + y[i];
    }
    gettimeofday(&stopT, NULL); // trigger stopwatch

    // print time
    timersub(&stopT, &startT, &elapsedT);
    cout << "Elapsed time (s): " << elapsedT.tv_sec + elapsedT.tv_usec / 1000000.0 << endl;

    // goodbye
    return 0;
}