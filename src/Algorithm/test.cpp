#include <iostream>
#include <deque>
//#include <algorithm>

using namespace std;
int main() {
    deque<int> ml;
    bool isequal;

    for(int i=0; i<30; i++) {
        if(ml.size() >= 20)
            ml.pop_front();

        int num;
        cin>>num;
        ml.push_back(num);
        if(ml.size() >=20) {
            for(int i=0; i<ml.size()-1; i++) {
                if(ml.at(i) != ml.at(i+1)) {
                    isequal = false;
                    break;
                }
                isequal = true;
            }

        }
        if(isequal == true)
            cout<<"모든 숫자가 같습니다"<<endl;
    }



    for(auto i: ml)
        cout<<i<<" ";
    cout<<endl;
}
