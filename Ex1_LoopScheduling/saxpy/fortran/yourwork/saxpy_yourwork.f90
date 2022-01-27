program saxpy_yourwork
    use, intrinsic :: iso_fortran_env
    implicit none
    integer, parameter :: sp = REAL32   ! single precision
    integer, parameter :: dp = REAL64   ! double precision
    integer, parameter :: ORD = 2**27   ! arrays size
    real(sp), dimension(:), allocatable :: x, y     ! arrays
    real(sp) :: a   ! scalar constant    
    integer :: i    ! integer helper

    ! allocate memory space
    allocate(x(ORD))
    allocate(y(ORD))
    
    ! initialize random number generator, set values of x, y, a
    call random_seed()
    call random_number(x)   ! x is noise
    y = 1.0_sp              ! y is just ones
    a = 2.0_sp              ! a is the scalar y -> a*x + y

    ! perform SAXPY
    do i = 1, ORD
        y(i) = a*x(i) + y(i)
    enddo

    ! clean up
    deallocate(x,y)

end program saxpy_yourwork
