// C++ program to demonstrate
// the use of rand()
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // This program will create same sequence of
    // random numbers on every program run
    srand(time(0));
    for (int i = 0; i < 5; i++)
    {
        printf("%d\t", rand());
    }

    return 0;
}
