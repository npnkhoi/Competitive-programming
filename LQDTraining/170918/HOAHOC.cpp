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
ll weight(char &ch) {
    if (ch == 'C') return 12;
    else if (ch == 'H') return 1;
    else if (ch == 'O') return 16;
    else if (ch == '(') return -1;
    else return 0;
}
int main() {
    freopen("HOAHOC.inp", "r", stdin);
    freopen("HOAHOC.out", "w", stdout);
    getline(cin, s);
    REP(i, s.size()) {
        if (s[i] == ')') {
            ll tmp = 0;
            while (st.top() != -1) tmp += st.top(), st.pop();
            st.pop();
            st.push(tmp);
        }
        else if (isdigit(s[i])) {
            ll tmp = 1LL * (s[i] - '0') * st.top();
            st.pop();
            st.push(tmp);
        }
        else st.push(weight(s[i]));
    }
    ll res = 0;
    while (!st.empty()) res += st.top(), st.pop();
    cout << res;

    return 0;
}
/** Happy Coding ^^ */
