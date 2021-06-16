//********************
// Author:  yh 
// Time:    2021/6/16.
// 
//********************
//

#include "CommonFunction.h"
#include <windows.h>
#include <codecvt>



void echoStr(string str) {
    cout << str << endl;
}

string UTF8ToGB(const char *str) {
    string result;
    WCHAR *strSrc;
    LPSTR szRes;

    int i = MultiByteToWideChar(CP_UTF8, 0, str, -1, NULL, 0);
    strSrc = new WCHAR[i + 1];
    MultiByteToWideChar(CP_UTF8, 0, str, -1, strSrc, i);

    i = WideCharToMultiByte(CP_ACP, 0, strSrc, -1, NULL, 0, NULL, NULL);
    szRes = new CHAR[i + 1];
    WideCharToMultiByte(CP_ACP, 0, strSrc, -1, szRes, i, NULL, NULL);

    result = szRes;
    delete[]strSrc;
    delete[]szRes;

    return result;
}