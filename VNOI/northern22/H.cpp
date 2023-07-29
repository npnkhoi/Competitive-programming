#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("Test.txt", "r", stdin);

    multiset<int> minSet;
    multiset<int> maxSet;

    int q; cin >> q;
    for(int T = 1; T <= q; T++) {
        // cout << "Test " << T << endl;

        string type; cin >> type;
        if(type == "IN") {
            int value; cin >> value;
            maxSet.insert(value);
            int outEle = *maxSet.rbegin();
            minSet.insert(outEle);
            maxSet.erase(maxSet.find(outEle));
            if(abs((int) minSet.size() - (int) maxSet.size()) >= 2) {
                int lowest = *minSet.begin();
                maxSet.insert(lowest);
                minSet.erase(minSet.find(lowest));
            }
            // for(auto element: minSet)
            //     cout << element << ' ';
            // cout << endl;
            // for(auto element: maxSet)
            //     cout << element << ' ';
            // cout << endl;
        } else if(type == "MEDIAN") {
            double median;
            if(((int) maxSet.size() + (int) minSet.size()) % 2 == 0) {
                median = (double) (*minSet.begin() + *maxSet.rbegin()) / 2;
            } else {
                median = *minSet.begin();
            }

            cout << median << endl;
        } else if(type == "OUT") {
            int value; cin >> value;
            set<int>::iterator maxIT = maxSet.find(value);
            if(maxIT != maxSet.end()) {
                maxSet.erase(maxIT);
            } else {
                set<int>::iterator minIT = minSet.find(value);
                minSet.erase(minIT);
            }

            if((int) maxSet.size() > (int) minSet.size()) {
                int highest = *maxSet.rbegin();
                minSet.insert(highest);
                maxSet.erase(maxSet.find(highest));
            }

            if((int) minSet.size() - (int) maxSet.size() >= 2) {
                int lowest = *minSet.begin();
                maxSet.insert(lowest);
                minSet.erase(minSet.find(lowest));
            }
            // for(auto element: minSet)
            //     cout << element << ' ';
            // cout << endl;
            // for(auto element: maxSet)
            //     cout << element << ' ';
            // cout << endl;
        }
    }

    return 0;
}
