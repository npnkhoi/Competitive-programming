#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define REP(i,n) for (int i = 0; i < n; ++ i)
#define FOR(i,a,b) for (int i = a; i <= b; ++ i)
#define FORD(i,b,a) for (int i = b; i >= a; -- i)
#define task "btn4"
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ll, int> li;
typedef vector<int> vi;
struct Node{
    int l, r, sum, minSum, maxSum, lazy;
};
struct pack{
    int minSum, maxSum, sum;
};
pack foo;

const int N = 3e5 + 5;
Node IT[8*N];
int n, q;
char s[N];

void build(int p, int l, int r) {
    IT[p].l = l;
    IT[p].r = r;
    if (l < r) {
        int mid = (l + r) / 2 + 1;
        build(2*p, l, mid - 1);
        build(2*p + 1, mid, r);
        IT[p].sum = IT[2*p].sum + IT[2*p+1].sum;
        IT[p].minSum = min(IT[2*p].minSum, IT[2*p].sum + IT[2*p+1].minSum);
        IT[p].maxSum = max(IT[2*p].maxSum, IT[2*p].sum + IT[2*p+1].maxSum);
    } else {
        int tmp;
        if (s[l] == '(') tmp = 1;
        else tmp = -1;
        IT[p].sum = tmp;
        IT[p].minSum = min(0, tmp);
        IT[p].maxSum = max(0, tmp);
    }
    //cerr << p << " " << l << " " << r << " " << IT[p].sum << " " << IT[p].minSum << " " << IT[p].maxSum << "\n";
}
void show(int p, int l, int r) {
    cerr << p << " " << l << " " << r << " " <<
    IT[p].sum << " " << IT[p].minSum << " " << IT[p].maxSum << " " << IT[p].lazy << "\n";
    if (l < r) {
        int mid = (l + r) / 2 + 1;
        show(2*p, l, mid-1);
        show(2*p+1, mid, r);
    }
}
void lazyDown(int p) {
    if (IT[p].lazy == 1) {
        //cerr << "lazy " << p << "\n";
        IT[p].lazy = 0;
        IT[p].sum = -IT[p].sum;
        swap(IT[p].minSum, IT[p].maxSum);
        IT[p].minSum = - IT[p].minSum;
        IT[p].maxSum = - IT[p].maxSum;
        IT[2*p].lazy ^= 1;
        IT[2*p+1].lazy ^= 1;
    }
}
void update(int p, int ll, int rr) {
    lazyDown(p);
    //cerr << "update " << p << " " << IT[p].l << " " << rr << "\n";
    if (ll > IT[p].r || IT[p].l > rr) return;
    //cerr << "update " << p << "\n";
    if (ll <= IT[p].l && IT[p].r <= rr) {
        IT[p].lazy = 1;
        lazyDown(p);
    } else {
        //cerr << "spilt \n";
        update(2*p, ll, rr);
        update(2*p+1, ll, rr);
        IT[p].sum = IT[2*p].sum + IT[2*p+1].sum;
        IT[p].minSum = min(IT[2*p].minSum, IT[2*p].sum + IT[2*p+1].minSum);
        IT[p].maxSum = max(IT[2*p].maxSum, IT[2*p].sum + IT[2*p+1].maxSum);
    }
}
pack get(int p, int ll, int rr) {
    lazyDown(p);
    //cerr << "get " << p << " " << IT[p].l << " " << IT[p].r << " " << ll << " " << rr << "\n";
    if (ll > IT[p].r || IT[p].l > rr) return foo;
    pack res;
    //cerr << "ok\n";
    if (ll <= IT[p].l && IT[p].r <= rr) {
        //cerr << "end here\n";
        res.minSum = IT[p].minSum;
        res.maxSum = IT[p].maxSum;
        res.sum = IT[p].sum;
        return res;
    } else {
        int mid = (ll+rr)/2+1;
        /*if (rr <= mid-1) return get(2*p, ll, rr);
        if (mid <= ll) return get(2*p+1, ll, rr);*/
        pack tmp1 = get(2*p, ll, rr);
        pack tmp2 = get(2*p+1, ll, rr);
        if (tmp1.sum == 1e9) return tmp2;
        else if (tmp2.sum == 1e9) return tmp1;

        res.sum = tmp1.sum + tmp2.sum;
        res.minSum = min(tmp1.minSum, tmp1.sum + tmp2.minSum);
        res.maxSum = max(tmp1.maxSum, tmp1.sum + tmp2.maxSum);
        return res;
    }
}
void show(pack a) {
    cerr << a.sum << " " << a.minSum << " " << a.maxSum << "\n";
}
int main() {
    foo.sum = 1e9;
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
    scanf("%s", s + 1);
    n = strlen(s+1);
    build(1, 1, n);
    //show(1, 1, n);
    scanf("%d", &q);
    while (q --) {
        int cmd, l, r;
        scanf("%d%d%d", &cmd, &l, &r);
        if (cmd == 1) {
            update(1, l, r);
        }
        else {
            pack tmp = get(1, l, r);
            //show(tmp);
            if (tmp.sum == 0 && tmp.minSum >= 0) printf("%d\n", tmp.maxSum);
            else printf("-1\n");
        }
    }
}
