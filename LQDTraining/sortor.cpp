#include <bits/stdc++.h>
#include <windows.h>
using namespace std;

#define path "d:\\codehub\\lqdtraining"

void command(string s) {
  system(s.c_str());
}

int main() {
  string folder, name, day, month, year;
  FILETIME ftCreate;
  SYSTEMTIME stUTC, stLocal;

  WIN32_FIND_DATA data;
  HANDLE hFind = FindFirstFile(path"\\*", &data);      // DIRECTORY

  if (hFind != INVALID_HANDLE_VALUE) {
    do {
      name = data.cFileName;
      cerr << name << '\n';
      if (name.find(".") == string::npos) continue;
      if (name.find("sortor") != string::npos) continue;
      cerr << "processing this file ...";
      GetFileTime(hFind, &ftCreate, NULL, NULL);
      FileTimeToSystemTime(&data.ftCreationTime, &stUTC);
      day = to_string(stUTC.wDay); while (day.size() < 2) day = '0' + day;
      month = to_string(stUTC.wMonth); while (month.size() < 2) month = '0' + month;
      year = to_string(stUTC.wYear);

      folder = year.substr(2, 2) + month + day;
      cerr << "making dir: " << "mkdir "path"\\" + folder << '\n';
      command("mkdir "path"\\" + folder);
      command("move "path"\\" + name + " "path"\\" + folder + "\\" + name);
    } while (FindNextFile(hFind, &data));
    FindClose(hFind);
  }
}