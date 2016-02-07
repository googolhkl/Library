#include "isEqual.h"

namespace hkl {
    namespace algorithm {
    isEqual::isEqual(int numsize) :numsize(numsize) {
        //this->numsize = numsize;
        isequal = false; 
    }
    isEqual::~isEqual () {}

    bool isEqual::Element (const double num) {
        if (myque.size() >= numsize)
            myque.pop_front ();

        myque.push_back (num);
        if (myque.size() >= numsize) {
            for (int i=0; i<myque.size()-1; i++) {
                if(myque.at(i) != myque.at(i+1)) {
                    isequal = false;
                    break;
                }
                isequal = true;
            }
        }
        return isequal;
    } // Element

    }
}
