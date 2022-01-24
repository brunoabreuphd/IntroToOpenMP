/***
 * File: indexgame_omp.cpp
 * Description: Index-game code parallelized with OpenMP
 * Author: Bruno R. de Abreu  |  babreu at illinois dot edu
 * National Center for Supercomputing Applications (NCSA)
 *
 * Creation Date: Monday, 24th January 2022, 10:21:35 am
 * Last Modified: Monday, 24th January 2022, 10:21:40 am
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
#include "omp.h"

#define ORD 1 << 14          // size of array
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
    double startT, stopT;     // measure execution time
    double c1, c2;            // compare results

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
    // print this specific element
    c1 = M[7790][10722];
    cout << "M[7790][10722] = " << c1 << endl;

    // now perform some funky matrix shuffling
    startT = omp_get_wtime(); // trigger stopwatch
    #pragma omp parallel
    {
        #pragma omp for private(j, shuff_i, shuff_j) schedule(dynamic)
        for (i = 0; i < ORD; i++)
        {
            for (j = 0; j < ORD; j++)
            {
                shuff_i = ((float(ORD) / 2.0) * abs((cos(PI * float(i) / float(j)) + sin(PI * float(j) / float(i))))) - 1;
                shuff_j = ((float(ORD) / 2.0) * abs((cos(PI * float(j) / float(i)) + sin(PI * float(i) / float(j))))) - 1;
                M[i][j] = M[shuff_i][shuff_j];
            }
        }
    }
    stopT = omp_get_wtime(); // stopwatch click
    cout << "\nShuffling time (s): " << (stopT - startT) << endl;

    // print output
    cout << "\nThe same elements of M after shuffling: " << endl;
    cout << r1 << "\t" << r2 << "\t" << M[r1][r2] << endl;
    cout << r3 << "\t" << r4 << "\t" << M[r3][r4] << endl;

    // compare results: is c1 = c2?
    c2 = M[100][1000];
    cout << "M[100][1000] = " << c2 << endl;

    // goodbye
    return 0;
}
