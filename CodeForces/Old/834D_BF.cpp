using namespace std;
#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define FOD(i, b, a) for (int i = b; i >= a; i--)

int left(int p) {return p*2;}
int right(int p) {return p*2+1;}

const int N = 35e4 + 10;
const int K = 55;
int a[N], f[K][N];
int n, k;

int numDiff(int l, int r) {
    set<int> data;
    for (int i = l; i <= r; i++) data.insert(a[i]);
    return data.size();
}

int main() {
    //freopen("","r",stdin);
    //freopen("","w",stdout);
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);

    for (int i = 1; i <= k; i++)
    for (int j = 1; j <= n; j++) {
        int t = 0;
        for (int k = 0; k < j; k++) t = max(t, f[i][k] + numDiff(k+1, j));
    }

    printf("%d", f[k][n]);
    return 0;
}
/**/
