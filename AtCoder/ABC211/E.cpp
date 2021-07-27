#include <bits/stdc++.h>
using namespace std;

const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

typedef unsigned long long Shape;
set<Shape> shapes[2];
int n, k, curr = 0;
Shape board;

int getIndex(int row, int col) {
    return row * 8 + col;
}

int getBit(Shape mask, int row, int col) {
    return mask >> getIndex(row, col) & 1;
}

int getRow(Shape mask, int row) {
    int res = 0;
    for (int j = 0; j < 8; ++j) {
        res |= (getBit(mask, row, j) << j);
    }
    return res;
}

int getCol(Shape mask, int col) {
    int res = 0;
    for (int i = 0; i < 8; ++i) {
        res |= (getBit(mask, i, col) << i);
    }
    return res;
}

bool inBoard(int row, int col) {
    return 0 <= row && row < 8 && 0 <= col && col < 8;
}

Shape add(Shape mask, int row, int col) {
    return mask | (1LL << getIndex(row, col));
}

Shape shiftCol(Shape mask) {
    Shape tmp = 0;
    for (int i = 0; i < 9; ++ i) {
        for (int j = 0; j < 7; ++ j) {
            if (getBit(mask, i, j)) {
                tmp = add(tmp, i, j+1);
            }
        }
    }
    return tmp;
}

void generate() {
    shapes[0] = {1};

    for (int i = 2; i <= k; ++ i) {
        int prev = curr;
        curr ^= 1;

        shapes[curr].clear();
        // generate new shape
        for (Shape oldShape : shapes[prev]) {
            
            // Bottom and right
            for (int i = 0 ; i < 8; ++ i) {
                for (int j = 0; j < 8; ++ j) {
                    if (getBit(oldShape, i, j)) {
                        continue;
                    }
                    bool adj = false;
                    for (int dir = 0; dir < 4; ++ dir) {
                        int u = i + dx[dir], v = j + dy[dir];
                        if (!inBoard(u, v)) {
                            continue;
                        }
                        if (getBit(oldShape, u, v)) {
                            adj = true;
                        }
                    }
                    if (!adj) {
                        continue;
                    }
                    shapes[curr].insert(add(oldShape, i, j));
                }
            }

            // Top
            if (getRow(oldShape, 7) == 0) {
                Shape tmp = oldShape << 8;
                for (int j = 0; j < 8; ++ j) {
                    if (getBit(tmp, 1, j)) {
                        shapes[curr].insert(add(tmp, 0, j));
                    }
                }
            }

            // Left
            if (getCol(oldShape, 7) == 0) {
                Shape tmp = shiftCol(oldShape);
                for (int i = 0; i < 8; ++ i) {
                    if (getBit(tmp, i, 1)) {
                        shapes[curr].insert(add(tmp, i, 0));
                    }
                }
            }
        }
        // cout << shapes[curr].size() << '\n';
        // for (Shape shape : shapes[curr]) {
        //     int cntBit = __builtin_popcountll(shape);
        //     if (cntBit != i) {
        //         cout << "WRONG BELOW\n";
        //     }
        //     for (int i = 0; i < 8; ++ i) {
        //         for (int j = 0; j < 8; ++ j) {
        //             cout << getBit(shape, i, j);
        //         }
        //         cout << '\n';
        //     }
        //     cout << '\n';
        // }
        // cout << '\n';
    }
}

void showBoard(Shape shape) {
    cout << "Showing " << shape << '\n';
    cout << '\n';
    for (int i = 0; i < 8; ++ i) {
        for (int j = 0; j < 8; ++ j) {
            cout << (getBit(shape, i, j) ? '#' : '.');
        }
        cout << '\n';
    }
    cout << '\n';
}

int main() {
    // Shape foo = 1LL << 63;
    // cerr << (foo << 1);
    // freopen("E.inp", "r", stdin);
    // freopen("E.out", "w", stdout);
    cin >> n >> k;
    for (int i = 0; i < n; ++ i) {
        string s;
        cin >> s;
        for (int j = 0; j < n; ++ j) {
            if (s[j] == '.') {
                board = add(board, i, j);
            }
        }
    }
    // showBoard(board);

    generate();
    // cout << shapes[curr].size() << '\n';
    
    int result = 0;
    for (Shape shape : shapes[curr]) {
        // MATCH
        // showBoard(shape);
        for (int i = 0; i < 8; ++ i) {
            Shape tmp = shape << (8 * i);
            for (int j = 0; j < 8; ++ j) {
                if (j != 0) {
                    tmp = shiftCol(tmp);
                }
                // cout << tmp << '&' << board << '=' << (tmp & board) << " => " << __builtin_popcountll(tmp & board) << '\n';
                result += (__builtin_popcountll(tmp & board) == k);

            }
        }
        // cout << '\n';
    }
    cout << result;
}