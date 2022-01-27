!!!!
!! File: saxpy_pseudo_omp1.f90
!! Description: SAXPY simple implementation with hints to include OpenMP directives
!! Author: Bruno R. de Abreu  |  babreu at illinois dot edu
!! National Center for Supercomputing Applications (NCSA)
!!  
!! Creation Date: Thursday, 20th January 2022, 10:04:28 am
!! Last Modified: Thursday, 20th January 2022, 10:08:08 am
!!  
!! Copyright (c) 2022, Bruno R. de Abreu, National Center for Supercomputing Applications.
!! All rights reserved.
!! License: This program and the accompanying materials are made available to any individual
!!          under the citation condition that follows: On the event that the software is
!!          used to generate data that is used implicitly or explicitly for research
!!          purposes, proper acknowledgment must be provided in the citations section of
!!          publications. This includes both the author's name and the National Center
!!          for Supercomputing Applications. If you are uncertain about how to do
!!          so, please check this page: https://github.com/babreu-ncsa/cite-me.
!!          This software cannot be used for commercial purposes in any way whatsoever.
!!          Omitting this license when redistributing the code is strongly disencouraged.
!!          The software is provided without warranty of any kind. In no event shall the
!!          author or copyright holders be liable for any kind of claim in connection to
!!          the software and its usage.
!!!!

program saxpy_hints
    use, intrinsic :: iso_fortran_env
    ! ## HINT1 include the OpenMP module here ##
    implicit none
    integer, parameter :: sp = REAL32   ! single precision
    integer, parameter :: dp = REAL64   ! double precision
    integer, parameter :: ORD = 2**27   ! arrays size
    real(sp), dimension(:), allocatable :: x, y     ! arrays
    real(sp) :: a   ! scalar constant    
    integer :: i    ! integer helper
    ! ## HINT1 add a couple of reals to track execution time ##

    ! allocate memory space
    allocate(x(ORD))
    allocate(y(ORD))
    
    ! initialize random number generator, set values of x, y, a
    call random_seed()
    call random_number(x)   ! x is noise
    y = 1.0_sp              ! y is just ones
    a = 2.0_sp              ! a is the scalar y -> a*x + y

    ! perform SAXPY
    ! ## HINT1 trigger stopwatch ##
    ! ## HINT1 open omp parallel region here ##
    ! ## HINT1 open omp do directive here ##
    do i = 1, ORD
        y(i) = a*x(i) + y(i)
    enddo
    ! ## HINT1 close omp do directive here ##
    ! ## HINT1 close omp parallel region here ##
    ! ## HINT1 trigger stopwatch ##
 
    ! ## HINT1 print execution time here ##

    ! ## HINT1 check your results here ##

    ! clean up
    deallocate(x,y)

end program saxpy_hints
