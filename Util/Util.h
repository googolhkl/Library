#ifndef __UTIL_H__
#define __UTIL_H__
#include <random>

using namespace std;

namespace hkl{

    // random,확률 관련 클래스
        class rand{
            private:
            public:
            rand(){};
            ~rand(){};
            static long long MakeRangeNum();                                            //임의범위 난수 하나 발생
            static long long MakeRangeNum(const long long start,const long long end);   //지정범위 난수 하나 발생
            //todo
            static bool TrueOrFalse(const int       probability);                       // n%확률로 true 또는 or생성
            static bool TrueOrFalse(const double    probability);   
            
            static long long NumOfSuccess(const long long obj, const int    probability);// 성공횟수 확률
            static long long NumOfSuccess(const long long obj, const double probability);

            static long double MakeNearByNum(long long obj,long long deviation);        //표준편차
        };
}

#endif
