#include "Time.h"

namespace hkl {

/* 아래 함수들은 public 함수  */
    bool time::Today() {
        tmp = TimeToTm(TODAY);
        wcsftime(buffer.data(),buffer.size(),DATE_FORMAT, tmp);    //원하는 포맷으로 설정
        wprintf(L"%ls\n", buffer.data());
        return true;
    }

    bool time::Yesterday() {
        tmp = TimeToTm(YESTERDAY);
        wcsftime(buffer.data(),buffer.size(),DATE_FORMAT, tmp);    //원하는 포맷으로 설정
        wprintf(L"%ls\n", buffer.data());
        return true;
    }

    bool time::Tomorrow() {
        tmp = TimeToTm(TOMORROW);
        wcsftime(buffer.data(),buffer.size(),DATE_FORMAT, tmp);    //원하는 포맷으로 설정
        wprintf(L"%ls\n", buffer.data());
        return true;
    }

    bool time::Day(int day) {
        tmp = TimeToTm(day);
        wcsftime(buffer.data(),buffer.size(),DATETIME_FORMAT, tmp);    //원하는 포맷으로 설정
        wprintf(L"%ls\n", buffer.data());
        return true;
    }


    bool time::CurrentTime() {
        tmp = TimeToTm(TODAY);
        wcsftime(buffer.data(),buffer.size(),TIME_FORMAT, tmp);    //원하는 포맷으로 설정
        wprintf(L"%ls\n", buffer.data());
        return true;
    }


    void timer::Start() {
        start = std::chrono::system_clock::now();
    }

    double timer::End() {
        std::chrono::duration<double> sec = std::chrono::system_clock::now() - start;
        return sec.count();
    }

    /* 아래 두 함수는 private 함수  */
    time_t* time::SystemTime() {
        startTime =std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
        return &startTime;
    }

    struct tm* time::TimeToTm(int day) {
        tmp = localtime(SystemTime());
        tmp->tm_mday += day;
        tmp->tm_wday += day;
        mktime( tmp );          // 윤년도 계산
        return tmp;
    }
}
