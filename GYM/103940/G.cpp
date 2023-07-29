#include <bits/stdc++.h>

using namespace std;
#define int long long
typedef pair<int, int> pii;

int findOverlap(pii x, pii y) {
    int end1Start2 = x.second - y.first;
    int end2Start1 = y.second - x.first;
    int overlapMin = min(end1Start2, end2Start1);
    return max(0LL, overlapMin);
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    freopen("Test.txt", "r", stdin);
    int n; cin >> n;
    vector<int> distList(n - 1);
    for(int i = 0; i < n - 1; i++)
        cin >> distList[i];

    vector<int> waitingList(n);
    for(int i = 0; i < n; i++)
        cin >> waitingList[i];

    vector<pii> firstTrain(n);
    vector<pii> secondTrain(n);

    int time = 1;
    for(int i = 0; i < n; i++) {
        int startTime = time;
        int endTime = startTime + waitingList[i];
        firstTrain[i] = {startTime, endTime};
        if(i < n - 1)
            time = endTime + distList[i];
    }

    time = 1;
    for(int i = n -1 ; i >= 0; i--) {
        int startTime = time;
        int endTime = startTime + waitingList[i];
        secondTrain[i] = {startTime, endTime};
        if(i > 0)
            time = endTime + distList[i - 1];
    }

    int sameWaiting = 0;
    for(int i = 0; i < n; i++) {
        int overlapTime = findOverlap(firstTrain[i], secondTrain[i]);
        // cout << overlapTime << endl;
        sameWaiting = max(sameWaiting, overlapTime);
    }

    cout << sameWaiting;

    /*
    time = 1;
    for(int i = n - 1; i >= 0; i--) {
        int startTime = time;
        int endTime = startTime + waitingList[i];
        secondTrain[i] = {startTime, endTime};
        if(i > 0)
            time = endTime + distList[i];
    } */
    /*
     for(int i = 0; i < n; i++)
        cout << firstTrain[i].first << ' ' << firstTrain[i].second << endl;

    for(int i = 0; i < n; i++)
        cout << secondTrain[i].first << ' ' << secondTrain[i].second << endl;
    */




    return 0;

}
