#include <iostream>
#include <vector>

#define ORD 1 << 29 // size of arrays

using namespace std;

int main()
{
    // declare variables
    vector<double> v1, v2; // vectors
    double r;              // this will hold random numbers
    double dotp;           // this will hold the dot product
    int i;                 // index that runs over vectors

    // start random number generator, fill up vectors
    srand(time(NULL));
    for (i = 0; i < ORD; i++)
    {
        r = double(rand() % RAND_MAX) / RAND_MAX; // random number between 0 and 1
        v1.push_back(r);
        r = double(rand() % RAND_MAX) / RAND_MAX;
        v2.push_back(r);
    }

    // calculate dot product
    dotp = 0.0;
    for (i = 0; i < ORD; i++)
    {
        dotp = dotp + v1[i] * v2[i];
    }

    // print result
    cout << "Dot product is: " << dotp << endl;

    // goodbye
    return 0;
}