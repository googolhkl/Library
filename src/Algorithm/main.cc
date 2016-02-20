/* 작성자 : 이경훈
 * 설명 : Util폴더에 있는 라이브러리들의 단위테스트입니다.
 *        이 테스트가 곧 사용법이라고 보시면 되겠습니다. 
 */
#include <iostream>
#include <UnitTest++.h>
#include "algorithm.h"

using namespace std;
using namespace hkl::algorithm;

int main () {
    return UnitTest::RunAllTests();
}

SUITE (totaltest) {
    TEST(test1) {
        CHECK(true);
    }

    TEST(test2) {
        cout<<"hello"<<endl;
        hkl::algorithm::linear t1("datax.txt","datay.txt");
        cout<< t1.GetResult() <<endl;

        t1.SetIteration(100000);
        t1.SetAlpha(0.0000001);
        cout<< t1.GetResult() <<endl;

        CHECK(true);
    }

}
