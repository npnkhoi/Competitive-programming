using namespace std;
#include <stdio.h>
#include <iostream>
#include <vector>
#include <string.h>
#include <cstring>
const int N = 2e5 + 50;
const long long oo = 1e18 + 7;
int a[N];
int lazy[4*N];
long long IT[8*N];
int n, q;

int left(int p) { return p<<1; }
int right(int p) { return (p<<1)+1; }

void build(int p, int l, int r)
{
    if (l==r) IT[p] = a[l];
    else
    {
        int mid = (l+r)/2;
        build(left(p), l, mid);
        build(right(p), mid + 1, r);
        IT[p] = min(IT[left(p)], IT[right(p)]);
    }
}
void keen(int p) {
    lazy[left(p)] += lazy[p];
    lazy[right(p)] += lazy[p];
    IT[p] += lazy[p];
    lazy[p] = 0;
}
void update(int p, int l, int r, int L, int R, int v)
{
    //printf("update %d %d %d %d %d %d\n",p, l, r, L, R, v);
    keen(p);
    //-----------------------------------
    if (r<L || R<l || l>r) return;

    if (L<=l && r<=R)
    {
        IT[p] += v;
        lazy[left(p)] += v;
        lazy[right(p)] += v;
    }
    else
    {
        int mid = (l+r) / 2;
        update(left(p), l , mid, L, R, v);
        update(right(p), mid + 1, r, L, R, v);
        IT[p] = min(IT[left(p)], IT[right(p)]);
    }
}
long long rmq(int p, int l, int r, int L, int R)
{
    keen(p);
    if (r<L || R<l || l>r) return oo;
    if (L<=l && r<=R) return IT[p];
    int mid = (l+r)/2;
    return min(
                rmq(left(p), l, mid, L, R),
                rmq(right(p), mid + 1, r, L, R) );
}
int main()
{
    //freopen("test.inp", "r", stdin);
    //freopen("test.out","w",stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    build(1, 0, n-1);
    memset(lazy, 0, sizeof lazy);

    scanf("%d\n", &q);
    //cout << q << endl;
    while (q--)
    {
        string line;
        getline(cin, line);
        vector<int> v;
        int t = 0;
        bool neg = 0;
        for (int i = 0; i < line.size(); i++)
            if (line[i] == ' ') {
                if (neg) t = -t;
                v.push_back(t);
                t = 0;
                neg = 0;
            }
            else if (line[i] == '-') neg = 1;
            else t = 10*t + line[i] - '0';

        if (neg) t = -t;
        v.push_back(t);
        if (v[0] <= v[1]) {
            if (v.size() == 2) printf("%I64d\n", rmq(1, 0, n-1, v[0], v[1]));
            else update(1, 0, n-1, v[0], v[1], v[2]);
        }
        else {
            if (v.size() == 2) {
                long long res = min(    rmq(1, 0, n-1, 0, v[1]),
                                        rmq(1, 0, n-1, v[0], n-1) );
                printf("%I64d\n", res);
            }
            else
                update(1, 0, n-1, 0, v[1], v[2]),
                update(1, 0, n-1, v[0], n-1, v[2]);
        }
    }
}
