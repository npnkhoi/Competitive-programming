#include <bits/stdc++.h>
using namespace std;
const int N = 105;
int dep[N], par[N], jump[N];
stack<int> st;
string str[N];
class JustBrackets {
    public:
    string getSmallest(string s) {
        string res = "";
        int n = s.size();
        for (int i = 1; i <= n; i++) {
            if (s[i-1] == '(') {
                if (st.empty()) par[i] = 0;
                else par[i] = st.top();
                st.push(i);
                dep[i] = 1;
            } else {
                int tmp = st.top(); st.pop();
                dep[par[tmp]] = max(dep[par[tmp]], dep[tmp] + 1);
                jump[tmp] = i;
            }
        }
        int m = 0;
        for (int i = 1; i <= n; i++) {
            if (s[i-1] == '(') {
                if (par[i] == 0) ++m;
                else if (dep[i] != dep[par[i]] - 1) {
                    i = jump[i];
                    continue;
                }
            }
            str[m] += s[i-1];
        }
        for (int i = 1; i <= m; i++) cout << str[i] << "\n";
        for (int i = 2; i <= m; i++) if (str[1] > str[i]) str[1] = str[i];
        return str[1];
    }
};
JustBrackets A;
int main() {
    cout << A.getSmallest("()()()()()()()");
}
