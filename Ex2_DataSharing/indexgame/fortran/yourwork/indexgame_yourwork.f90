program indexgame_yourwork
    use, intrinsic :: iso_fortran_env
    implicit none
    integer, parameter :: dp = REAL64   ! double precision fp
    integer, parameter :: ORD = 2**14   ! matrix order
    real(dp), parameter :: PI = -4.0 * atan(-1.0_dp)    ! pi :D
    real(dp), dimension(:,:), allocatable :: M  ! matrix
    integer :: i, j     ! indexes to run over matrix
    integer :: shuff_i, shuff_j     ! shuffled indexes
    integer :: r1, r2, r3, r4       ! helpers to check results
    real(dp) :: r                   ! real helper

    ! allocate matrix
    allocate(M(ORD,ORD))

    ! initialize random number generator, fill matrix
    call random_seed()
    call random_number(M)

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

    ! perform some funky shuffling
    do j = 1, ORD
        do i = 1, ORD
            shuff_i = (real(ORD)/2.0) * (abs(cos(PI*real(i)/real(j)) &
                        + sin(PI*real(j)/real(i))))
            shuff_i = max(1, shuff_i) 
            shuff_j = (real(ORD)/2.0) * (abs(cos(PI*real(j)/real(i)) &
                        + sin(PI*real(i)/real(j)))) 
            shuff_j = max(1, shuff_j)
            M(i,j) = M(shuff_i, shuff_j) 
        enddo
    enddo

    ! print output
    write(*,*)
    write(*,*) 'The same elements after shuffling:'
    write(*,*) r1, r2, M(r1,r2)
    write(*,*) r3, r4, M(r3,r4)


    ! cleanup and bye
    deallocate(M)                        

end program indexgame_yourwork