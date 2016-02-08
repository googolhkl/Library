#include <iostream>
#include "gradient.h"
#include "is_equal.h"

namespace hkl {
    namespace algorithm {
//private 멤버 함수
    double batchGD::H(const double x)const {
        return theta0 + theta1 * x;
    }

    bool batchGD::Cost(void) {
        for(int i=0 ; i<m ; ++i) {
            d0 += H(xv[i]) - yv[i];
            d1 += (H(xv[i]) - yv[i]) * xv[i];
        }
        return true;
    }
//public 멤버 함수
    batchGD::batchGD(int m) : m(m) {
        xv.resize(m);
        yv.resize(m);
    }
    batchGD::~batchGD() {}
    
    void batchGD::Input(void) {
        for(int i=0 ; i<m ; ++i) {
            std::cout <<"[x,y] : ";
            std::cin >> xv[i] >> yv[i];
        }
    }

    double batchGD::Result(const double x) {
        isEqual deque1(10);
        isEqual deque2(10);
        while(1) {
            d0 = d1 = 0.0;
            Cost();
            theta0 -= alpha * d0/m;
            theta1 -= alpha * d1/m;
            if (deque1.Element(theta0) && deque2.Element(theta1))
            {
                //std::cout<<"종룢"<<std::endl;
                    return H(x);
            }
            //std::cout<<"theta0 : "<<theta0 <<" theta1 : "<< theta1<<std::endl;
        }
        return H(x);
    }

    bool batchGD::Setxv(const double x,const int idx) {
        if(xv.size() <= idx)
            xv.resize(xv.size()+1);
        xv[idx] = x;
        return true;
    }
    bool batchGD::Setyv(const double y,const int idx) {
        if(yv.size() <= idx)
            yv.resize(yv.size()+1);
        yv[idx] = y;
        return true;
    }

    
    }
}
