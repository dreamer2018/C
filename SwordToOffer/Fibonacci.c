#include<stdio.h>
long Fibonacci(int n)
{
    if(n < 0)
    {
        return -1;
    }
    else if(n == 0)
    {
        return 0;
    }
    if(n==1 || n == 2)
    {
        return 1;
    }
    int i=3;
    long f1=1,f2=1,fn;
    while(i<=n)
    {
        fn=f1+f2;
        f1=f2;
        f2=fn;
        i++;
    }
    return fn;
}
int main(int argc, void * argv)
{
    printf("%d\n", Fibonacci(10);
}
