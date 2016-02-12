/* 작성자 : 이경훈
 * 설명 : Util폴더에 있는 라이브러리들의 단위테스트입니다.
 *        이 테스트가 곧 사용법이라고 보시면 되겠습니다. 
 */
#include <iostream>
#include <UnitTest++.h>
#include "gradient.h"

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
        gradient t1("datax.txt","datay.txt");
        cout<<t1.GetResult()<<endl;
        CHECK(true);
    }

}
