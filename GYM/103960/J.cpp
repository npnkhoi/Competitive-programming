#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("Test.txt", "r", stdin);
    int n; cin >> n;
    int John = 0, Marry = 0;

    vector<int> freqCount(14, 0);

    for(int i = 0; i < 2; i++) {
        int value; cin >> value;
        freqCount[value]++;
        if(value > 10) value = 10;
        John += value;
    }

    for(int i = 0; i < 2; i++) {
        int value; cin >> value;
        freqCount[value]++;
        if(value > 10) value = 10;
        Marry += value;
    }

    for(int i = 0; i < n; i++) {
        int value; cin >> value;
        freqCount[value]++;
        if(value > 10) value = 10;
        John += value; Marry += value;
    }

    if(John > Marry) {
        int res = -1;
        for(int card = 24 - John; card <= min(10, 23 - Marry); card++) {
            if(freqCount[card] < 4) {
                res = card;
                break;
            }

            if(card == 10) {
                for(int image = 11; image <= 13; image++) {
                    if(freqCount[image] < 4) {
                        res = image;
                        break;
                    }
                }

                if(res != -1)
                    break;
            }
        }

        cout << res;
    } else if(John <= Marry) {
        if(freqCount[23 - Marry] < 4 && 23 - Marry <= 10) cout << 23 - Marry;
        else cout << -1;
    }

    return 0;
}
