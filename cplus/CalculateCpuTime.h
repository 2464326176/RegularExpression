//********************
// Author:  yh 
// Time:    2021/6/16.
// 
//********************
//

#ifndef REGULAREXPRESSION_CALCULATECPUTIME_H
#define REGULAREXPRESSION_CALCULATECPUTIME_H
#include <ctime>
#include <cstdio>
#include <string>

using namespace std;
class CpuTime {
public:
    CpuTime(string name) {
        m_name = name;
        m_start_t = clock();
    }

    CpuTime() {

    }

    void startCpUTime(string name) {
        m_name = name;
        m_start_t = clock();
    };

    void endCpuTime() {
        m_end_t = clock();
        double total_t = (double) (m_end_t - m_start_t) / CLOCKS_PER_SEC;
        printf("%s process of CPU time: %f\n", m_name.c_str(), total_t);
    }

private:
    string m_name;
    clock_t m_start_t;
    clock_t m_end_t;
};
#endif //REGULAREXPRESSION_CALCULATECPUTIME_H
