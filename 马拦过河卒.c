#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//假设棋盘最多25*25格
int ban[25][25] = { 0 };
long long dp[25][25] = { 0 };

// 马八个跳跃方向偏移量
int dx[] = { 2, 1, -1, -2, -2, -1, 1, 2 };
int dy[] = { 1, 2, 2, 1, -1, -2, -2, -1 };

int main()
{
    int n, m, hx, hy;
    scanf("%d %d %d %d", &n, &m, &hx, &hy);

    ban[hx][hy] = 1;
    for (int i = 0; i < 8; i++)
    {
        int x = hx + dx[i];
        int y = hy + dy[i];
        if (x >= 0 && x <= 20 && y >= 0 && y <= 20)
        {
            ban[x][y] = 1;
        }
    }

    dp[0][0] = 1;

    for (int j = 1; j <= m; j++)
    {
        if (ban[0][j])
            dp[0][j] = 0;
        else
            dp[0][j] = dp[0][j - 1];
    }

    for (int i = 1; i <= n; i++)
    {
        if (ban[i][0])
            dp[i][0] = 0;
        else
            dp[i][0] = dp[i - 1][0];
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (ban[i][j])
                dp[i][j] = 0;
            else
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }

    printf("%lld", dp[n][m]);
    return 0;
}