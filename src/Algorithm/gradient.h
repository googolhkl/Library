#ifndef HKLLIBRARY_SRC_ALGORITHM_GRADIENT_H
#define HKLLIBRARY_SRC_ALGORITHM_GRADIENT_H

#include "../Util/file.h"
#include <string>

namespace hkl {
namespace algorithm {

    class gradient {
        public:
            gradient(){}
            gradient(const std::string x, const std::string y);
            ~gradient(){}
            double GetResult();
            bool SetAlpha(double alpha);    // 학습률 변경
            bool SetIteration(int iter);    // 반복숫자 변경

        private:
            //멤버 함수
            Eigen::MatrixXd h(Eigen::MatrixXd x, Eigen::MatrixXd theta);

            //멤버 변수
            int iteration_ = 10000;
            long m_ = 0;
            long n_ = 0;
            double alpha_ = 0.00001;
            double result_ = 0.0;
            std::string xFile_;
            std::string yFile_;
            Eigen::MatrixXd X_;
            Eigen::MatrixXd Y_;
    };

}
}
#endif // HKLLIBRARY_SRC_ALGORITHM_GRADIENT_H
