! Comment
program main
  implicit integer
  ! Read array from file
  integer, dimension(:), allocatable :: x
  integer :: n
  open(unit=99, file='array.txt', status='old', action='read')
  read(99, *) n
  allocate(x(n))
  read(99, *) x
  write(*,*) x

  ! Call subroutine to sort
  call sort(x, size(x))
  print *,x
end program main

! Insertion sorg algorithm
subroutine sort(a, s)
  ! Good practice
  implicit none
  integer :: s, i, j, a(s), x
  do i = 2, s
    x = a(i)
    j = i - 1
      do while (j >= 1)
        if (a(j) <= x) exit
          print *,a
          a(j + 1) = a(j)
          j = j - 1
      end do
      a(j + 1) = x
  end do
end subroutine
