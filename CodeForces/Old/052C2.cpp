using namespace std;
#include <stdio.h>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
#include <sstream>
#define ll long long

const int N = 2e5 + 10;
const ll oo = 1e15;
ll IT[4*N], a[N], lazy[4*N];
int n;
ll build(ll IT[], int p, ll a[], int l, int r) {
    if (l == r) return IT[p] = a[l];

    int mid = (l+r)/2;
    return IT[p] = min(build(IT, 2*p, a, l, mid), build(IT, 2*p+1, a, mid+1, r));
}

void lazyDown(ll IT[], int p) {
    if (2*p+1 >= 4*n) return;

    lazy[2*p] += lazy[p];
    lazy[2*p+1] += lazy[p];
    IT[2*p] += lazy[p];
    IT[2*p+1] += lazy[p];
    lazy[p] = 0;
}

ll update(ll IT[], int p, int l, int r, int L, int R, ll val) {
    if (r < L || R < l || r < l || R < L) return IT[p];
    //printf("update %d %d %d %d\n", l, r, L, R);

    lazyDown(IT, p);

    if (L <= l && r <= R) {
        lazy[p] += val;
        return IT[p] = IT[p] + val;
    }
    int mid = (l+r)/2;
    return IT[p] =
        min(update(IT, 2*p, l, mid, L, R, val), update(IT, 2*p+1, mid+1, r, L, R, val));
    //for (int i = 1; i <= 4*n; i++) cout << lazy[i] << " \n"[i == 4*n];
    //for (int i = 1; i <= 4*n; i++) cout << IT[i] << " \n"[i == 4*n];
}

ll rmq(ll IT[], int p, int l, int r, int L, int R) {
    if (r < L || R < l || r < l || R < L) return oo;
    //printf("rmq %d %d %d %d\n", l, r, L, R);
    //for (int i = 1; i <= 4*n; i++) cout << lazy[i] << " \n"[i == 4*n];

    lazyDown(IT, p);

    if (L <= l && r <= R) return IT[p];
    else {
        int mid = (l+r)/2;
        return min(
            rmq(IT, 2*p, l, mid, L, R), rmq(IT, 2*p+1, mid+1, r, L, R));
    }
}
int main() {
    //freopen("test.inp", "r", stdin);
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    build(IT, 1, a, 0, n-1);
    //cout << "ok" << endl;
    //for (int i = 0; i < n; i++) cout << rmq(IT, 1, 0, n-1, i, i) << " \n"[i == n-1];
    int q;
    cin >> q; cin.ignore();
    //cout << q << "--"<< endl;

    while (q--) {
    //==================================
        string line; getline(cin, line);
        //cout << "ok\n";
        //cout << line << endl;
        stringstream ss(line);
        vector<int> v;
        int x;
        while (ss >> x) v.push_back(x);
        int l = v[0], r = v[1];
    //==================================
        if (v.size() == 2) {
            //printf("rmq %d:\n", ++cnt);
            if  (l <= r) printf("%I64d\n", rmq(IT, 1, 0, n-1, l, r));
            else printf("%I64d\n",
                min(rmq(IT, 1, 0, n-1, l, n-1), rmq(IT, 1, 0, n-1, 0, r)));
            //for (int i = 0; i < n; i++) cout << rmq(IT, 1, 0, n-1, i, i) << " \n"[i == n-1];
        }
        else {
            //printf("UPDATE: %d %d %d\n", v[0], v[1], v[2]);
            if (l <= r) update(IT, 1, 0, n-1, l, r, v[2]);
            else
                update(IT, 1, 0, n-1, 0, r, v[2]),
                update(IT, 1, 0, n-1, l, n-1, v[2]);
            //for (int i = 1; i <= 4*n; i++) cout << IT[i] << " \n"[i == 4*n];
            //for (int i = 1; i <= 4*n; i++) cout << lazy[i] << " \n"[i == 4*n];
            //for (int i = 0; i < n; i++) cout << rmq(IT, 1, 0, n-1, i, i) << " \n"[i == n-1];
        }
    }
}
