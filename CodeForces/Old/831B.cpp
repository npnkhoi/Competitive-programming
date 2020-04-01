using namespace std;

#include <bits/stdc++.h>

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define For(i, a, b) for (int i = a; i <= b; i++)
#define F0r(i, b, a) for (int i = b; i >= a; i--)

typedef pair<int, int> ii;
typedef vector<int> vi;

map<char, char> data;
string str;
char a[30];

using namespace std;

int main()
{
    //freopen("","r",stdin);
    //freopen("","w",stdout);
    int n = 26;
    for (int i = 1; i <= n; i++) scanf(" %c", &a[i]);
    for (int i = 1; i <= n; i++) {
        char ch;
        scanf(" %c", &ch);
        data[a[i]] = ch;
        data[a[i] - 'a' + 'A'] = ch - 'a' + 'A';
    }
    cin >> str;
    for (int i = 0; i < str.size(); i++)
    if ('0' <= str[i] && str[i] <= '9') printf("%c", str[i]);
    else printf("%c", data[str[i]]);
    return 0;
}
/**/
