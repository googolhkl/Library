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
    class time{
    private:
        //멤버 변수
        time_t startTime=0;
        struct tm * tmp=nullptr;
        array<wchar_t, WBUFFER_SIZE> buffer;
        //멤버 함수
        time_t* SystemTime();
        struct tm*  TimeToTm(int day);
        
    public:
        //멤버 함수
        time(){}
        ~time(){}
        bool Today();
        bool Yesterday();
        bool Tomorrow();
        bool Day(int day);
        bool CurrentTime();
    };
}


#endif
