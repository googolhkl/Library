#include "algorithm.h"
#include <iostream>
using namespace std;

namespace hkl {
namespace algorithm {

linear::linear(const string x, const string y) {
    xFile_ = x;
    yFile_ = y;
}

double linear::GetResult() {
    //data의 matrix화
    hkl::file xFile(xFile_);    
    hkl::file yFile(yFile_);     
    X_ = xFile.Read();
    Y_ = yFile.Read();

    //입렴데이터의 행과 열
    m_ = X_.rows();
    n_ = X_.cols();
    n_--;  

    Eigen::MatrixXd theta(1,n_+1);
    for(int i=0; i<n_+1; i++) {
        theta(0,i) = 0.0;
    }

    // 입력을 받기위한 코드
    Eigen::MatrixXd in(n_+1, 1); in(0,0) = 1;
    for(int i= 1; i< n_+1; i++) {
        cout << "input:";
        cin >> in(i,0);
    }

    //cost function 과 linear descent 
    for(int i=0; i<iteration_; i++) {
        Eigen::MatrixXd delta = (1.0/m_) * ((h(X_,theta) - Y_).transpose() * X_);
        theta = theta - alpha_*delta;
    }

    Eigen::MatrixXd result = theta * in;
    result_ = result(0,0);
    return result_;
}

bool linear::SetAlpha(double alpha) {
    alpha_ = alpha;
    return true;
}

bool linear::SetIteration(int iter) {
    iteration_ = iter;
    return true;
}

//가설함수
Eigen::MatrixXd linear::h(Eigen::MatrixXd x, Eigen::MatrixXd theta) {
    Eigen::MatrixXd prediction = x * theta.transpose();
    return prediction;
}




}
}
