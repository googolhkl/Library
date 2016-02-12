#include "file.h"
#include <iostream>
using namespace std;

namespace hkl {
file::file() {
    filename_ = "data.txt";
    m_.resize(1,1);
}

file::file(const string filename) :filename_(filename){
    m_.resize(1,1);
}

file::~file(){
}

bool file::SetFileName(const string filename) {
    filename_ = filename;
    return true;
}

Eigen::MatrixXd file::Size() {
    numOfRow_=1;
    numOfCol_=1;
    fin_.open(filename_);
    if(!fin_) { 
        cout<<"input failed"<<endl;
        exit(-1);
    }

    char tempStr[1024];
    while(fin_.getline(tempStr,1024)) {
        string tempString = tempStr;     //char -> string
        string token;
        stringstream stream(tempString);
        while(stream >> token) {
            numOfCol_++;
        }
        numOfRow_++;
    }
    numOfRow_--;
    numOfCol_ = (numOfCol_-1)/numOfRow_;

    Eigen::MatrixXd tempM(1,2);         // [ row column ] matrix 생성
    tempM(0,0) = numOfRow_;
    tempM(0,1) = numOfCol_;
    fin_.close();
    return tempM;                       // matrix에는 datafile의 정보가 들어가있음
}

Eigen::MatrixXd file::Read() {
    Size();
    fin_.open(filename_);
    m_.resize(numOfRow_,numOfCol_);     // m*n matrix생성 

    char tempStr[1024];
    string tempString;
    string token;
    //데이터 입력
    for(int i=0; i<numOfRow_; i++) {
        fin_.getline(tempStr,1024);
        tempString = tempStr;
        stringstream stream(tempString);
        for(int j=0; j<numOfCol_; j++) {
            stream >> token;
            m_(i,j) = stod(token,0);
        }
    }
    fin_.close();
    return m_;
}

Eigen::MatrixXd file::Read(const string filename) {
    SetFileName(filename); 
    Size();
    fin_.open(filename_);
    m_.resize(numOfRow_,numOfCol_);     // m*n matrix생성 

    char tempStr[1024];
    string tempString;
    string token;
    //데이터 입력
    for(int i=0; i<numOfRow_; i++) {
        fin_.getline(tempStr,1024);
        tempString = tempStr;
        stringstream stream(tempString);
        for(int j=0; j<numOfCol_; j++) {
            stream >> token;
            m_(i,j) = stod(token,0);
        }
    }
    fin_.close();
    return m_;
}

}
