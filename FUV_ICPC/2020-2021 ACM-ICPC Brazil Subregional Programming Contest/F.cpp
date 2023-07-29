#include <bits/stdc++.h>
using namespace std;

int serving = 0, score[2], wins[2];

bool does_win(int candidate) {
	int opponent = candidate ^ 1;
	if (score[candidate] >= 5 && score[candidate] - score[opponent] >= 2) {
		return true;
	}
	if (score[candidate] == 10) {
		return true;
	}
	return false;
}

void scoring(int winner) {
	score[winner] ++;
	if (does_win(winner)) {
		wins[winner] ++;
		score[0] = score[1] = 0;
	}
	serving = winner;
	// printf("after score: %d %d %d %d\n", wins[0], score[0], wins[1], score[1]);
}

bool end_game() {
	if (wins[0] + wins[1] == 3) return true;
	if (abs(wins[0] - wins[1]) == 2) return true;
	return false;
}

void show_status() {
	if (end_game()) {
		if (wins[0] > wins[1])
			printf("%d (winner) - %d\n", wins[0], wins[1]);
		else
			printf("%d - %d (winner)\n", wins[0], wins[1]);
	} else {
		if (serving == 0)
			printf("%d (%d*) - %d (%d)\n", wins[0], score[0], wins[1], score[1]);
		else
			printf("%d (%d) - %d (%d*)\n", wins[0], score[0], wins[1], score[1]);
	}
}

int main() {
	char c;
	while (cin >> c) {
		if (c == 'Q') {
			show_status();
		} else {
			if (c == 'S') scoring(serving);
			else scoring(serving ^ 1);
		}
	}
}