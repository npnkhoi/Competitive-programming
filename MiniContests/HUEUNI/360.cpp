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
char s[105];
int n;
void truoc(int i) {
    if (i > n || s[i] == '0') return;
    printf("%c ", s[i]);
    truoc(2*i);
    truoc(2*i + 1);
}
void giua(int i) {
    if (i > n || s[i] == '0') return;
    giua(2*i);
    printf("%c ", s[i]);
    giua(2*i + 1);
}
void sau(int i) {
    if (i > n || s[i] == '0') return;
    sau(2*i);
    sau(2*i + 1);
    printf("%c ", s[i]);
}
int main() {
    //freopen("", "r", stdin);
    //freopen("", "w", stdout);
    scanf("%s", s+1);
    n = strlen(s+1);
    truoc(1); printf("\n");
    giua(1); printf("\n");
    sau(1); printf("\n");
    return 0;
}
/** Happy Coding ^^ */
