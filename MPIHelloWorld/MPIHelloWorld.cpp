// MPIHelloWorld.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "mpi.h"
#include "stdio.h"
#include "stdlib.h"


int main(int argc, char * argv[])
{
  MPI_Init(&argc, &argv);

  int rank;

  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  if (rank == 0) {
    char hello[] = "Hello, World";
    MPI_Send(hello, _countof(hello), MPI_CHAR, 1, 0, MPI_COMM_WORLD);
  }
  else if (rank == 1) {
    char hello[256];
    MPI_Recv(hello, _countof(hello), MPI_CHAR, 0, 0, MPI_COMM_WORLD, MPI_STATUSES_IGNORE);
    printf("Rank 1 received string `%s' from Rank 0.\n", hello);
  }

  MPI_Finalize();
  return 0;
}
