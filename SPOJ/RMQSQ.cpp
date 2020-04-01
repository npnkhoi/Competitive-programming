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

const int N = 1e5 + 10;
const int logN = 64;
int a[N], spT[N][logN], n, oo;

void build() {
    for (int i = n-1; i >= 0; i--) {
        spT[i][0] = a[i];
        for (int j = 1; (1<<j) <= n-i+1; j++)
        spT[i][j] = min(spT[i][j-1], spT[i + (1<<(j-1))][j-1]);
    }
}
int rmq(int l, int r) {
    int k = int(floor(log(double(r-l+1))/log(2.0)));
    //printf("rmq -> %d, %d    %d, %d\n", l, k, r-(1<<k), k);
    return min(spT[l][k], spT[r-(1<<k)+1][k]);
}
int main() {
    //freopen("rmqsq.inp","r",stdin);
    //freopen("rmqsq.out","w",stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        //oo = max(oo, a[i]);
    }
    build();
    /*for (int i = 0; i < n; i++) {
        for (int j = 0; j < log2(n); j++) printf("%d ", spT[i][j]);
        cout << endl;
    }*/
    int q;
    scanf("%d", &q);
    while (q--) {
        int u, v;
        scanf("%d %d", &u, &v);
        printf("%d\n", rmq(u, v));
    }
    return 0;
}
/**/
