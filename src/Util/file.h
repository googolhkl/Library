#ifndef HKLLIBRARY_SRC_UTIL_FILE_H
#define HKLLIBRARY_SRC_UTIL_FILE_H
// 이 헤더파일은 C++ matrix계산용 라이브러리 Eigen을 포함하고 있습니다
// http://eigen.tuxfamily.org/index.php?title=Main_Page 에서 설치 할 수있으며
// 설치 메뉴열 대로 설치를 완료하면 /usr/local/include 경로에 Eigen이 설치되어 컴파일 옵션에서 따로 지정해 줄 필요는 없습니다. 
// linux와 mac 에서는 잘 동작하는데 windows는 확인을 안해봤지만 IDE에서 라이브러리 설정만 해주면 될 것 같습니다
// 사용 용도 : 데이터파일을 matrix에 저장
#include <Eigen/Dense>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>


namespace hkl {

class file {
    public:
        file();
        file(const std::string filename);
        ~file();

        bool SetFileName(const std::string filename);
        Eigen::MatrixXd Size();
        Eigen::MatrixXd Read();
        Eigen::MatrixXd Read(const std::string filename);

    private:
        std::ifstream fin_;             //입력스트림
        std::ofstream fout_;            //출력스트림
        int numOfRow_ = 1;
        int numOfCol_ = 1;
        Eigen::MatrixXd m_;        // basic matrix
        std::string filename_;
};
}


#endif //HKLLIBRARY_SRC_UTIL_FILE_H
