#include <iostream>
#include <random>

using namespace std;

namespace hkl{

    class rand{
        private:
        public:
            rand(){}
            ~rand(){}
            static long long Generate(){
                random_device ran;                                   //비결정적 난수 생성
                return ran();
            }
            static long long Generate(const long long start,const long long end){    
                random_device ran;                                   //비결정적 난수 생성
                mt19937_64 randNum( ran() );                         //비결정적 난수를 mt난수의 시드값으로
                uniform_int_distribution<long long> dist(start,end); //범위 생성
                return dist( randNum );
            }
    };
}

using namespace hkl;

int main ()
{
    cout<< rand::Generate()<<endl;
    cout<< rand::Generate(0,10000000000000) << endl;
}
