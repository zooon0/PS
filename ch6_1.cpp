#include <iostream>
#include <vector>

using std::cout;
using std::cin;
using std::vector;

int sum(int);

int main(void)
{
    cout << sum(10);
}

int sum(int n)
{
    if (n == 1)
        return 1;
    else
        return n + sum(n - 1);
}