#include "Util.h"

long long hkl::rand::MakeRangeNum(){
    random_device ran;                                   //비결정적 난수 생성
    return ran();
}

long long hkl::rand::MakeRangeNum(const long long start,const long long end){
    random_device ran;                                   //비결정적 난수 생성
    mt19937_64 randNum( ran() );                         //비결정적 난수를 mt난수의 시드값으로
    uniform_int_distribution<long long> dist(start,end); //범위 생성
    return dist( randNum );
}
