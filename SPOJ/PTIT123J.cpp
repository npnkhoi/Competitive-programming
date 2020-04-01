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
string line;
int main() {
    //freopen("test.inp", "r", stdin);
    //freopen("", "w", stdout);
    while (1) {
        getline(cin, line);
        if (line == ".") break;
        stack<char> st;
        bool ans = true;
        int cnt = 0;
        FOR(i, 0, line.size() - 1)

        if (line[i] == '(') st.push('(');

        else if (line[i] == ')') {
            if (!st.empty() && st.top() == '(')
                st.pop();
            else {
                ans = false;
                break;
            }
        }

        else if (line[i] == '[') st.push('[');

        else if (line[i] == ']') {
            if (!st.empty() && st.top() == '[') st.pop();
            else {
                ans = false;
                break;
            }
        }
        if (ans) printf("yes\n");
        else printf("no\n");
    }
    return 0;
}
/** Happy Coding ^^ */
