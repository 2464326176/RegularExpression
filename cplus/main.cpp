//********************
// Author:  yh 
// Time:    2021/6/14.
// 
//********************
//
#include <iostream>
#include <string>
#include <regex>
#include <fstream>
#include "CalculateCpuTime.h"
#include "CommonFunction.h"

using namespace std;

//正则优化

vector<string> fileSearch(string fileName, string regexStr) {
    ifstream iFile;
    string tmpStr;
    smatch pieces_match;
    vector<string> tmpVector;

    iFile.open(fileName.c_str(), std::fstream::in );
    if(!iFile.is_open()) {
        cout << "open" << fileName << "error" << endl;
    }
    /*while (getline(iFile, tmpStr)) {
        if (regex_search(tmpStr, pieces_match, regex(regexStr))) {
            cout << "string: " << tmpStr << endl;
            for (size_t i = 0; i < pieces_match.size(); ++i) {
                ssub_match sub_match = pieces_match[i];
                string piece = sub_match.str();
                tmpVector.push_back(piece);
                cout << "submatch : " << i << " " << piece << endl;
            }
        }
    }*/


    // 展示每个匹配中有标记子表达式的内容
    std::smatch color_match;
    while (getline(iFile, tmpStr)) {
        //cout << "tmpStr" << tmpStr << endl;
        if(std::regex_search(tmpStr, color_match, regex("\\d{2}\\.\\d{3}"))) {
            std::cout << "matches for '" << tmpStr << "'\n";
            std::cout << "Prefix: '" << color_match.prefix() << "'\n";
            for (size_t i = 0; i < color_match.size(); ++i)
                std::cout << i << ": " << color_match[i] << '\n';
            std::cout << "Suffix: '" << color_match.suffix() << "\'\n\n";
        }
    }
    iFile.close();

    return tmpVector;
}

int main(int argc, char *argv[]) {
    //cout << "File or Folder name: " << argv[1] << endl;
    string sFilePath = "../cplus/file/file.txt";
    CpuTime cpuTime;
    cpuTime.startCpUTime("regular");
    string regexStr = "\\d{2}\\.\\d{3}";

    fileSearch(sFilePath, "\\d{2}\\.\\d{3}");



    cpuTime.endCpuTime();
    return 0;
}