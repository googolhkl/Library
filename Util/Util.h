#ifndef __UTIL_H__
#define __UTIL_H__
#include <random>

using namespace std;

namespace hkl{

        class rand{
            private:
            public:
            rand(){};
            ~rand(){};
            static long long Generate();                                            //임의범위 난수 하나 발생
            static long long Generate(const long long start,const long long end);   //지정범위 난수 하나 발생
        };
}

#endif
