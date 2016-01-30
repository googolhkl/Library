#include <iostream>
#include <UnitTest++.h>
#include "Util.h"

using namespace std;

int main(){
    return UnitTest::RunAllTests();
}

SUITE(totaltest){
    // MakeRangeNum테스트
    TEST(test1){
        if(hkl::rand::MakeRangeNum(1,10) ){
            CHECK(true);
        } else{
            CHECK(false);
        }
    }

    // TrueOrFalse테스트
    // 100%확률로 통과
    TEST(test2){
        if(hkl::rand::TrueOrFalse(100) ){
            CHECK(true);
        } else{
            CHECK(false);
        }
    }
    // 100%확률로 통과
    TEST ( test3 ){
        if(hkl::rand::TrueOrFalse(1.0) ){
            CHECK(true);
        } else{
            CHECK(false);
        }
    }
    
    // NumOfSuccess테스트
    TEST ( numofsuccess ){
        int num = hkl::rand::NumOfSuccess(1000,0.45);
        if(num){
            cout<<"num: "<<num<<endl;
            CHECK(true);
        } else{
            CHECK(false);
        }
    }
    TEST ( numofsuccess2 ){
        int num = hkl::rand::NumOfSuccess(1000,45);
        if(num){
            cout<<"num2: "<<num<<endl;
            CHECK(true);
        } else{
            CHECK(false);
        }
    }
    // MakeNearByNum테스트
}

