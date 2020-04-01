using namespace std;
#include <stdio.h>
#include <algorithm>
#include <queue>
#include <string.h>

typedef pair<int, int> ii;
const int N = 105;
int a[N][N];
bool sign[N][N];
int even, odd;
int ways;
vector <int> dx, dy;
int r, c, m, n;
queue<ii > q;

/*void update(int u, int v) {
    //printf("%d %d\n", u, v);
    sign[u][v] = 1;
    if (a[u][v]%2) odd ++;
    else even ++;
    q.push(ii(u, v));
}*/

void update(int x, int y) {
    //printf("%d %d\n", x, y);
    sign[x][y] = 1; q.push(ii(x, y));

    int s = 0;
    for (int z = 0; z < ways; z++) {
        int u = x + dx[z], v = y + dy[z];
        if (u >= 0 && v >= 0 && u < r && v < c && a[u][v] == 0) s++;
    }
    if (s%2) odd ++;
    else even ++;
}

int main() {
    //freopen("test.inp", "r", stdin);
    //freopen("test.out", "w", stdout);
    int tc;
    scanf("%d", &tc);
    for (int TC = 1; TC <= tc; TC++) {

        scanf("%d %d %d %d", &r, &c, &m ,&n);
        dx.clear(); dy.clear();
        m = abs(m); n = abs(n);
        dx.push_back(m); dy.push_back(n);
        if (m!=0) dx.push_back(-m), dy.push_back(n);
        if (n!=0) dx.push_back(m), dy.push_back(-n);
        if (m!=0 && n !=0) dx.push_back(-m), dy.push_back(-n);

        if (m != n) {
            swap(m, n);
            dx.push_back(m); dy.push_back(n);
            if (m!=0) dx.push_back(-m), dy.push_back(n);
            if (n!=0) dx.push_back(m), dy.push_back(-n);
            if (m!=0 && n !=0) dx.push_back(-m), dy.push_back(-n);
        }
        ways = dx.size();

        //for (int i = 0; i < ways; i++) printf("%d ", dx[i]); printf("\n");
        //for (int i = 0; i < ways; i++) printf("%d ", dy[i]); printf("\n");
        /*for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
        if (i-n >= 0 && i+n < r && j-n >= 0 && j+n < c) a[i][j] = ways;
        else {
            int s = 0;
            for (int z = 0; z < ways; z++) {
                int u = i + dx[z], v = j + dy[z];
                if (u >= 0 && v >= 0 && u < r && v < c) s ++;
            }
            a[i][j] = s;
        }
        int _q;
        scanf("%d", &_q);
        while (_q --) {
            int x, y;
            scanf("%d %d", &x, &y);
            a[x][y] = -1;
            for (int z = 0; z < ways; z++) {
                int u = x + dx[z], v = y + dy[z];
                if (u >= 0 && v >= 0 && u < r && v < c) a[u][v] --;
            }
        }

        for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
        if (a[i][j] > 0)
        if (a[i][j]%2) odd ++;
        else even++;*/

        memset(a, 0, sizeof a);
        int _q;
        scanf("%d", &_q);
        while (_q --) {
            int x, y;
            scanf("%d %d", &x, &y);
            a[x][y] = -1;
        }

        memset(sign, 0, sizeof sign);
        even = odd = 0;
        if (a[0][0] == 0) update(0, 0);

        while (!q.empty()) {
            ii fr = q.front(); q.pop();
            for (int z = 0; z <ways; z++) {
                int u = fr.first + dx[z], v = fr.second + dy[z];
                //printf("%d %d\n", u, v);
                if (u >= 0 && v >= 0 && u < r && v < c && a[u][v] == 0 && sign[u][v] == 0)
                    update(u, v);
            }
        }

        printf("Case %d: %d %d\n", TC, even, odd);
    }
}
