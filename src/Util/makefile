# 공유라이브러리로 만들 이름
SHAREDNAME=hkl_util.dll
# 어떤소스를 공유라이브러리로 만들지,여러개 가능
SHAREDOBJECT=util.cc time.cc db.cc

# main함수가 들어있는 소스파일이름
MAIN=main

# 컴파일 정보
gxx=g++ -std=c++11

# 유틸라이브러리와 유닛테스트라이브러리
LIBS=$(SHAREDNAME) -lunittest++ -I/usr/local/include -I/user/local/include/cppconn -lmysqlcppconn


################################### 행동 방식 #####################################
$(MAIN): $(MAIN).o
	$(gxx) -o $(MAIN) $(MAIN).o $(LIBS)

$(MAIN).o: $(MAIN).cc
	$(gxx) -c -g $(MAIN).cc

clean:
	rm $(MAIN) $(MAIN).o

shared:
	$(gxx) -shared -fPIC -o $(SHAREDNAME) $(SHAREDOBJECT) -I/usr/local/include -I/user/local/include/cppconn -lmysqlcppconn
