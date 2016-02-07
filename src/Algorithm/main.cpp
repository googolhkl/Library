#include "gradient.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;
int main(void){
    char inputString[100];
    hkl::algorithm::batchGD algo(5);
    double input;
    cout<<"입력하세요: ";   cin>>input;

    // 파일에서 데이터를 받아옴
    ifstream inFile("data.dat");
    char * pch;
    bool flag= true;
    string number;
    int i=0;
    double temp;
    while(!inFile.eof()) {
        inFile.getline(inputString,100);
        pch = strtok ( inputString, ",");
        cout<<i<<"번째"<<endl;
        while(pch != NULL) { 
            number = pch;
            pch = strtok(NULL, ",");

            if(flag) {
                flag = false;
                temp = stod(number);
                algo.Setxv(temp,i);
            } else {
                flag = true;
                algo.Setyv(stod(number) ,i);
            }
        }
        i++;
    }   // 데이터 입력 끝   

    std::cout<<"입력데이터로 보아 "<<input<<"의 결과는: "<<algo.Result(input)<<std::endl;
}
