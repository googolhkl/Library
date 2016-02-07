#include "gradient.h"
#include <iostream>

namespace hkl {
    namespace algorithm {
//private 멤버 함수
    double batchGD::H (const double x)const {
        return theta0 + theta1*x;
    }

    bool batchGD::Cost (void) {
        for(int i=0; i<m; ++i) {
            d0 += H(xv[i]) - yv[i];
            d1 += (H(xv[i]) - yv[i]) * xv[i];
        }
        return true;
    }
//public 멤버 함수
    batchGD::batchGD (int m) : m(m) {
        xv.resize(m);
        yv.resize(m);
    }
    batchGD::~batchGD () {}
    
    void batchGD::Input (void) {
        for(int i=0; i<m; ++i) {
            std::cout<<"[x,y] : ";
            std::cin >> xv[i] >> yv[i];
        }
    }

    double batchGD::Result (const double x) {
        for (int i=0; i< 100000; ++i) {   //TODO 수렴할때 까지 동작
            d0 = d1 = 0.0;
            Cost();
            theta0 -= alpha * d0/m;
            theta1 -= alpha * d1/m;
            std::cout<<"theta0 : "<<theta0 <<" theta1 : "<< theta1<<std::endl;
        }
        return H(x);
    }
    }
}
