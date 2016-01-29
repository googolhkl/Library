#include <iostream>
#include <UnitTest++.h>
#include "Util.h"

using namespace std;

int main(){
    cout<<"hello world"<<endl;
    cout<< hkl::rand::Generate(1,10)<<endl;
    return UnitTest::RunAllTests();
}

SUITE(totaltest){
    TEST(test1){
        if(hkl::rand::Generate(1,10) ){
            CHECK(true);
        } else{
            CHECK(false);
        }
    }

    TEST(test2){
        if(hkl::rand::Generate(1,10) ){
            CHECK(true);
        } else{
            CHECK(false);
        }
    }
}

