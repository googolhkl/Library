#include "Util.h"

namespace hkl {
    //MakeRangeNum
    long long rand::MakeRangeNum() {
        std::random_device ran;                                   //비결정적 난수 생성
        return ran();
    }

    long long rand::MakeRangeNum(const long long start,const long long end) {
        std::random_device ran;                                   //비결정적 난수 생성
        std::mt19937_64 randNum( ran() );                         //비결정적 난수를 mt난수의 시드값으로
        std::uniform_int_distribution<long long> dist(start,end); //범위 생성
        return dist( randNum );
    }

    //TrueOrFalse
    bool rand::TrueOrFalse(int probability) {
        double ratio = static_cast<double>( probability/static_cast<double>(100) );
        std::random_device ran;                                   //비결정적 난수 생성
        std::bernoulli_distribution dist(ratio);             // ratio의 확률
        return dist(ran);
    }

    bool rand::TrueOrFalse(const double probability) {
        std::random_device ran;
        std::bernoulli_distribution dist(probability);
        return dist(ran);
    }

    //NumOfSuccess
    long long rand::NumOfSuccess(const long long obj, const int probability) throw(int) {
        if (( probability<0) || (probability>100))
            throw probability;

        int pro = probability;
        double ratio = static_cast<double>(pro/static_cast<double>(100));
        std::random_device ran;                 // 비결정적 난수 생성
        std::binomial_distribution<> dist(obj,ratio);
        return dist(ran);
    }

    long long rand::NumOfSuccess(const long long obj, const double probability) {
        std::random_device ran;                 // 비결정적 난수 생성
        std::binomial_distribution<> dist(obj,probability);
        return dist(ran);
    }

    //MakeNearByNum
    long double rand::MakeNearByNum(long long obj, long long deviation) {
        std::random_device ran;                 // 비결정적 난수 생성
        std::normal_distribution<> dist(obj,deviation); //정규분포
        return dist(ran);
    }
}
