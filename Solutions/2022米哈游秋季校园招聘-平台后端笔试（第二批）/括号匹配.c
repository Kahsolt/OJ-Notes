#include <stdio.h>
#include <string.h>
#define MAXLEN 1000

/*
2
{[][}}
[][]{{]]
*/

char s[MAXLEN+1];
int dp[MAXLEN+1][MAXLEN+1] = { 0 };     // s[i:j]需要多少次修改才能成为合法序列

static inline int min(int a, int b, int c) {
    if (b < a) a = b;
    if (c < a) a = c; 
    return a;
}

int main() {
    int T; scanf("%d", &T); getchar();
    while (T--) {
        scanf("%s", s); getchar();
        puts(s);
        memset(dp, 0x30, sizeof(dp));
        int len = strlen(s);

        for (int i=0; i<=len; i++)
            dp[0][i] = dp[i][0] = i, dp[i][i] = 0;
        for (int i=1; i<len; i++)
            for (int j=i; j<=len; j++)
                if (i+1 < j-1 && s[i+1] == '{' && s[j-1] == '}' || s[i+1] == '[' && s[j-1] == ']')
                    dp[i][j] == dp[i-1][j-1];
                else
                    dp[i][j] = min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]) + 1;

        for (int i=0; i<len; i++) {
            for (int j=i+1; j<=len; j++)
                printf(" %d", dp[i][j]);
            putchar(10);
        }

        printf("ans=%d\n", dp[1][len]);
    }
}