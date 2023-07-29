#include <bits/stdc++.h>

using namespace std;
#define int long long
unordered_map<int, string> decodeMap;
unordered_map<string, int> encodeMap;

struct RGB {
    string name;
    int r, g, b;
};

int findDistanceSquare(int r1, int g1, int b1, int r2, int g2, int b2) {
    return (r1 - r2) * (r1 - r2) + (g1 - g2) * (g1 - g2) + (b1 - b2) * (b1 - b2);
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    vector<RGB> colorList(17);
    colorList[1] = {"White", 255, 255, 255};
    colorList[2] = {"Silver", 192, 192, 192};
    colorList[3] = {"Gray", 128, 128, 128};
    colorList[4] = {"Black", 0, 0, 0};
    colorList[5] = {"Red", 255, 0, 0};
    colorList[6] = {"Maroon", 128, 0, 0};
    colorList[7] = {"Yellow", 255, 255, 0};
    colorList[8] = {"Olive", 128, 128, 0};
    colorList[9] = {"Lime", 0, 255, 0};
    colorList[10] = {"Green", 0, 128, 0};
    colorList[11] = {"Aqua", 0, 255, 255};
    colorList[12] = {"Teal", 0, 128, 128};
    colorList[13] = {"Blue", 0, 0, 255};
    colorList[14] = {"Navy", 0, 0, 128};
    colorList[15] = {"Fuchsia", 255, 0, 255};
    colorList[16] = {"Purple", 128, 0, 128};


    while(true) {
        vector<int> distanceList(17);
        int r, g, b; cin >> r >> g >> b;
        if(r == -1 && g == -1 && b == -1) break;

        for(int i = 1; i <= 16; i++) {
            RGB rgb = colorList[i];
            string colorName = rgb.name;
            int colorR = rgb.r;
            int colorG = rgb.g;
            int colorB = rgb.b;
            int dist = findDistanceSquare(r, g, b, colorR, colorG, colorB);
            distanceList[i] = dist;
        }

        int minIndex = -1;
        int minValue = INT_MAX;
        for(int i = 1; i <= 16; i++) {
            int currentDist = distanceList[i];
            if(currentDist < minValue) {
                minIndex = i;
                minValue = currentDist;
            }
        }

        RGB res = colorList[minIndex];
        cout << res.name << endl;
    }

    return 0;
}

