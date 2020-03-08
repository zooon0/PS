#include <bits/stdc++.h>
#define isIN(x, a, b) (((x) >= (a) && (x) < (b))? true : false)

using namespace std;

int ans;
void solve(int gameBoard[20][20], int H, int W, int blank);

int main()
{
    int C, H, W;
    scanf("%d", &C);
    for (int testCase = 0; testCase < C; testCase++)
    {
		// init 
		ans = 0;
        int gameBoard[20][20];
        for (int i = 0; i < 20; i++)
            for (int j = 0; j < 20; j++)
                gameBoard[i][j] = -1;
        // get input
        scanf("%d %d", &H, &W);
        char temp;
        for (int i = 0; i < H; i++)
        {
            for (int j = 0; j < W; j++)
            {
                scanf("%c", &temp);
                if (temp == '#')
                    gameBoard[i][j] = 1;
                else
                    gameBoard[i][j] = 0;
            }
            if (i != H - 1)
                getchar();
        }

        printf("INPUT CHECK\n");
        for (size_t i = 0; i < H; i++)
        {
            for (size_t j = 0; j < W; j++)
            {
                printf("%c", (gameBoard[i][j] == 1 ? '#' : '.'));
            }
            putchar('\n');
        }
        

        /*
        int blank = 0;
        for (int i = 0; i < H; i++)
            for (int j = 0; j < W; j++)
                if (gameBoard[i][j] == 0)
                    blank++;
        if (blank % 3 != 0)
        {
            printf("0\n");
            continue;
        }
		else 
		{
        	solve(gameBoard, H, W, blank);
			printf("%d", ans / (2 * blank));
		}
        */
    }
}

void solve(int gameBoard[20][20], int H, int W, int blank)
{
	if (blank == 0)
	{
		ans++;
		return;
	}

	else
	{
		for (int i = 0; i < H; i++) 
		{
			for (int j = 0; j < W; j++) 
			{
				if (gameBoard[i][j] == 0)		
				{
					// fill 3 block of gameboard
                    for (int k = 0; k < 4; k++)
                    {
                        switch (k)
                        {
                        case 0: // right 
                            if (isIN((i + 1), 0, H) && gameBoard[i + 1][j] == 0)
                            {
                                if (isIN((j + 1), 0, W) && gameBoard[i + 1][j + 1] == 0)
                                {
                                    gameBoard[i][j] = 1;
                                    gameBoard[i + 1][j] = 1;
                                    gameBoard[i + 1][j + 1] = 1;
                                    solve(gameBoard, H, W, blank + 3);
                                    gameBoard[i][j] = 0;
                                    gameBoard[i + 1][j] = 0;
                                    gameBoard[i + 1][j + 1] = 0;
                                }
                                if (isIN((j - 1), 0, W) && gameBoard[i + 1][j - 1] == 0)
                                {
                                    gameBoard[i][j] = 1;
                                    gameBoard[i + 1][j] = 1;
                                    gameBoard[i + 1][j - 1] = 1;
                                    solve(gameBoard, H, W, blank + 3);
                                    gameBoard[i][j] = 0;
                                    gameBoard[i + 1][j] = 0;
                                    gameBoard[i + 1][j - 1] = 0;
                                }
                            }
                            break;
                        
                        case 1:
                            if (isIN((i - 1), 0, H) && gameBoard[i - 1][j] == 0)
                            {
                                if (isIN((j + 1), 0, W) && gameBoard[i - 1][j + 1] == 0)
                                {
                                    gameBoard[i][j] = 1;
                                    gameBoard[i - 1][j] = 1;
                                    gameBoard[i - 1][j + 1] = 1;
                                    solve(gameBoard, H, W, blank + 3);
                                    gameBoard[i][j] = 0;
                                    gameBoard[i - 1][j] = 0;
                                    gameBoard[i - 1][j + 1] = 0;
                                }
                                if (isIN((j - 1), 0, W) && gameBoard[i - 1][j - 1] == 0)
                                {
                                    gameBoard[i][j] = 1;
                                    gameBoard[i - 1][j] = 1;
                                    gameBoard[i - 1][j - 1] = 1;
                                    solve(gameBoard, H, W, blank + 3);
                                    gameBoard[i][j] = 0;
                                    gameBoard[i - 1][j] = 0;
                                    gameBoard[i - 1][j - 1] = 0;
                                }
                            }
                            break;

                        case 2:
                            if (isIN((j + 1), 0, W) && gameBoard[i][j + 1] == 0)
                            {
                                if (isIN((i + 1), 0, H) && gameBoard[i + 1][j + 1] == 0)
                                {
                                    gameBoard[i][j] = 1;
                                    gameBoard[i][j + 1] = 1;
                                    gameBoard[i + 1][j + 1] = 1;
                                    solve(gameBoard, H, W, blank + 3);
                                    gameBoard[i][j] = 0;
                                    gameBoard[i][j + 1] = 0;
                                    gameBoard[i + 1][j + 1] = 0;
                                }
                                if (isIN((i - 1), 0, H) && gameBoard[i - 1][j + 1] == 0)
                                {
                                    gameBoard[i][j] = 1;
                                    gameBoard[i][j + 1] = 1;
                                    gameBoard[i - 1][j + 1] = 1;
                                    solve(gameBoard, H, W, blank + 3);
                                    gameBoard[i][j] = 0;
                                    gameBoard[i][j + 1] = 0;
                                    gameBoard[i - 1][j + 1] = 0;
                                }
                            }
                            break;

                        case 3:
                            if (isIN((j - 1), 0, W) && gameBoard[i][j - 1] == 0)
                            {
                                if (isIN((i + 1), 0, H) && gameBoard[i + 1][j - 1] == 0)
                                {
                                    gameBoard[i][j] = 1;
                                    gameBoard[i][j - 1] = 1;
                                    gameBoard[i + 1][j - 1] = 1;
                                    solve(gameBoard, H, W, blank + 3);
                                    gameBoard[i][j] = 0;
                                    gameBoard[i][j - 1] = 0;
                                    gameBoard[i + 1][j - 1] = 0;
                                }
                                if (isIN((i - 1), 0, H) && gameBoard[i - 1][j - 1] == 0)
                                {
                                    gameBoard[i][j] = 1;
                                    gameBoard[i][j - 1] = 1;
                                    gameBoard[i - 1][j - 1] = 1;
                                    solve(gameBoard, H, W, blank + 3);
                                    gameBoard[i][j] = 0;
                                    gameBoard[i][j - 1] = 0;
                                    gameBoard[i - 1][j - 1] = 0;
                                }
                            }
                            break;
                        
                        default:
                            break;
                        }
                    }
					// solve(gameBoard, H, W, blank + 3);
                    //
                    // restore gameboard
            
				}
			}
		}	
	}
}
