#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
int n, q;
vector <int> vec = {2, 3, 5, 7};
array <int, 4> lazy[4 * N], st[4 * N];

int Left(int x) {
    return x << 1;
}

int Right(int x) {
    return (x << 1) + 1;
}

void upd(array<int,4> &a, array <int, 4> b) {
    for (int i = 0; i < 4; ++i) {
        a[i] += b[i];
    }
}

array<int,4> get_max(array<int,4> a, array <int, 4> b) {
    array<int,4> ret = {0, 0, 0, 0};
    for (int i = 0; i < 4; ++i) {
        ret[i] = max(a[i], b[i]);
    }
    return ret;
}


void push(int id, int L, int R) {
    upd(st[id], lazy[id]);
    if (L != R) {
        upd(lazy[Left(id)], lazy[id]);
        upd(lazy[Right(id)], lazy[id]);
    }
    lazy[id] = {0, 0, 0, 0};
}

void add(int id, int L, int R, int i, int j, array <int, 4> more) {
    if (L <= R) push(id, L, R);
    if (L > j || R < i) {
        return;
    }
    if (L >= i && R <= j) {
        upd(lazy[id], more);
        push(id, L, R);
        return;
    }
    int mid = (L + R) >> 1;
    add(Left(id), L, mid, i, j, more);
    add(Right(id), mid + 1, R, i, j, more);
    st[id] = get_max(st[Left(id)], st[Right(id)]);
}

array<int, 4> query(int id, int L, int R, int i, int j) {
    if (L <= R) push(id, L, R);
    if (L > j || R < i) {
        return {0, 0, 0, 0};
    }
    int mid = (L + R) >> 1;
    if (L >= i && R <= j) {
        return st[id];
    }
    array<int,4> l = query(Left(id), L, mid, i, j), r = query(Right(id), mid + 1, R, i, j);
    st[id] = get_max(st[Left(id)], st[Right(id)]);
    return get_max(l, r);
}

int max_value(array<int, 4> a) {
    int mx = 0;
    for (int i = 0; i < 4; ++i) {
        mx = max(mx, a[i]);
    }
    return mx;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("G.inp", "r", stdin);

    int n, q;
    cin >> n >> q;
    while (q--) {
        string type;
        cin >> type;
        if (type == "MULTIPLY") {
            int l, r, x;
            cin >> l >> r >> x;
            array<int, 4> qq = {0, 0, 0, 0};
            for (int i = 0; i < 4; ++i) {
                while (x % vec[i] == 0) {
                    x /= vec[i];
                    qq[i]++;
                }
            }
            add(1, 1, n, l, r, qq);
        } else {
            int l, r;
            cin >> l >> r;
            int res = max_value(query(1, 1, n, l, r));
            cout << "ANSWER " << res << endl;
        }
    }

    return 0;
}
