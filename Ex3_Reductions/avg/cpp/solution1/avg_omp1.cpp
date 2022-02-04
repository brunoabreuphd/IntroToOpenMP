/***
 * File: avg_omp1.cpp
 * Description: Parallelized AVG calculation using OMP CRITICAL
 * Author: Bruno R. de Abreu  |  babreu at illinois dot edu
 * National Center for Supercomputing Applications (NCSA)
 *
 * Creation Date: Friday, 4th February 2022, 9:43:42 am
 * Last Modified: Friday, 4th February 2022, 9:43:46 am
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
#include "omp.h"

#define ORD 1 << 29 // size of arrays

using namespace std;

int main()
{
    // declare variables
    vector<double> vec;           // vector
    double r;                     // this will hold random numbers
    double thread_avg, total_avg; // this will hold the averages
    double startT, stopT;         // these will hold time
    int i;                        // index that runs over vectors

    // start random number generator, fill up vectors
    srand(time(NULL));
    for (i = 0; i < ORD; i++)
    {
        r = double(rand() % RAND_MAX) / RAND_MAX; // random number between 0 and 1
        vec.push_back(r);
    }

    // calculate dot product
    total_avg = 0.0;
    startT = omp_get_wtime();
#pragma omp parallel shared(vec, total_avg) private(thread_avg)
    {
        thread_avg = 0.0;
#pragma omp for
        for (i = 0; i < ORD; i++)
        {
            thread_avg = thread_avg + vec[i];
        }
#pragma omp critical
        {
            total_avg = total_avg + thread_avg;
        }
    }
    stopT = omp_get_wtime();

    // print execution time
    cout << "Avg calculated in (s): " << (stopT - startT) << endl;

    // print result
    cout << "Average is: " << total_avg / double(ORD) << endl;

    // goodbye
    return 0;
}
