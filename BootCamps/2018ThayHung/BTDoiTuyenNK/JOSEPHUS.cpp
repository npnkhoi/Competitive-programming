#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<ll, int> li;
typedef pair<int, int> ii;
typedef unsigned long long ull;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define REP(i,n) for (int i = 0; i < n; ++ i)
#define FOR(i,a,b) for (int i = a; i <= b; ++ i)
#define FORD(i,b,a) for (int i = b; i >= a; -- i)

#define task "josephus"

struct node {
    node *nex[2], *par;
    int cnt;
    bool End;
} *T;
int n, m, L;


void init(node *&p) {
    p = new node;
    p -> nex[0] = p -> nex[1] = NULL;
    p -> cnt = 0;
    p -> End = 0;
}
void add(int val) {
    vi v; v.resize(L);
    FORD(i, L-1, 0) {
        v[i] = val%2, val /= 2;
    }
    node *p = T;
    (T -> cnt) ++;
    REP(i, L) {
        int tmp = v[i];
        if (p -> nex[tmp] == NULL) init(p -> nex[tmp]);
        (p -> nex[tmp]) -> par = p;
        p = p -> nex[tmp];
        p -> cnt ++;
    }
    p -> End = 1;
}
void calc(int pos) {
    node *p = T;
    T -> cnt --;

    int ans = 0;
    REP(i, L) {
        int t;
        if (p->nex[0] != NULL && ((p -> nex[0]) -> cnt) >= pos) t = 0;
        else {
            t = 1;
            if (p->nex[0] != NULL) pos -= p -> nex[0] -> cnt;
        }
        ans = 2 * ans + t;
        p = p -> nex[t];
        p -> cnt --;
    }
    printf("%d ", ans);
}
void duyet(node *p, int d) {
    if (p->nex[0] && (p->nex[0])->cnt) {
        cerr << " (0 " << d << ") ";
        duyet(p->nex[0], d+1);
    }
    if (p->nex[1] && (p->nex[1])->cnt) {
        cerr << " (1 " << d << ") ";
        duyet(p->nex[1], d+1);
    }
}
void make_test() {
    ofstream inp(task".inp");
    inp << 1 + rand() % 10 << " " << rand() % 10 + 1;
    //inp << "1 2";
    inp.close();
}
int main() {
    //srand(time(NULL));
    //while (1) {
        //make_test();
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
        scanf("%d%d", &n, &m);
        //m %= n; if (m == 0) m = n;
        L = (int)ceil(log2(n)+1);
        init(T);
        FOR(i, 1, n) add(i);
        int pos = n+1;
        FORD(i, n, 2) {
            pos = (pos + m + i - 1) % i;
            if (pos == 0) pos = i;
            calc(pos);
        }
        calc(1);
        //cerr << "ok\n";
    //}
}
/** Happy Coding :D */
