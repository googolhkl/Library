#ifndef HKLLIBRARY_SRC_UTIL_DB_H
#define HKLLIBRARY_SRC_UTIL_DB_H
#include <iostream>
#include <string>
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>

#include "mysql_driver.h"
#include "mysql_connection.h"
#include "db_info.h"


namespace hkl {
// DB 관련 클래스
class DB {
    public:
        DB();
        ~DB();
        void Execute (std::string str) throw(sql::SQLException);         //명령어 수행
        void ExecuteQuery (std::string str) throw(sql::SQLException);    //사용할 때 바꿔줘야하는.. 사용자제
    private:
        void QuerySuccess(std::string str);
        void QueryFailed(std::string str);
        sql::mysql::MySQL_Driver *driver;
        sql::Connection *con;
        sql::Statement *stmt;
        sql::ResultSet *res;
};
}

#endif // HKLLIBRARY_SRC_UTIL_DB_H
