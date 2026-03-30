#include <iostream>
#include <string>
#include <io.h>
#include <fcntl.h>
#include<bits/stdc++.h>
using namespace std;
int main() {
    // 设置控制台为宽字符模式
    _setmode(_fileno(stdout), _O_U16TEXT);
    _setmode(_fileno(stdin), _O_U16TEXT);
    _setmode(_fileno(stderr), _O_U16TEXT);
    vector<wstring> man;
    while(1)
        {
            wstring s,ls;
            getline(wcin,s);
            if(s[0]=='0') break;
            for(auto tmp:s) ls+=tmp,ls+=tmp;
            man.push_back(ls);
        }
    for(auto tmp:man)
    {
        wcout<<tmp<<endl;
    }
    return 0;
}
//using chcp 65001 in your terminal