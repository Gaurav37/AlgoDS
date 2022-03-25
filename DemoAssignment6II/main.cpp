#include<iostream>
#include<time.h>
using namespace std;


int init_array[100];//taken max numbers as 99

/* Function to initialize NIL
values in lookup table */
void first_call_set()
{
    int i;
    for (i = 0; i < 100; i++)
        init_array[i] = -1;
}

/* function for nth Fibonacci number */
int fibonacci(int n)
{
    if(n<=1)
        return n;

    return fibonacci(n-1)+fibonacci(n-2);
}

int fibDynamic(int n)
{
    if (init_array[n] == -1)
    {
        if (n <= 1)
            init_array[n] = n;
        else
            init_array[n] = fibDynamic(n - 1) + fibDynamic(n - 2);
    }

    return init_array[n];
}

// Driver code
int main ()
{
    int n;

    std::cout<<"Enter a number";
    std::cin>>n;
    first_call_set();
    clock_t time_req = clock();
    std::cout<< "Fibonacci number is " << fibDynamic(n-1);
    time_req=clock()-time_req;
    std::cout<<"time taken by dynamic method:"<<(long(time_req))*1000000/CLOCKS_PER_SEC;
    std::cout<<"fibonnacii number by rec is"<< fibonacci(n-1)<<std::endl;
    time_req=clock()-time_req;
    std::cout<<"time taken by recursive method:"<<(float(time_req))/CLOCKS_PER_SEC;

    for(int a=0;a<100;a++){
        std::cout<<init_array[a]<<std::endl;
    }
    return 0;
}
