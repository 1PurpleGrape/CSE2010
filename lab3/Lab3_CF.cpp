#include <iostream>
#include <cstdlib>
using namespace std;
int main()
{
    int x = 0;
    int y = 5;
    while(x < y){
        printf("%i\n",x);
        x += 3;
    }
    if(x % 2==0)
    {
        printf("x is even");
    }
    else{
        printf("x is even");

    }
    return 0;

}