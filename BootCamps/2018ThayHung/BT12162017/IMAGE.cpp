#include <cstdio>
#include <cstring>
#include <string>
#include <stack>
#include <iostream>
#include <algorithm>
using namespace std;
#define taskname "image"

const int maxL = 1e6 + 5;

struct TPoint{
    unsigned long long x, y;
    bool valid;
    bool operator == (const TPoint &a) {
        return x == a.x && y == a.y && valid == a.valid;
    }
    bool operator != (const TPoint &a) {
        return x != a.x || y != a.y || valid != a.valid;
    }
};
struct TNode {
    int child[2][2];
    char color;
    TPoint TopLeft;
};
TPoint NP = {0, 0, 0};


struct TTree {
    int nNodes;
    //char c[maxL];
    TNode Node[maxL];

    void Build(string &s) {
        stack<int> Stack;
        for (int i = s.size() - 1; i >= 0; --i) {
            //cerr << s[i] << "\n";
            Node[i].color = s[i];
            for (int j = 0; j < 2; ++j)
            for (int k = 0; k < 2; ++k)
            if (s[i] == '&'){
                Node[i].child[j][k] = Stack.top();
                Stack.pop();
            } else Node[i].child[j][k] = -1;
            Stack.push(i);
        }
    }
    void setCoor(int idx, unsigned long long x, unsigned long long y, unsigned long long halfSize) {
        Node[idx].TopLeft.x = x;
        Node[idx].TopLeft.y = y;
        Node[idx].TopLeft.valid = 1;
        if (Node[idx].color == '&')
            for (int j = 0; j < 2; ++j)
            for (int k = 0; k < 2; ++k)
            setCoor(Node[idx].child[j][k], x + j * halfSize, y + k * halfSize, halfSize / 2);
    }
    TPoint Find(int idx, char color) {
        //cerr << "find " << idx << " " << color << "\n";
        if (Node[idx].color == color) return Node[idx].TopLeft;
        else if (Node[idx].color != '&') return NP;
        else {
            for (int j = 0; j < 2; ++j)
            for (int k = 0; k < 2; ++k) {
                //cerr << idx << " -> " << Node[idx].child[j][k] << "\n";
                TPoint tmp = Find(Node[idx].child[j][k], color);
                if (tmp != NP) return tmp;
            }
            return NP;
        }
    }
};

int n;
string a, b;

char contrast(char ch) {
    if (ch == 'B') return 'W';
    else return 'B';
}
TPoint Diff(TTree &A, int a, TTree &B, int b) {
    //cerr << "diff " << a << " " << b << "\n";
    if (A.Node[a].color == '&' && B.Node[b].color == '&') {
        for (int j = 0; j < 2; ++j)
        for (int k = 0; k < 2; ++k) {
            TPoint tmp = Diff(A, A.Node[a].child[j][k], B, B.Node[b].child[j][k]);
            if (tmp != NP) return tmp;
        }
        return NP;
    } else if (A.Node[a].color == '&') {
        return A.Find(a, contrast(B.Node[b].color));
    } else if (B.Node[b].color == '&') {
        return B.Find(b, contrast(A.Node[a].color));
    } else if (A.Node[a].color != B.Node[b].color) return A.Node[a].TopLeft;
    else return NP;
}
TTree imageA, imageB;
int main() {
    //cerr << "ok\n";
    freopen(taskname".inp", "r", stdin);
    freopen(taskname".out", "w", stdout);
    //cerr << "ok\n";
    cin >> n >> a >> b;
    imageA.Build(a);
    imageA.setCoor(0, 0, 0, (1LL << (n - 1)));
    imageB.Build(b);
    imageB.setCoor(0, 0, 0, (1LL << (n - 1)));
    /*for (int i = 0; i < a.size(); ++i) {
        cerr << imageA.Node[i].color << " " << imageA.Node[i].child[0][0] << " " << imageA.Node[i].child[0][1] << " "
        << imageA.Node[i].child[1][0] <<
        " " << imageA.Node[i].child[1][1] <<
        " " << imageA.Node[i].TopLeft.x <<
        " " << imageA.Node[i].TopLeft.y << "\n";
    }
    cerr << "\n" ;
    for (int i = 0; i < a.size(); ++i) {
        cerr << imageB.Node[i].color << " " << imageB.Node[i].child[0][0] << " " << imageB.Node[i].child[0][1] << " "
        << imageB.Node[i].child[1][0] <<
        " " << imageB.Node[i].child[1][1] <<
        " " << imageB.Node[i].TopLeft.x <<
        " " << imageB.Node[i].TopLeft.y << "\n";
    }
    cerr << imageA.Find(0, 'W').x << " " << imageA.Find(0, 'W').y << "\n";
    cerr << imageA.Node[1].TopLeft.x << " " << imageA.Node[1].TopLeft.y << "\n";*/

    TPoint tmp = Diff(imageA, 0, imageB, 0);
    if (tmp == NP) printf("NO\n");
    else {
        cout << "YES\n" << tmp.x << " " << tmp.y << "\n";
    }
}
