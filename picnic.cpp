#include <bits/stdc++.h>

int possibleCase;

int factorial(int n)
{
    int x = 1;
    for (size_t i = 0; i < n; i++)
        x *= (i + 1);
    return x;
}
void generateAllCase(int n, std::vector<std::pair<int, int>> &isFriend, std::list<int> &numList);
int main()
{
    int numberOfTestCase;
    int n, m;
    scanf("%d", &numberOfTestCase);
    for (int index = 0; index < numberOfTestCase; ++index)
    {
        possibleCase = 0;
        std::vector<std::pair<int, int>> isFriend(0, std::pair<int, int>(0, 0));
        std::list<int> numList(0, 0);
        int x, y;
        scanf("%d%d", &n, &m);
        for (int j = 0; j < m; ++j)
        {
            scanf("%d%d", &x, &y);
            isFriend.emplace_back(x, y);
        }
        for (int i = 0; i < n; ++i)
            numList.push_back(i);
        for (auto &i : isFriend)
        {
            if (i.first > i.second)
            {
                int temp = i.first;
                i.first = i.second;
                i.second = temp;
            }
        }
        std::sort(isFriend.begin(), isFriend.end(), [](const std::pair<int, int> &lhs, const std::pair<int, int> &rhs) {
            return (lhs.first < rhs.first ? true : (lhs.second < rhs.second));
        });
        std::cout << "List IS: ";
        for (auto &p : numList)
            std::cout << p << " ";
        std::cout << std::endl;
		std::cout << "Friend List Is: ";
		for (auto &k : isFriend)	
			std::cout << k.first << " " << k.second << "|";
		std::cout << std::endl;
        generateAllCase(n, isFriend, numList);

        printf("%d\n", possibleCase / factorial(n / 2));
    }
    return 0;
}

void generateAllCase(int n, std::vector<std::pair<int, int>> &isFriend, std::list<int> &numList)
{
    std::vector<std::pair<int, int>>::iterator isFriendIter;
    if (n == 0)
    {
        possibleCase++;
        return;
    }
    else
    {
        for (std::list<int>::iterator i = numList.begin(); i != numList.end(); ++i)
        {
            for (std::list<int>::iterator j = std::next(i, 1); j != numList.end(); ++j)
            {
                isFriendIter = std::find(isFriend.begin(), isFriend.end(), std::pair<int, int>(*i, *j));
                if (isFriendIter != isFriend.end())
                {
                    int tempI = *i;
                    int tempJ = *j;
                    i = numList.erase(i);
                    j = numList.erase(j);
                    generateAllCase(n - 2, isFriend, numList);
                    std::cout << "i: " << tempI << " j: " << tempJ << std::endl;
                    std::cout << "List IS: ";
                    for (auto &p : numList)
                        std::cout << p << " ";
                    std::cout << std::endl;
                    numList.insert(j, tempJ);
                    numList.insert(i, tempI);
                    i--;
                    j--;
                }
            }
        }
        return;
    }
}
