#include <stdio.h>
#include <iostream>
#include <string.h>
#include <math.h>
#include <algorithm>

using namespace std;

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

const int MAX = 1010;

int m, n;
int a[MAX][MAX];

void start(){
	scanf("%d%d",&m,&n);
	for (int i=1;i<=m;i++)
		for (int j=1;j<=n;j++)
        {
            char ch;
            scanf(" %c",&ch);
            a[i][j]=(ch-'0');
        }
    /*cout<<m<<" "<<n<<endl;
    for (int i=1;i<=m;i++)
    {
        for (int j=1;j<=n;j++) cerr<<a[i][j]<<" ";
        cerr<<endl;

    }
*/

}

int cnt = 0;

bool kt[MAX][MAX];

void flood(int u, int v) {
	cnt++;
	kt[u][v] = 0;
	for (int i = 0; i < 4; i++) {
	 	int x = u+dx[i], y = v+dy[i];
		if (x > 0 && x <= m && y > 0 && y <= n && kt[x][y] && a[x][y] == 1) {
			flood(x, y);
		}
	}

}

int main()
{
    freopen("CHUOT.inp","r",stdin);
    //freopen("CHUOT.out","w",stdout);
	start();
	int res = 0;
	for (int i=1;i<=m;i++)
        for (int j=1;j<=n;j++) kt[i][j]=1;
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			if (kt[i][j] && a[i][j] == 1) {
				cnt = 0;
				flood(i, j);
				res = max( res, cnt );
			}
		}
	}

	printf("%d", res);

	return 0;

}
