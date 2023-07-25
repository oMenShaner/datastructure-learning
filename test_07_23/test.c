#include<stdio.h>

long long Fib(int N)
{
    if (N <= 1)                     //1
        return 1;                   //2    
    else                                
        return Fib(N-1) + Fib(N-2); //3
}

int main(void)
{
	Fib(5);

	return 0;
}
