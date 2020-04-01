using namespace std;
#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define FOD(i, b, a) for (int i = b; i >= a; i--)
#define REP(i ,n) for (int i = 0; i < n; i++)

string s;
stack<int> st;
int main() {
    freopen("NGOAC.inp", "r", stdin);
    freopen("NGOAC.out", "w", stdout);
    //ios_base::sync_with_stdio(0); cin.tie(0);
    getline(cin, s);
    int cnt = 0, res = 0;
    REP(i, s.size()) {
        if (s[i] == '(') res ++, cnt ++;
        else if (s[i] == ')') cnt --;
        if (cnt < 0) {
            //cout << "-1";
            printf("-1");
            return 0;
        }
    }
    if (cnt != 0) {
        //cout << "-1";
        printf("-1");
        return 0;
    }

    printf("%d\n", res);
    REP(i, s.size()) {
        if (s[i] == '(') st.push(i);
        else if (s[i] == ')') {
            FOR(j, st.top(), i) printf("%c", s[j]);
            printf("\n");
            st.pop();
        }
    }
    return 0;
}
/** Happy Coding ^^ */
