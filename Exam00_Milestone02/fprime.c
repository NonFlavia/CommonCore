#include <stdio.h>
#include <stdlib.h>

/*
we need to find all the prime numbers that make up the int
given as an argument. we can use atoi(), so converting argv to an int is easier.

we create an int variable called `todiv`, starting from the first prime number after 1 (2).

if `n % todiv == 0`,
we know that `todiv` is one of the prime factors, so we print it.
then we divide `n` by `todiv`, store the result back into `n`,
and continue the loop.
if `n` is still greater than 1, we print our beloved "*".
if `todiv` doesn't divide `n`, we just try the next number.
*/


void fprime(int n)
{
    int todiv;
    todiv = 2;
    if (n <= 0)
        return;
    if (n == 1)
    {
        printf("1");
        return;
    }
    else
    {
        while (n > 1)
        {
            if (n % todiv == 0)
            {
                printf("%d", todiv);
                n = n / todiv;
                if (n > 1)
                    printf("*");
            }
            else 
                todiv++;
            
        }
    }
}

int main(int argc, char **argv)
{
    int nb;
    if (argc != 2)
        printf("\n");
    else
    {
        nb = atoi((const char *)argv[1]);
        fprime(nb);
        printf("\n");
    }
    return(0);
}