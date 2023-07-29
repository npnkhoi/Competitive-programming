#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
const int MAX = 5e6 + 10;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    freopen("Test.txt", "r", stdin);
    int n; cin >> n;
    vector<int> balloonLst(n);
    for(int i = 0; i < n; i++) {
        cin >> balloonLst[i];
    }

    vector<int> cnt(MAX);
    int result = 0;
    for(int i = 0; i < n; i++) {
        int cur = balloonLst[i];
        if(cnt[cur] > 0) {
            cnt[cur]--;
            cnt[cur - 1]++;
        } else {
            cnt[cur - 1]++;
            result++;
        }
    }

    cout << result;
    return 0;
}
