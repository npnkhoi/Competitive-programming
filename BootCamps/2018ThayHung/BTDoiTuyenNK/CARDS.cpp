//#include <bits/stdc++.h>
#include <vector>
#include <cstdio>
#include <iostream>
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

#define task "cards"

const int N = 1e5 + 5;
int l[N], r[N];
int n, x, head;

int getElement(int head, int x) {
    int res = head;
    for (int i = 2; i <= x; i++) res = r[res];
    return res;
}
void showList() {
    int cur = head;
    while (cur != -1) {
        printf("%d ", cur);
        cur = r[cur];
    }
    printf("\n");
}
int main() {
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
    scanf("%d%d", &n, &x);
    for (int i = 2; i <= n; i++) l[i] = i-1; l[1] = -1;
    for (int i = 1; i < n; i++) r[i] = i+1; r[n] = -1;
    head = 1;

    for (int love = 1; love <= x; love ++) {
        int lo, hi, valLo, valHi, nex, len, d;
        scanf("%d%d%d", &lo, &len, &d);
        if (len == n) continue;

        hi = lo + len - 1;

        valLo = getElement(head, lo);
        valHi = getElement(valLo, len);

        if (valLo == head) head = getElement(valHi, 2);
        //cerr << valLo << " " << valHi << "\n";
        if (l[valLo] != -1) r[l[valLo]] = r[valHi];
        if (r[valHi] != -1) l[r[valHi]] = l[valLo];
        l[valLo] = r[valHi] = -1;

        //showList();

        if (d == 1) {
            l[valLo] = -1;
            r[valHi] = head;
            l[head] = valHi;
            head = valLo;
        } else {
            nex = getElement(head, d - 1);
            if (r[nex] != -1) l[r[nex]] = valHi;
            r[valHi] = r[nex];

            r[nex] = valLo;
            l[valLo] = nex;
        }
        //showList();
    }
    showList();
}
/// Expelliarmus !
