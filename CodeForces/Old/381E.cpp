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

const int N = 1e5 + 10;
int n;
int ft[N], a[N], p[N], IT[4*N];

int LSOne(int x)
{
    return x&(-x);
}
void adjust(int pos, int val)
{
    for (; pos <= n; pos+= LSOne(pos)) ft[pos]+=val;
}
int rsq(int b)
{
    int s = 0;
    for (; b > 0; b -= LSOne(b)) s+=ft[b];
    return s;
}
int rsq(int a, int b)
{
    return rsq(b) - rsq(a-1);
}

int left(int x) { return x<<1; }
int right(int x) { return (x<<1) + 1; }

void build(int p, int l, int r)
{
    if (l==r) IT[p] = l;
    else
    {
        build(left(p), l, (l+r) / 2);
        build(right(p), (l+r) / 2 + 1, r);
        int p1 = IT[left(p)], p2 = IT[right(p)];
        IT[p] = (a[p1] <= a[p2]) ? p1 : p2;
    }
}

int rmin(int p, int l, int r, int L, int R)
{
    if (l>R || r<L) return -1;
    if (L<=l && r<=R) return IT[p];

    int p1 = rmin(left(p), l, (l+r) / 2, L, R);
    int p2 = rmin(right(p), (l+r) /2 +1, r, L, R);
    if (p1 == -1) return p2;
    if (p2 == -1) return p1;
    return (a[p1] <= a[p2]) ? p1 : p2;
}

void update(int p, int l, int r, int i, int v)
{
    if (i<l || r<i) return;
	if (v<IT[p]) IT[p] = i;

    if (l==r) return;
    int mid = (l+r)/2;

    if (i <= (l+r)/2)
    	update(left(p), l, mid, i,v);
    else update(right(p),mid+1, r, i, v);
}

int main()
{
    //freopen("","r",stdin);
    //freopen("","w",stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);

    build(1, 1, n);
    for (int i = 1; i <= n; i++) adjust(i, 1);

    long long res = 0;
    int cur = 0;

    for (int x = 1; x <= n; x++) {
        int pr = rmin(1, 1, n, cur +1, n);
        int pl = rmin(1, 1, n, 1 ,cur -1);
        if (a[pr] > a[pl]) pr = pl;

        if (pr > cur) {
            res += rsq(cur + 1, pr);
            cur = pr;
            adjust(cur, -1);
            update(1, 1, n, cur, 10000000);
        }
            else {
                res += rsq(cur + 1, n) + rsq(1 , pr);
                cur = pr;
                adjust(cur, -1);
                update(1, 1, n, cur, 10000000);
            }
    }
    cout << res;

    return 0;
}
/**/
