#include "Time.h"

/* 아래 두 함수는 private 함수  */
time_t* hkl::time::SystemTime(){
    startTime =std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
    return &startTime;
}

struct tm* hkl::time::TimeToTm(int day){
    tmp = localtime(SystemTime());
    tmp->tm_mday += day;
    tmp->tm_wday += day;
    mktime( tmp );          // 윤년도 계산
    return tmp;
}

/* 아래 함수들은 public 함수  */
bool hkl::time::Today(){
    tmp = TimeToTm(TODAY);
    wcsftime(buffer.data(),buffer.size(),DATE_FORMAT, tmp);    //원하는 포맷으로 설정
    wprintf(L"%ls\n", buffer.data());
    return true;
}

bool hkl::time::Yesterday(){
    tmp = TimeToTm(YESTERDAY);
    wcsftime(buffer.data(),buffer.size(),DATE_FORMAT, tmp);    //원하는 포맷으로 설정
    wprintf(L"%ls\n", buffer.data());
    return true;
}

bool hkl::time::Tomorrow(){
    tmp = TimeToTm(TOMORROW);
    wcsftime(buffer.data(),buffer.size(),DATE_FORMAT, tmp);    //원하는 포맷으로 설정
    wprintf(L"%ls\n", buffer.data());
    return true;
}

bool hkl::time::Day(int day){
    tmp = TimeToTm(day);
    wcsftime(buffer.data(),buffer.size(),DATETIME_FORMAT, tmp);    //원하는 포맷으로 설정
    wprintf(L"%ls\n", buffer.data());
    return true;
}


bool hkl::time::CurrentTime(){
    tmp = TimeToTm(TODAY);
    wcsftime(buffer.data(),buffer.size(),TIME_FORMAT, tmp);    //원하는 포맷으로 설정
    wprintf(L"%ls\n", buffer.data());
    return true;
}


void hkl::timer::Start(){
    start = std::chrono::system_clock::now();
}

double hkl::timer::End(){
    std::chrono::duration<double> sec = std::chrono::system_clock::now() - start;
    return sec.count();
}
