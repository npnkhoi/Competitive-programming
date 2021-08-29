using namespace std;
#include <stdio.h>
#include <iostream>
#include <vector>
#include <string.h>
const int N = 1e5 + 50;
int n;
vector<int> pos[N];
bool v[N];
int a[2][N];
int _min;
string ways;
void x2()
{
    int r = 0;
    for (int i = ways.size()-1; i >= 0; i--)
    {
        int t = r + 2*(ways[i]-'0');
        r = t/10;
        ways[i] = (char) (t%10 + '0');
    }
    if (r) ways = "1" + ways;
}
int main()
{
    freopen("swapgame.inp","r",stdin);
    freopen("swapgame.out","w",stdout);
    scanf("%d", &n);
    for (int i = 0; i <= 1; i++)
        for (int j = 1; j <= n;j++)
    {
        scanf("%d",&a[i][j]);
        pos[a[i][j]].push_back(j);
    }
    //for (int i = 1; i <= n; i++) cout << pos[i][0] << " " << pos[i][1] << endl;
    memset(v, 0, sizeof(v));
    ways = "1";
    for (int i = 1; i <= n; i++) if (!v[i])
    {
        //cout << "try " << i << endl;
        int j = i, x = a[0][i],
        _size = 0, cnt = 0;
        while (!v[j])
        {
            _size ++;
            v[j] = 1;
            if (pos[x][0] != j) j = pos[x][0];
                else j = pos[x][1];
            if (a[0][j] != x) x = a[0][j];
                else x = a[1][j], cnt++;
        }
        //cout << _size << " " << cnt << endl;
        if (_size > 1) x2();
        _min += min(cnt, _size-cnt);
    }
    cout << ways << endl << _min << endl;
}
