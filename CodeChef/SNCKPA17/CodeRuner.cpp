#include <bits/stdc++.h>
using namespace std;
int main()
{
    string folder, file, set_folder, compile, run;
    cin>>folder;
    cin>>file;
    set_folder="cd \"C:\\Users\\admin\\Google Drive\\CODE_CPP\\"+file+"\"";
    compile="g++ -o "+file+".exe "+file+".cpp";
    run=file+".exe";
    system("color A");
    system(set_folder.c_str());
    system(compile.c_str());
    system(run.c_str());
}
