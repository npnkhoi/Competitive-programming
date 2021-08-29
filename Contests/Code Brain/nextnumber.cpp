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

using namespace std;
string s;
int pos[11];
int main()
{
    //freopen("test.inp","r",stdin);
    //freopen("","w",stdout);
    while (getline(cin, s)) {
        //cout << s << endl;
        if (s[0] == '0') {
            printf("Error!\n");
            continue;
        }
        int l = s.size();
        for (int i = 0; i <= 9; i++) pos[i] = -1;
        bool cont = 1;

        for (int i = l-1; i >= 0 && cont; i--) {
            int x = s[i] - '0';

            pos[x] = i;

            for (int j = x + 1; j <= 9; j++)
            if (pos[j] != -1) {
                s[i] = j + '0';
                s[pos[j]] = x + '0';
                sort(s.begin() + i + 1, s.end());
                while (s[0] == '0') s.erase(s.begin());
                printf("%s\n", s.c_str());
                cont = 0;
                break;
            }
        }
        if (cont) printf("Error!\n");
    }
    return 0;
}
/**/
