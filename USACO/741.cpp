#include <cstdlib>
#include <iostream>
#include <fstream>
#include <set>
#include <time.h>
#define REP(i, n) for (int i = 0; i < n; i++)
using namespace std;

const int N = 505;
int n, m;
string spotty[N], plain[N];
unsigned long long hash1[N], hash2[N], R[N];

int main(void) {
    srand(time(NULL));
    ifstream fin ("cownomics.in");
    ofstream fout ("cownomics.out");
    fin >> n >> m;
    REP(i, n) fin >> spotty[i];
    REP(i, n) fin >> plain[i];
    REP(i, m) R[i] = rand() % 1000000000;

    int i = 0, j = 0;
    int best = m;
    bool dups = 1;

    while (j < m) {
        if (dups == 0) best = min(best, j-i);
        if (dups) {
            set<unsigned long long> H;
            dups = 0;
            REP(k, n) H.insert(hash1[k] += R[j] * spotty[k][j]);
            REP(k, n) if (H.count(hash2[k] += R[j] * plain[k][j]) > 0) dups = 1;
            j++;
        } else {
            set<unsigned long long> H;
            dups = 0;
            REP(k, n) H.insert(hash1[k] -= R[i] * spotty[k][i]);
            REP(k, n) if (H.count(hash2[k] -= R[i] * plain[k][i]) > 0) dups = 1;
            i++;
        }
        //cerr << i << " " << j << "\n";
    }

    fout << best;
}
