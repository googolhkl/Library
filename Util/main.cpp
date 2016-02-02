#include <iostream>
#include <UnitTest++.h>
#include "Util.h"
#include "Time.h"

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
        if(hkl::rand::TrueOrFalse(100) ){   //100%확률로 true를 출력해주세요
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
        int num = hkl::rand::NumOfSuccess(1000,0.45);   // 1000명중 45%만이 지구탈출을 할수있다면 몇명이 탈출할수있을까?
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
    TEST ( makenearbynum){
        long double num = hkl::rand::MakeNearByNum(174,5);  //표준 키 174에서 +-5cm까지 출력
        if(num){
            cout<<">표준편차 : "<<num<<endl;
            CHECK(true);
        } else{
            CHECK(false);
        }
    }

    // Time테스트
    TEST ( timetest ){
        hkl::time timer;
        CHECK(timer.Yesterday());
        CHECK(timer.Today());
        CHECK(timer.Tomorrow());
        CHECK(timer.CurrentTime());
    }

    TEST ( timertest){
        hkl::timer::Start();
        for(int i=0; i<100000000; i++)
            i+=1;
        cout<<hkl::timer::End()<<endl;
        CHECK(hkl::timer::End());
    }
}
