#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;

int main() {
    int tc; cin >> tc;
    while(tc--) {
        int n; cin >> n;
        vector<int> list(n);
        for(int i = 0; i < n; i++)
             cin >> list[i];

        bool f[100][100];
        memset(f, false, sizeof(f));
        f[0][0] = true;

        vector<pii> prev;
        for(int i = 0; i < n; i++) {
            int num = list[i];
            int digit = num % 10;
            for(int j = 0; j < prev.size(); j++) {
                int r = prev[i].first;
                int c = prev[i].second;
                f[r][c] = true;
            }

            prev.clear();
            for(int j = 0; j < 4; j++) {
                for(int k = 0; k < 10; k++) {
                    if(f[j][k] && j + 1 < 4 && k + digit < 10)
                        prev.push_back({j + 1, k + digit});
                }
            }

            cout << 0 << endl;
        }

        cout << "Ma may" << endl;

        for(int i = 0; i < prev.size(); i++)
            f[prev[i].first][prev[i].second] = true;
        
        if(f[3][3]) cout << "YES" << endl;
        else cout << "NO" << endl;
        return 0;
    }
}