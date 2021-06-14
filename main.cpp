//********************
// Author:  yh 
// Time:    2021/6/14.
// 
//********************
//
#include <iostream>
#include <iterator>
#include <string>
#include <regex>
#include <ctime>
#include <cstdio>
#include <fstream>
#include <windows.h>

using namespace std;


//http://c.runoob.com/front-end/854
int main1() {
    std::string s = "Some people, when confronted with a problem, think "
                    "\"I know, I'll use regular expressions.\" "
                    "Now they have two problems.";

    std::regex self_regex("REGULAR EXPRESSIONS",
                          std::regex_constants::ECMAScript | std::regex_constants::icase);
    if (std::regex_search(s, self_regex)) {
        std::cout << "Text contains the phrase 'regular expressions'\n";
    }

    std::regex word_regex("(\\w+)");
    auto words_begin =
            std::sregex_iterator(s.begin(), s.end(), word_regex);
    auto words_end = std::sregex_iterator();

    std::cout << "Found "
              << std::distance(words_begin, words_end)
              << " words\n";

    const int N = 6;
    std::cout << "Words longer than " << N << " characters:\n";
    for (std::sregex_iterator i = words_begin; i != words_end; ++i) {
        std::smatch match = *i;
        std::string match_str = match.str();
        if (match_str.size() > N) {
            std::cout << "  " << match_str << '\n';
        }
    }

    std::regex long_word_regex("(\\w{7,})");
    std::string new_s = std::regex_replace(s, long_word_regex, "[$&]");
    std::cout << new_s << '\n';
    return 0;
}

class CpuTime {
public:
    CpuTime(string name) {
        m_name = name;
        m_start_t = clock();
    }

    void startCpUTime(string name) {
        m_name = name;
        m_start_t = clock();
    };

    void getCpuTime() {
        m_end_t = clock();
        double total_t = (double) (m_start_t - m_end_t) / CLOCKS_PER_SEC;
        printf("CPU time: %f", total_t);
    }

private:
    string m_name;
    clock_t m_start_t;
    clock_t m_end_t;
};

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

void echoStr(string str) {
    cout << str << endl;
}
//4	double difftime(time_t time1, time_t time2)
int main(int argc, char *argv[]) {
    //cout << "File or Folder name: " << argv[1] << endl;

    regex function_regex(".*\\d{1}\\s+[a-zA-Z_0-9*]+\\s+[a-zA-Z_0-9*]+\\(.*\\).*");

    string sFilePath = "C:/Users/Administrator/Desktop/myGithubCode/RegularExpression/cmake-build-debug/log.txt";
    ifstream iFile;
    iFile.open(sFilePath.c_str(), ios::out | ios::in | ios::binary);

    string tmpStr;
    smatch pieces_match;
    while (getline(iFile, tmpStr)) {
        tmpStr = UTF8ToGB(tmpStr.c_str());
//        tmpStr = "1\tchar *asctime(const struct tm *timeptr)";
        if(regex_match(tmpStr, pieces_match, function_regex)) {
            cout << "string: " << tmpStr << endl;
            for (size_t i = 0; i < pieces_match.size(); ++i) {
                ssub_match sub_match = pieces_match[i];
                string piece = sub_match.str();
                cout << "submatch : " << i << piece << endl;
            }
        }
    }

    iFile.close();

    system("pause");
    return 0;
}