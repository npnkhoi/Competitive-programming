#include <bits/stdc++.h>
using namespace std;

char mat[10][10];

const int dx[8] = {0, 0, 1, -1, 1, 1, -1, -1};
const int dy[8] = {-1, 1, 0, 0, -1, 1, 1, -1};

const int mx[8] = {-2, -1, -2, -1, 2, 1, 2, 1};
const int my[8] = {-1, -2, 1, 2, -1, -2, 1, 2};

pair<int, int> vuaDen;
bool djtme = false;

bool inBoard(int x, int y) {
	return (1 <= x) && (x <= 8) && (1 <= y) && (y <= 8);
}

void showBoard() {
	for (int i = 1; i <= 8; ++ i) {
		for (int j = 1; j <= 8; ++ j) {
			cout << mat[i][j] << ' ';
		}
		cout << '\n';
	}
	cout << '\n';
}

pair<int, int> translate(char xx, char yy) {
  return make_pair(
    8 - (yy - '0') + 1, 
    xx - 'a' + 1
  );
}

void init(vector <string> pos) {
  for (int i = 1; i <= 8; ++i) {
    for (int j = 1; j <= 8; ++j)
      mat[i][j] = '.';
  }

  for (string x : pos) {
    pair<int, int> p = translate(x[1], x[2]);
    mat[p.first][p.second] = x[0];
    if (x[0] == 'K') {
      vuaDen = p;
    }
  }
}

int u, v;

bool inc_uv() {
	if (v == 8) {
		if (u == 8) {
			u = 1; v = 1;
			return false;
		} else {
			u ++;
			v = 1;
		}
	} else v ++;
	return true;
}

bool find(char piece) {
	while (inc_uv()) {
		if (mat[u][v] == piece) {
			return true;
		}
	}
	return false;
}

bool check_diag(int x, int y, int u, int v) {
	if (x - y == u - v) {
		if (x > u) {
			swap(x, u);
			swap(y, v);
		}
		for (int i = x + 1; i < u; ++ i) {
			if (mat[i][i - (x - y)] != '.') return false;
		}
		return true;
	} else if (x + y == u + v) {
		if (x > u) {
			swap(x, u);
			swap(y, v);
		}
		for (int i = x + 1; i < u; ++ i) {
			if (mat[i][(x + y) - i] != '.') return false;
		}
		return true;
	} else return false;
}

bool check_line(int x, int y, int u, int v) {
	if (x == u) {
		if (y > v) swap(y, v);
		for (int j = y + 1; j < v; ++ j) {
			if (mat[x][j] != '.') return false;
		}
		return true;
	} else if (y == v) {
		if (x > u) swap(x, u);
		for (int i = x + 1; i < u; ++ i) {
			if (mat[i][y] != '.') return false;
		}
		return true;
	} else return false;
}

bool reachable(int x, int y) {
	// check if (x, y) is in control
	u = v = 1;
	// cerr << "after nothing\n";
	// check king
	find('k');
	if (abs(vuaDen.first - u) <= 1 && abs(vuaDen.second - v) <= 1) {
		return true;
	}
	// if (djtme) cerr << "after k\n";
	// check queen
	u = v = 1;
	if (find('q')) {
		if (check_diag(u, v, vuaDen.first, vuaDen.second)) return true;
		if (check_line(u, v, vuaDen.first, vuaDen.second)) return true;
	}
	// if (djtme) cerr << "after q\n";
	// check bishop
	u = v = 1;
	do {
		if (check_diag(u, v, vuaDen.first, vuaDen.second)) return true;
	} while (find('b'));
	// if (djtme) cerr << "after b\n";
	// check knight
	u = v = 1;
	do {
		int i = abs(u - vuaDen.first), j = abs(v - vuaDen.second);
		if (i == 2 && j == 3) return true;
		if (i == 3 && j == 2) return true;
	} while (find('n'));
	// if (djtme) cerr << "after n\n";
	// check rook
	u = v = 1;
	do {
		// if (djtme) cerr << u << ' ' << v << '\n';
		if (check_line(u, v, vuaDen.first, vuaDen.second)) return true;
	} while (find('r'));
	// if (djtme) cerr << "after r\n";
	return false;
}

