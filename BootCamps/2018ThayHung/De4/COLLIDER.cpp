#include <cstdio>
#include <vector>
#include <string>
#include <iostream>
using namespace std;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef long long ll;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define REP(i,n) for (int i = 0; i < n; i++)
#define FOR(i,a,b) for (int i = a; i <= b; i++)
#define FORD(i,b,a) for (int i = b; i >= a; i--)
#define task "collider"

int n;
string s;

int main() {
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
    scanf("%d ", &n);
    while (n--) {
        getline(cin, s);
        if (s[0] == '?') printf("0.0\n");
    }
}
