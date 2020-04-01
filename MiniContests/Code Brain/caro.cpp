using namespace std;

#include <bits/stdc++.h>

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define For(i, a, b) for (int i = a; i <= b; i++)
#define F0r(i, b, a) for (int i = b; i >= a; i--)

typedef pair<int, int> ii;
typedef vector<int> vi;
char a[4][4];
int tc;
using namespace std;
bool win(char ch) {
    if (a[1][1] == ch && a[1][2] == ch && a[1][3] == ch) return 1;
    if (a[2][1] == ch && a[2][2] == ch && a[2][3] == ch) return 1;
    if (a[3][1] == ch && a[3][2] == ch && a[3][3] == ch) return 1;
    if (a[1][1] == ch && a[2][1] == ch && a[3][1] == ch) return 1;
    if (a[1][2] == ch && a[2][2] == ch && a[3][2] == ch) return 1;
    if (a[1][3] == ch && a[2][3] == ch && a[3][3] == ch) return 1;
    if (a[1][1] == ch && a[2][2] == ch && a[3][3] == ch) return 1;
    if (a[1][3] == ch && a[2][2] == ch && a[3][1] == ch) return 1;
    return 0;
}
int main()
{
    //freopen("","r",stdin);
    //freopen("","w",stdout);
    scanf("%d", &tc);
    for (int z = 1; z <= tc; z++) {
        printf("Game #%d:\n", z);
        for (int i = 1; i <= 3; i++)
        for (int j = 1; j <= 3; j++) scanf(" %c", &a[i][j]);
        if (win('X') && (!win('O'))) printf("Nobita! X wins!\n\n");
        else if (win('O') && (!win('X'))) printf("Doraemon! O wins!\n\n");
        else printf("Draw game!\n\n");
    }
    return 0;
}
/**/
