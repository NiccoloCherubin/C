#include <stdio.h>
#include <pthread.h>

#define DIM 64
#define N 16

struct BUFFER
{
    unsigned char buffer[DIM];
    int n;
};

struct BUFFER ring_buffer[N];

