!!!!
!! File: indexgame_omp.f90
!! Description: Index-game code parallelized with OpenMP
!! Author: Bruno R. de Abreu  |  babreu at illinois dot edu
!! National Center for Supercomputing Applications (NCSA)
!!  
!! Creation Date: Tuesday, 25th January 2022, 10:04:04 am
!! Last Modified: Tuesday, 25th January 2022, 10:35:04 am
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

!!!!
!!    This is a solution to the IndexGame exercise.
!!    I recommend you do not read this file any further
!!    unless you are sure you checked all the hints and
!!    tried your best to code it yourself.
!!!!


program indexgame_omp
    use, intrinsic :: iso_fortran_env
    use :: omp_lib
    implicit none
    integer, parameter :: dp = REAL64   ! double precision fp
    integer, parameter :: ORD = 2**14   ! matrix order
    real(dp), parameter :: PI = -4.0 * atan(-1.0_dp)    ! pi :D
    real(dp), dimension(:,:), allocatable :: M, B  ! matrices
    integer :: i, j     ! indexes to run over matrix
    integer :: shuff_i, shuff_j     ! shuffled indexes
    integer :: r1, r2, r3, r4       ! helpers to check results
    real(dp) :: r                   ! real helper
    real(dp) :: c1, c2              ! these will be used to compare results
    real(dp) :: startT, stopT       ! stopwatch variables

    ! allocate matrices
    allocate(M(ORD,ORD))
    allocate(B(ORD,ORD))

    ! initialize random number generator, fill matrices
    call random_seed()
    call random_number(M)
    B = 0.0_dp

    ! print some elements of M before shuffling
    call random_number(r)
    r1 = int(ORD*r)
    call random_number(r)
    r2 = int(ORD*r)
    call random_number(r)
    r3 = int(ORD*r)
    call random_number(r)
    r4 = int(ORD*r)
    write(*,*) 'Some elements of M before shuffling:'
    write(*,*) '        i', '           j', '           M(i,j)'
    write(*,*) r1, r2, M(r1,r2)
    write(*,*) r3, r4, M(r3,r4)
    ! print one specific element
    c1 = M(7791,10723)
    write(*,*) 'M(7791,10723) =', c1

    ! perform some funky shuffling
    startT = omp_get_wtime()    ! trigger stopwatch
    !$omp parallel shared(M,B)
        !$omp do schedule(static) private(i, j, shuff_i, shuff_j)
        do j = 1, ORD
            do i = 1, ORD
                shuff_i = (real(ORD)/2.0) * (abs(cos(PI*real(i)/real(j)) &
                        + sin(PI*real(j)/real(i))))
                shuff_i = max(1, shuff_i) 
                shuff_j = (real(ORD)/2.0) * (abs(cos(PI*real(j)/real(i)) &
                        + sin(PI*real(i)/real(j)))) 
                shuff_j = max(1, shuff_j)
                B(i,j) = M(shuff_i, shuff_j) 
            enddo
        enddo
        !$omp end do
    !$omp end parallel
    stopT = omp_get_wtime()

    ! print execution time
    write(*,*)
    write(*,*) 'Shuffling time (s): ', (stopT-startT)

    ! print output
    write(*,*)
    write(*,*) 'The same elements after shuffling:'
    write(*,*) r1, r2, B(r1,r2)
    write(*,*) r3, r4, B(r3,r4)

    ! compare results: is c1 = c2?
    c2 = B(100,1000)
    write(*,*) "B(100,1000) = ", c2

    ! cleanup and bye
    deallocate(M)    
    deallocate(B)                    

end program indexgame_omp
