#include <iostream>
#include <vector>

using namespace std;

void solve(int tc[]);

int main()
{
    int C;
    int tc[16];
    cin >> C;
    for (int _count = 0; _count < C; _count++)
    {
        for (int i = 0; i < 16; ++i)
            cin >> tc[i];
        solve(tc);
    }
    return 0;
}

int solve(int tc[])
{
    int ans = 0;
    /* 0 = 0, 3, 5
     * 1 = 0, 8
     * 2 = 0, 5, 8
     * 3 = 1, 6, 8, 9
     * 4 = 2, 7, 9
     * 5 = 3, 7, 8, 9
     * 6 = 3, 4
     * 7 = 1, 3, 7
     * 8 = 4
     * 9 = 1, 9
     * 10 = 2, 4
     * 11 = 1
     * 12 = 4
     * 13 = 9
     * 14 = 2, 5, 6, 7
     * 15 = 2, 5, 7
     */
    for (auto i : {8, 11, 12, 13})
        while (tc[i] % 4 == 0)
        {
        }
    return ans;
}
