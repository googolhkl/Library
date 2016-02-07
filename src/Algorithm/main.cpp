#include "gradient.h"
#include <iostream>

int main(void){
    hkl::supervised::batchGD algo(5);
    algo.Input();
    std::cout<<"입력값을 분석한 결과 x=3000이면 결과는 : "<<algo.Result(3000)<<std::endl;

}
