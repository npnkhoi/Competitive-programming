#include <utility>
#include <vector>
#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;
typedef pair<int, int> ii;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define FOR(i,a,b) for (int i = a; i <= b; i++)
#define REP(i,n) for (int i = 0; i < n; i++)
#define FORD(i,b,a) for (int i = b; i >= a; i--)

#define task "DELSTR"

int n;
string s;

string after(string s, int i) {
    string t = "";
    FORD(j, i-1, 0)
        if (s[j] == s[i]) s[j] = '.';
        else break;
    FOR(j, i+1, s.size() - 1)
        if (s[j] == s[i]) s[j] = '.';
        else break;
    s[i] = '.';

    REP(i, s.size()) if (s[i] != '.') t += s[i];
    return t;
}
int backTrack(string s) {
    if (s.empty()) return 0;
    else {
        int res = s.size();
        REP(i, s.size()) res = min(res, 1 + backTrack(after(s, i)));
        return res;
    }
}
int main() {
    freopen(task".inp", "r", stdin);
    freopen(task".ans", "w", stdout);
    scanf("%d ", &n);
    getline(cin, s);
    printf("%d", backTrack(s));

    return 0;
}
