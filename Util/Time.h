#ifndef __TIME_H__
#define __TIME_H__
#include <ctime>
#include <chrono>
#include <array>

using namespace std;

// 시간 포맷은 아래 링크
// http://www.cplusplus.com/reference/ctime/strftime/
#define DATETIME_FORMAT     L"%Y-%m-%d %A %r"
#define TIME_FORMAT         L"%H:%M:%S"
#define DATE_FORMAT         L"%Y-%m-%d %A"
#define DB_FORMAT           L"%Y-%m-%d %H:%M:%S"

#define WBUFFER_SIZE            120

#define YESTERDAY -1
#define TODAY      0
#define TOMORROW   1

namespace hkl{
        array<wchar_t, WBUFFER_SIZE> buffer;
    class time{
    private:
        //멤버 변수
        static time_t startTime;
        static struct tm * tmp;
        //static array<wchar_t, WBUFFER_SIZE> buffer;
        //멤버 함수
        static time_t* SystemTime();
        static struct tm*  TimeToTm(int day);
        
    public:
        //멤버 함수
        time(){}
        ~time(){}
        static bool Today();
        static bool Yesterday();
        static bool Tomorrow();
        static bool Day(int day);
        static bool CurrentTime();
    };
    time_t time::startTime=0;
    struct tm * time::tmp=nullptr;

    class timer{
        private:
            static chrono::system_clock::time_point start;
        public:
            static void Start();
            static double End();
    };
    chrono::system_clock::time_point timer::start = std::chrono::system_clock::now();
}


#endif
