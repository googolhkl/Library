#ifndef HKLLIBRARY_SRC_ALGORITHM_ISEQUAL_H
#define HKLLIBRARY_SRC_ALGORITHM_ISEQUAL_H

#include <deque>
namespace hkl {
    namespace algorithm {
    class isEqual {
        public:
            isEqual (int numsize=0);
            ~isEqual();
            bool Element (const double num);    //num에 들어간 deque에 전부 같은원소인지 확인
        private:
            std::deque<double> myque;
            int numsize;
            bool isequal;
    };
    }
}



#endif //HKLLIBRARY_SRC_ALGORITHM_ISEQUAL_H
