/***
* File: saxpy_omp.cpp
* Description: SAXPY implementation with OpenMP-parallelized loop
* Author: Bruno R. de Abreu  |  babreu at illinois dot edu
* National Center for Supercomputing Applications (NCSA)
*  
* Creation Date: Wednesday, 19th January 2022, 9:33:43 am
* Last Modified: Thursday, 20th January 2022, 9:46:51 am
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

/****
 ***    This is the solution to the SAXPY exercise.
 ***    I recommend you do not read this file any further
 ***    unless you are sure you checked all the hints and
 ***    tried your best to code it yourself.
 ****/

#include <iostream>
#include <vector>
#include "omp.h"

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
    double startT, stopT;

    // perform SAXPY
    startT = omp_get_wtime(); // trigger stopwatch
    #pragma omp parallel
    {
        #pragma omp for schedule(dynamic)
        for (int i = 0; i < x.size(); i++)
        {
            y[i] = a * x[i] + y[i];
        }
    }
    stopT = omp_get_wtime(); // trigger stopwatch

    // print time
    cout << "Elapsed time (s): " << (stopT - startT) << endl;

    // check result
    cout << "\nSamples of y: " << endl;
    int test;
    for (int i = 0; i < 5; i++)
    {
        test = rand() % 100000;
        cout << y[test] << endl;
    }

    // goodbye
    return 0;
}
