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


//http://c.runoob.com/front-end/854
int main1() {
    string s = "Some people, when confronted with a problem, think "
               "\"I know, I'll use regular expressions.\" "
               "Now they have two problems.";

    regex self_regex("REGULAR EXPRESSIONS",
                     regex_constants::ECMAScript | regex_constants::icase);
    if (regex_search(s, self_regex)) {
        cout << "Text contains the phrase 'regular expressions'\n";
    }

    regex word_regex("(\\w+)");
    auto words_begin =
            sregex_iterator(s.begin(), s.end(), word_regex);
    auto words_end = sregex_iterator();

    cout << "Found "
         << distance(words_begin, words_end)
         << " words\n";

    const int N = 6;
    cout << "Words longer than " << N << " characters:\n";
    for (sregex_iterator i = words_begin; i != words_end; ++i) {
        smatch match = *i;
        string match_str = match.str();
        if (match_str.size() > N) {
            cout << "  " << match_str << '\n';
        }
    }

    regex long_word_regex("(\\w{7,})");
    string new_s = regex_replace(s, long_word_regex, "[$&]");
    cout << new_s << '\n';
    return 0;
}







int main(int argc, char *argv[]) {
    //cout << "File or Folder name: " << argv[1] << endl;
    string tmpStr;
    smatch pieces_match;
    string sFilePath = "1.txt";
    ifstream iFile;
    CpuTime cpuTime;

    cpuTime.startCpUTime("regular");

    regex function_regex(".*\\d{1}\\s+[a-zA-Z_0-9*]+\\s+[a-zA-Z_0-9*]+\\(.*\\).*");

    iFile.open(sFilePath.c_str(), std::fstream::in | std::fstream::out | std::fstream::app);

    while (getline(iFile, tmpStr)) {
        if (regex_match(tmpStr, pieces_match, function_regex)) {
            cout << "string: " << tmpStr << endl;
            for (size_t i = 0; i < pieces_match.size(); ++i) {
                ssub_match sub_match = pieces_match[i];
                string piece = sub_match.str();
                cout << "submatch : " << i << " " << piece << endl;
            }
        }
    }

    iFile.close();
    cpuTime.endCpuTime();
    system("pause");
    return 0;
}