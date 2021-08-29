#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define REP(i,n) for (int i = 0; i < n; ++ i)
#define FOR(i,a,b) for (int i = a; i <= b; ++ i)
#define FORD(i,b,a) for (int i = b; i >= a; -- i)
#define task "SC3"
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ll, int> li;
typedef vector<int> vi;

struct Node{
    int cnt;
    Node *son[2];
} *T;
void init(Node *&p) {
    p = new Node;
    p -> cnt = 0;
    p -> son[0] = p -> son[1] = NULL;
}
void add(int val) {
    Node *p = T;
    T -> cnt ++;
    FORD(i, 30, 0) {
        int tmp = (val & (1 << i)) > 0;
        if (p -> son[tmp] == NULL) init(p -> son[tmp]);
        p = p -> son[tmp];
        p -> cnt ++;
    }
}
void del(int val) {
    Node *p = T;
    T -> cnt --;
    FORD(i, 30, 0) {
        int tmp = (val & (1 << i)) > 0;
        p = p -> son[tmp];
        p -> cnt --;
    }
}

int get(int pos) {
    //cerr << "into get" << pos << "\n";
    Node *p = T;
    int res = 0, cnt = 0;
    FORD(i, 30, 0) {
        int tmp;
        if (p->son[0] != NULL) {
            if (cnt + ((p -> son[0]) -> cnt) < pos) {
                tmp = 1;
                cnt += (p -> son[0]) -> cnt;
            }
            else tmp = 0;
        } else tmp = 1;
        if (tmp) res += (1 << i);
        p = p -> son[tmp];
    }
    //cerr << "done get\n";
    return res;
}
void show(Node *p, int val, int dep) {
    if (dep == 0) cerr << val << "\n";
    else {
        REP(j, 2) {
            if (p -> son[j] != NULL && p -> son[j] -> cnt > 0)
            show(p -> son[j], 2*val + j, dep - 1);
        }
    }
}

const int N = 1e5 + 5;

int tc, n, q, d;
vi que[N];
int a[N];


int main() {
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
    scanf("%d", &tc);
    REP(khue, tc) {
        scanf("%d%d%d", &n, &q, &d);
        FOR(i, 1, n) {
            scanf("%d", &a[i]);
        }
        ll res = 0;
        FOR(i, 1, n) que[i].clear();
        FOR(i, 1, q) {
            int l, pos;
            scanf("%d%d", &l, &pos);
            que[l+d-1].pb(d-pos+1);
            //cerr << "pb " << l << "\n";
        }
        init(T);
        FOR(i, 1, n) {
            add(a[i]);
            if (i > d) {
                del(a[i - d]);
            }
            //show(T, 0, 31);
            //cerr << i - d + 2 << " done show \n";

            if (i >= d) {
                //cerr << "size " << (int) que[i].size() << "\n";
                REP(j, que[i].size()) res += get(que[i][j]);
                //cerr << "get " << get(que[i][j]) << "\n";
            }
        }
        printf("%lld\n", res);
    }
}
