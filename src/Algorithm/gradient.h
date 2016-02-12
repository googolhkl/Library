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
            double GetResult() const;

        private:
            //멤버 함수
            Eigen::MatrixXd h(Eigen::MatrixXd x, Eigen::MatrixXd theta);

            //멤버 변수
            int iteration = 10000;
            long m_ = 0;
            long n_ = 0;
            double alpha_ = 0.000001;
            double result_ = 0.0;
            Eigen::MatrixXd X_;
            Eigen::MatrixXd Y_;
    };

}
}
#endif // HKLLIBRARY_SRC_ALGORITHM_GRADIENT_H
