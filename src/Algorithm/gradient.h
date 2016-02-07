#ifndef HKLLIBRARY_SRC_ALGORITHM_GRADIENT_H
#define HKLLIBRARY_SRC_ALGORITHM_GRADIENT_H
#include <vector>

namespace hkl {
    namespace algorithm {

    //batch gradient descent
    class batchGD {
        private:
            //멤버 변수
            int m=0;
            double d0;
            double d1;
            double theta0 = 0.0;
            double theta1 = 0.0;
            double alpha = 0.001;
            std::vector<double> xv;
            std::vector<double> yv;

            //멤버 함수
            double H(const double x)const;     //Hypothesis Function (가설함수)
            bool Cost(void);
        public:
            //멤버 변수
            
            //멤버 함수
            batchGD(int m);
            ~batchGD();
            void Input(void);       //데이터 입력받기 (현재는 수동으로 콘솔창에서 입력) TODO: database, .dat, .txt파일에서 데이터 얻기
            double Result(const double x);
    };

    }

}


#endif // HKLLIBRARY_SRC_ALGORITHM_GRADIENT_H
