// Config:
// 1. file "sol.cpp"
//   input stream: "sol.inp"
//   output stream: "sol.out"
// 2. folder "sol"
//   contain inital format test
// 3. Put this file in "sol" folder and run
// 4. Use Themis to judge

#include <bits/stdc++.h>
#include <windows.h>
using namespace std;

int main() {
  WIN32_FIND_DATA data;
  HANDLE hFind = FindFirstFile("*", &data);      // DIRECTORY

  if ( hFind != INVALID_HANDLE_VALUE ) {
    do {
    	string fn = data.cFileName;
    	int dot2 = fn.size() - 1;
      while (fn[dot2] != '.') dot2 --;
      int dot1 = dot2 - 1;
      while (fn[dot1] != '.') dot1 --;
      cerr << fn << " " << dot2 << " " << dot1 << "\n";

    	string id = fn.substr(dot2 + 1, fn.size() - dot2 - 1);
      if (!isdigit(id[0])) continue;
    	string type = fn.substr(dot1 + 1, dot2 - dot1 - 1);
      if (type == "in") type = "sol.inp";
      if (type == "out") type = "sol.out";

    	system(("mkdir " + id).c_str());
    	system(("move " + fn + " " + id + "\\" + type).c_str());
    } while (FindNextFile(hFind, &data));
    FindClose(hFind);
  }
}