bool check() { // check_mate
	// if (djtme) showBoard();
	for (int dx = -1; dx <= 1; ++ dx) {
		for (int dy = -1; dy <= 1; ++ dy) {
			if (dx == 0 && dy == 0) continue;

			int tmp_x = vuaDen.first + dx, tmp_y = vuaDen.second + dy;
			if (!inBoard(tmp_x, tmp_y)) continue;

			char old_piece = mat[tmp_x][tmp_y];
			pair<int, int> old_king = vuaDen;

			mat[tmp_x][tmp_y] = 'K';
			mat[vuaDen.first][vuaDen.second] = '.';

			if (!reachable(vuaDen.first, vuaDen.second)) {
				mat[old_king.first][old_king.second] = 'K';
				mat[tmp_x][tmp_y] = old_piece;
				// vuaDen.first -= dx;
				// vuaDen.second -= dy;
				if (djtme) {
					// showBoard();
					// cerr << tmp_x << ' ' << tmp_y << '\n';
 				}
				return false;
			}

			mat[old_king.first][old_king.second] = 'K';
			mat[tmp_x][tmp_y] = old_piece;
			// vuaDen.first -= dx;
			// vuaDen.second -= dy;
		}
	}
	return true;
}

bool diVua(char xx, char yy) {
  pair<int, int> p = translate(xx, yy);
  int x = p.first, y = p.second;
  for (int i = 0; i < 4; ++i) {
    int u = x + dx[i];
    int v = y + dy[i];
    if (inBoard(u, v) && mat[u][v] == '.') {
      swap(mat[u][v], mat[x][y]);
      if (check()) return true;
      swap(mat[u][v], mat[x][y]);
    }
  }
  return false;
}

bool diTuong(char xx, char yy) {
  pair<int, int> p = translate(xx, yy);
  int x = p.first, y = p.second;
  for (int i = 4; i < 8; ++i) {
    for (int j = 1; j <= 8; ++j) {
      int u = x + dx[i] * j;
      int v = y + dy[i] * j;
      if (!inBoard(u, v)) break;
      if (mat[u][v] != '.') break;
      
      swap(mat[u][v], mat[x][y]);
      if (check()) return true;
      swap(mat[u][v], mat[x][y]);
    }
  }
  return false;
}

bool diXe(char xx, char yy) {
  pair<int, int> p = translate(xx, yy);
  int x = p.first, y = p.second;
	// cerr << "Toa do xe: " << x << ' ' << y << '\n';
  for (int i = 0; i < 4; ++i) {
    for (int j = 1; j <= 8; ++j) {
      int u = x + dx[i] * j;
      int v = y + dy[i] * j;
      if (!inBoard(u, v)) break;
      if (mat[u][v] != '.') break;
      
      swap(mat[u][v], mat[x][y]);

      djtme = (u == 1 && v == 1);
      if (check()) return true;
      // else if (djtme)
      swap(mat[u][v], mat[x][y]);
    }
  }
  return false;
}

bool diHau(char xx, char yy) {
	// cerr << diXe(xx, yy) << ' ' << diTuong(xx, yy) << '\n';
  return (diXe(xx, yy) || diTuong(xx, yy));
}

bool diMa(char xx, char yy) {
  pair<int, int> p = translate(xx, yy);
  int x = p.first, y = p.second;
  for (int i = 0; i < 8; ++i) {
    int u = x + mx[i];
    int v = y + my[i];
    if (inBoard(u, v) && mat[u][v] == '.') {
      swap(mat[u][v], mat[x][y]);
      if (check()) {
      	// cerr << "O DAY NEEEEEEEEEEEE\n";
      	// showBoard();
      	return true;
      }
      swap(mat[u][v], mat[x][y]);
    }
  }
  return false;
}

bool isOneMoveCheckMate(std::vector<std::string> pos) {
  init(pos);
  for (string x : pos) {
    if (x[0] == 'k') {
    	if (diVua(x[1], x[2])) {
    		// cerr << "djtme Vua\n";
    		return true; 
    	}
    } else if (x[0] == 'q') {
    	if (diHau(x[1], x[2])) {
    		// cerr << "djtme Hau\n";
    		return true; 
    	}
    } else if (x[0] == 'r') {
    	if (diXe(x[1], x[2])) {
    		// cerr << "djtme Xe\n";
    		return true; 
    	}
    } else if (x[0] == 'b') {
    	if (diTuong(x[1], x[2])) {
    		// cerr << "djtme Tuong\n";
    		return true; 
    	}
    } else if (x[0] == 'n') {
    	if (diMa(x[1], x[2])) {
    		// cerr << "djtme Ma\n";
    		return true;
    	}
    }
  }
  return false;
}

int main() {
	freopen("out.txt", "w", stdout);
	std::vector<std::string> pos = {"Kh8","kd1","ra6","rb7"};
	cerr << isOneMoveCheckMate(pos);
}
