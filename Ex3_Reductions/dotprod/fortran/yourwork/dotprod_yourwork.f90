program dotprod_yourwork
    use, intrinsic :: iso_fortran_env
    implicit none
    integer, parameter :: dp = REAL64   ! double precision
    integer, parameter :: ORD = 2**29   ! arrays size
    real(dp), dimension(:), allocatable :: v1, v2   ! arrays
    real(dp) :: dotp    ! this will hold the dot product
    integer :: i        ! this will run loops over the arrays

    ! allocate arrays
    allocate(v1(ORD))
    allocate(v2(ORD))

    ! attribute values to arrays (random numbers)
    call random_seed()  ! start RNG
    call random_number(v1)
    call random_number(v2)

    ! calculate dot product
    dotp = 0.0_dp
    do i = 1, ORD
        dotp = dotp + v1(i)*v2(i)
    enddo

    ! print result
    write(*,*) 'Dot product is: ', dotp

    ! cleanup and goodbye
    deallocate(v1,v2)

end program dotprod_yourwork