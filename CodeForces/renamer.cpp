#include <bits/stdc++.h>
#include <windows.h>
using namespace std;

int main() {
	string prob, contest, ext;
    WIN32_FIND_DATA data;
    HANDLE hFind = FindFirstFile("D:\\CodeHub\\CodeForces\\*", &data);  // DIRECTORY

    if ( hFind != INVALID_HANDLE_VALUE ) {
      do {
        // std::cout << data.cFileName << std::endl;
      	string tmp = data.cFileName;
        if (isalpha(tmp[0])) continue;
      	cerr << tmp << "\n";
        if (tmp.size() == 2) {
          system(("move " + tmp + " 00
            " + tmp).c_str());
        }
      } while (FindNextFile(hFind, &data));
      FindClose(hFind);
    }
}