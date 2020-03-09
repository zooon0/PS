#include <bits/stdc++.h>

using namespace std;

bool hasWord(int x, int y, char *word, char gameBoard[5][5], int position);

int main()
{
    char gameBoard[5][5];
    char word[11];
    int numberOfWord;
    int numberOfTestCase;
    scanf("%d\n", &numberOfTestCase);
    for (int i = 0; i < numberOfTestCase; ++i)
    {
        // get Input
        for (int j = 0; j < 5; ++j)
        {
            scanf("%s", gameBoard[j]);
        }

        scanf("%d", &numberOfWord);

        for (int l = 0; l < numberOfWord; l++)
        {
            bool counter = false;
            for (int t = 0; t < 11; t++)
                word[t] = '\0';
            scanf("%s", word);
            for (int j = 0; j < 5; ++j)
                for (int k = 0; k < 5; ++k)
                {
                    counter = hasWord(j, k, word, gameBoard, 0);
                    if (counter)
                        goto RETPOINT;
                }
        RETPOINT:
            if (counter)
                printf("%s YES\n", word);
            else
                printf("%s NO\n", word);
        }
    }
    return 0;
}

bool hasWord(int y, int x, char *word, char gameBoard[5][5], int position)
{
    bool counter = false;
    if (word[position] == gameBoard[y][x])
    {
        if (position + 1 == strlen(word))
            return true;
        else
        {
            for (int i = -1; i < 2; ++i)
                for (int j = -1; j < 2; ++j)
                {
                    if ((y + i < 0) || (x + j < 0) || (y + i > 4) || (x + j > 4) || ((i == 0) && (j == 0)))
                        continue;
                    else
                    {
                        counter = hasWord(y + i, x + j, word, gameBoard, position + 1);
                        if (counter)
                            return true;
                    }
                }
            return counter;
        }
    }
    else
        return false;
}