#include <string>
#include <iostream>
#include <stack>
#include <stdio.h>
#define REP(i, n) for (int i = 0; i < n; i++)
using namespace std;
const int oo = 1e9 + 7;
struct pack {
    int a[4];
};
stack<pack> st;
void show(pack a) {
    REP(i, 4) cerr << a.a[i] << " " ;
    cerr << "\n";
}
int main() {
    freopen("INDEP.inp", "r", stdin);
    freopen("INDEP.out", "w", stdout);
    pack one;
    one.a[0] = 0;
    one.a[1] = 1;
    one.a[2] = 1;
    one.a[3] = -oo;

    string str;
    getline(cin, str);
    for (int i = str.size() - 1; i >= 0; i--)
    if (str[i] == 'g') st.push(one);
    else if (str[i] == 'P') {
        //cerr << "P -------\n";
        pack tmp1 = st.top(); st.pop();
        pack tmp2 = st.top(); st.pop();
        //show(tmp1); show(tmp2);
        pack tmp;
        REP(mask, 4)
            tmp.a[mask] = max(-oo, tmp1.a[mask] + tmp2.a[mask] - __builtin_popcount(mask));
        st.push(tmp);
        //show(tmp);
    } else if (str[i] == 'S') {
        //cerr << "S ----------\n";
        pack tmp1 = st.top(); st.pop();
        pack tmp2 = st.top(); st.pop();
        //show(tmp1); show(tmp2);
        pack tmp;
        REP(mask, 4)
            tmp.a[mask] = max(tmp1.a[mask&2] + tmp2.a[mask&1], tmp1.a[mask|1] + tmp2.a[mask|2] - 1);
        st.push(tmp);
        //show(tmp);
    }
    int res = 0;
    REP(mask, 4) res = max(res, st.top().a[mask]);
    printf("%d\n", res);
}
