using namespace std;
#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
typedef pair<int, int> ii;
typedef vector<int> vi;
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define FOD(i, b, a) for (int i = b; i >= a; i--)

const int N = 35e4 + 10;
const int K = 55;
const int oo = 1e9 + 17;
int a[N], pos[N], f[K][N];
int n, k;

#define typeIT int
struct node{
    typeIT val, lazy; /// change type here
} node IT[4*N];

void build(node IT[], int p, typeIT a[], int l, int r) {
    IT[p].lazy = 0;
    if (l == r) IT[p].val = a[l];
    else {
        int mid = (l+r)/2;
        build(IT,   2*p,    a,  l,      mid);
        build(IT,   2*p+1,  a,  mid+1,  r);
        IT[p].val = max(IT[2*p].val, IT[2*p+1].val);
    }
}

void lazyDown(node IT[], int p) {
    if (2*p+1 >= 4*N) return;   /// notice about N

    IT[2*p].lazy += IT[p].lazy;
    IT[2*p+1].lazy += IT[p].lazy;
    IT[2*p].val += IT[p].lazy;
    IT[2*p+1].val += IT[p].lazy;

    IT[p].lazy = 0;
}

void update(node IT[], int p, int l, int r, int L, int R, typeIT val) {
    if (r < L || R < l || r < l || R < L) return;
    lazyDown(IT, p);
    if (L <= l && r <= R) {
        IT[p].lazy += val;
        IT[p].val += val;
        return;
    }
    int mid = (l+r)/2;
    update(IT, 2*p, l, mid, L, R, val);
    update(IT, 2*p+1, mid+1, r, L, R, val);
    IT[p].val = max(IT[2*p].val, IT[2*p+1].val);
}

typeIT rmq(node IT[], int p, int l, int r, int L, int R) {
    if (r < L || R < l || r < l || R < L) return 0; /// max -> ZERO ; min -> INF
    lazyDown(IT, p);
    if (L <= l && r <= R) return IT[p].val;
    else {
        int mid = (l+r)/2;
        return max(
            rmq(IT, 2*p, l, mid, L, R), rmq(IT, 2*p+1, mid+1, r, L, R));
    }
}

int main() {
    //freopen("","r",stdin);
    //freopen("","w",stdout);
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);

    for (int i = 1; i <= k; i++) {
        build(IT, 1, f[i-1], 0, n-1);
        memset(pos, 0, sizeof pos);
        for (int j = 1; j <= n; j++) {
            update(IT, 1, 0, n-1, pos[a[j]], j-1, 1);
            //for (int i = 1; i <= 4*n; i++) cout << IT[i] << " \n"[i == 4*n];
            f[i][j] = rmq(IT, 1, 0, n-1, 0, j-1);
            pos[a[j]] = j;
        }
    }
    //for (int i = 0; i <= k; i++)
    //for (int j = 1; j <= n; j++) cout << f[i][j] << " \n"[j == n];


    printf("%d", f[k][n]);
    return 0;
}
/**/
