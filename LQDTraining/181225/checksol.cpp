#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define REP(i,n) for (int i = 0; i < (n); ++ i)
#define FOR(i,a,b) for (int i = (a); i <= (b); ++ i)
#define FORD(i,b,a) for (int i = (b); i >= (a); -- i)
#define debug(x) cerr << #x << ": " << x << "\n"
#define all(x) x.begin(), x.end()
#define task "sol"
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
typedef pair<ll, int> li;
typedef vector<int> vi;

string testDir, runDir;

void input() {
    ifstream inp((testDir + task".inp").c_str());

    inp.close();
}

void score() {
    ifstream out((runDir + task".out").c_str());
    ifstream ans((testDir + task".out").c_str());
    int a, b;
    out >> a;
    ans >> b;
    cout << (a == b);
    out.close();
    ans.close();
}

int main() {
	getline(cin, testDir);
	getline(cin, runDir);
    //input();
    score();
}
