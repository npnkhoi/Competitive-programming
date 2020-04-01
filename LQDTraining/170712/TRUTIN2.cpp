using namespace std;
#include <stdio.h>
#include <set>
#include <cstring>

typedef pair<int, int> ii;

const int N = 1e3 + 10;
const int K = 210;

char str[N][K];
int c[N][N], s[N], pre[N], ans[N];
int res;
set<ii> data;

int main() {
    int n, k;
    scanf("%d %d\n", &n, &k);
    for (int i = 1; i <= n; i++) scanf("%s", &str[i]);
    for (int i = 1; i < n; i++)
    for (int j = i+1; j <= n; j++) {
        int t = 0;
        for (int x = 0; x < k; x ++) t += (str[i][x] != str[j][x]);
        c[i][j] = c[j][i] = min(k, t << 1);
        s[i] += c[i][j]; s[j] += c[i][j];
        //printf("%d %d: %d\n", i, j, c[i][j]);
    }

    for (int i = 1; i <= n; i++) data.insert(ii(s[i], i)), printf("%d %d\n", i, s[i]);

    set<ii>::iterator it;
    //for (it = data.begin(); it != data.end(); it++) printf("%d ", *it); printf("\n");

    for (int i = 1; i <= n; i++) {
        int a = data.begin() -> first;
        int b = data.begin() -> second;
        //printf("%d\n",b);

        data.erase(data.begin());
        ans[i] = b; s[b] = -1;

        for (int j = 1; j <= n; j++) if (s[j] != -1)
        {
            data.erase(ii(s[j], j));
            s[j] -= c[b][j];
            data.insert(ii(s[j], j));
        }
        //for (it = data.begin(); it != data.end(); it++) printf("%d ", *it); printf("\n");
    }
    pre[1] = 0; res = k;
    for (int i = 2; i <= n; i++) {
        int t = k, p = 0;
        for (int j = 1; j < i; j++) if (c[ans[j]][ans[i]] < t)
            t = c[ans[j]][ans[i]], pre[i] = ans[j];
        res += t;
    }
    printf("%d\n", res);
    for (int i = 1; i <= n; i++) printf("%d %d\n",  ans[i], pre[i]);

}
