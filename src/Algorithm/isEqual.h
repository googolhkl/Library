#ifndef HKLLIBRARY_SRC_ALGORITHM_ISEQUAL_H
#define HKLLIBRARY_SRC_ALGORITHM_ISEQUAL_H

#include <deque>
namespace hkl {
    namespace algorithm {
    class isEqual {
        public:
            isEqual (int numsize=0);
            ~isEqual();
            bool Element (const double num);
        private:
            std::deque<double> myque;
            int numsize;
            bool isequal;
    };
    }
}



#endif //HKLLIBRARY_SRC_ALGORITHM_ISEQUAL_H
