#include <iostream>

using namespace std;

int Sum_Solution(int n) 
{
    int result = 0;
    n == 0 || (result = Sum_Solution(n-1))
    return n+result;
}

int main()
{
    
    return 0;
}