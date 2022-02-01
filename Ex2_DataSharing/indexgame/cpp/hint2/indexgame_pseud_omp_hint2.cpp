/***
 * File: indexgame_pseud_omp_hint2.cpp
 * Description: Hints to parallelize Index Game with OpenMP
 * Author: Bruno R. de Abreu  |  babreu at illinois dot edu
 * National Center for Supercomputing Applications (NCSA)
 *
 * Creation Date: Monday, 24th January 2022, 2:14:37 pm
 * Last Modified: Monday, 24th January 2022, 2:14:40 pm
 *
 * Copyright (c) 2022, Bruno R. de Abreu, National Center for Supercomputing Applications.
 * All rights reserved.
 * License: This program and the accompanying materials are made available to any individual
 *          under the citation condition that follows: On the event that the software is
 *          used to generate data that is used implicitly or explicitly for research
 *          purposes, proper acknowledgment must be provided in the citations section of
 *          publications. This includes both the author's name and the National Center
 *          for Supercomputing Applications. If you are uncertain about how to do
 *          so, please check this page: https://github.com/babreu-ncsa/cite-me.
 *          This software cannot be used for commercial purposes in any way whatsoever.
 *          Omitting this license when redistributing the code is strongly disencouraged.
 *          The software is provided without warranty of any kind. In no event shall the
 *          author or copyright holders be liable for any kind of claim in connection to
 *          the software and its usage.
 ***/

#include <iostream>
#include <vector>
#include <cmath>
// !! HINT1 include the OpenMP header here !!

#define ORD 1 << 15          // size of array
#define PI -4.0 * atan(-1.0) // pi ;D

using namespace std;

int main()
{
    // variables
    vector<vector<double>> M; // matrix
    vector<double> v;         // vector
    float r;                  // this will hold random numbers
    srand(time(NULL));        // choose random seed for random number generator
    int i, j;                 // these will run over M
    int shuff_i, shuff_j;     // these will be the shuffled index
    int r1, r2, r3, r4;       // these will help us check resutls
    // !! HINT1 add a couple of doubles to measure execution time !!

    // instantiate M with random numbers
    for (i = 0; i < ORD; i++)
    {
        for (j = 0; j < ORD; j++)
        {
            r = float(rand() % RAND_MAX); // get a random integer
            v.push_back(r);               // push it to vector
        }
        M.push_back(v); // push it to matrx
        v.clear();      // clear vector
    }
    // print a couple of elements
    cout << "Some elements of M before shuffling: " << endl;
    r1 = rand() % int(ORD);
    r2 = rand() % int(ORD);
    r3 = rand() % int(ORD);
    r4 = rand() % int(ORD);
    cout << "i\t" << "j\t" << "M[i][j]" << endl;
    cout << r1 << "\t" << r2 << "\t" << M[r1][r2] << endl;
    cout << r3 << "\t" << r4 << "\t" << M[r3][r4] << endl;

    // now perform some funky matrix shuffling
    // !! HINT1 trigger stopwatch !!
    // !! HINT1 start the parallel region here !!
    // !! HINT2 declare explicitly which variables are shared in this region !!
    // !! HINT1 start the omp loop here -- you can now include the scheduling choice !!
    // !! HINT2 declare explicitly which variables are private in this loop !!
    for (i = 1; i < ORD; i++)
    {
        for (j = 1; j < ORD; j++)
        {
            shuff_i = (float(ORD) / 2.0) * abs((cos(PI * float(i) / float(j)) + sin(PI * float(j) / float(i)))) - 1;
            shuff_j = (float(ORD) / 2.0) * abs((cos(PI * float(j) / float(i)) + sin(PI * float(i) / float(j)))) - 1;
            M[i][j] = M[shuff_i][shuff_j];
        }
    }
    // !! HINT1 don't forget to close your OMP directives here !!
    // !! HINT1 trigger stopwatch !!

    // !! HINT1 print out the execution time here !!

    // print output
    cout << "\nThe same elements of M after shuffling: " << endl;
    cout << r1 << "\t" << r2 << "\t" << M[r1][r2] << endl;
    cout << r3 << "\t" << r4 << "\t" << M[r3][r4] << endl;

    // !! HINT1 check results here !!
    // !! HINT2 Choose a couple of values i and j, perform the transformation into shuff_i and shuff_j by hand, and check to see it it matches !!

    // goodbye
    return 0;
}
