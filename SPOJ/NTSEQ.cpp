using namespace std;
#include <vector>
#include <stdio.h>
#include <iostream>
#define pb push_back
#define mp make_pair
#define ll long long
#define ii pair<int, int>
#define fi first
#define se second
const int N = 1e5 + 10;
const int oo = 1e9 + 7 ;
const int md = 1e9 + 7;
int n;
vector<ii> cnt[N];
vector<int> tail;

int main() {
    scanf("%d", &n);
    tail.pb(-oo);
    cnt[0].push_back(mp(-oo, 1));
    //for (int i = 0; i < tail.size(); i++) cout << tail[i] << " "; cout << endl;
    for (int i = 0; i < n; i++) {
        int num, pos;
        scanf("%d", &num);

        if (num > tail.back()) {
            tail.pb(num);
            pos = tail.size() - 1;
        }
        else {
            int l = 0, r = tail.size() - 1;
            while (l < r) {
                int mid = (l+r+1)/2;
                if (tail[mid] < num) l = mid;
                else r = mid-1;
            }
            pos = l+1;
            tail[pos] = num;
        }
        /// get pos: the position of num in tail
        //cout << pos << "\n";

        int l = 0, r = cnt[pos-1].size() - 1;
        //cout << l << " " << r << endl;
        while (l < r) {
            int mid = (l+r)/2;
            if (cnt[pos-1][mid].fi < num) r = mid;
            else l = mid + 1;
        }
        //cout << l << " " << r << endl;

        int _cnt;
        _cnt = cnt[pos-1].back().se;
        if (l > 0)
            _cnt = (_cnt - cnt[pos-1][l-1].se + md) % md;
        if (!cnt[pos].empty()) _cnt = (_cnt + cnt[pos].back().se) % md;
        cnt[pos].pb(mp(num, _cnt));
    }
    /*for (int i = 0; i <= tail.size(); i++) {
        for (int j = 0; j < cnt[i].size(); j++)
        printf("(%d, %d) ", cnt[i][j].fi, cnt[i][j].se);
        printf("\n");
    }*/
    cout << cnt[tail.size() - 1].back().se;
}
