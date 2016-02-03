#ifndef HKLLIBRARY_SRC_UTIL_TIME_H
#define HKLLIBRARY_SRC_UTIL_TIME_H
#include <ctime>
#include <chrono>
#include <array>

// 시간 포맷은 아래 링크
// http://www.cplusplus.com/reference/ctime/strftime/
#define DATETIME_FORMAT     L"%Y-%m-%d %A %r"
#define TIME_FORMAT         L"%H:%M:%S"
#define DATE_FORMAT         L"%Y-%m-%d %A"
#define DB_FORMAT           L"%Y-%m-%d %H:%M:%S"

#define WBUFFER_SIZE              120

#define YESTERDAY -1
#define TODAY      0
#define TOMORROW   1

namespace hkl {
class time {
    public:
        //멤버 함수
        time() {}
        ~time() {}
        static bool Today();
        static bool Yesterday();
        static bool Tomorrow();
        static bool Day(int day);
        static bool CurrentTime();
    private:
        //멤버 변수
        static time_t startTime;
        static struct tm * tmp;
        static std::array<wchar_t, WBUFFER_SIZE> buffer;
        //멤버 함수
        static time_t* SystemTime();
        static struct tm*  TimeToTm(int day);
};
time_t time::startTime=0;
struct tm * time::tmp=nullptr;
std::array<wchar_t, WBUFFER_SIZE> time::buffer;

class timer {
    public:
        static void Start();
        static double End();
    private:
        static std::chrono::system_clock::time_point start;
};
std::chrono::system_clock::time_point timer::start = std::chrono::system_clock::now();
}


#endif  // HKLLIBRARY_SRC_UTIL_TIME_H
