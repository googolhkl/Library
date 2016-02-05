#include "DB.h"
using namespace std;

namespace hkl {
    //public 멤버함수
    DB::DB() {
        driver =sql::mysql::get_mysql_driver_instance();
        con = driver->connect(DB_ADDRESS, DB_USER_NAME, DB_USER_PASS);
        if(con->isValid()) {
            cout<<"DB에 접속 완료"<<endl;
        } else {
            cout<<"DB에 접속 실패"<<endl;
            exit(-1);
        }
        stmt = con->createStatement ();
    }

    DB::~DB() {
        delete res;
        delete stmt;
        delete con;
    }

    void DB::Execute (string str) throw (sql::SQLException) {
        try {
            stmt->execute(str);
        } catch (sql::SQLException &e) {
            QueryFailed(str);
            e.what();
            cout<<"Mysql Error Code: "<<e.getErrorCode()<<endl;
            cout<<"SQL상태: "<<e.getSQLState()<<endl;
        }
    }

    void DB::ExecuteQuery (string str) throw (sql::SQLException) {
        try {
            res = stmt->executeQuery(str);
            while (res->next()) {
                // You can use either numeric offset
                cout << "number = " << res->getString("number");
                // or column name for accessing results.
                // The latter is recommended.
                cout << ", name = '" << res->getString(1) << "'" << endl;
            }
        } catch (sql::SQLException &e) {
            QueryFailed(str);
            e.what();
            cout<<"Mysql Error Code: "<<e.getErrorCode()<<endl;
            cout<<"SQL상태: "<<e.getSQLState()<<endl;
        }

    }

    //private 멤버함수
    void DB::QuerySuccess (string str) {
        cout<<"Query [ "<<str<<" ] 실행완료"<<endl;
    }
    void DB::QueryFailed (string str) {
        cout<<"Query [ "<<str<<" ] 실행실패"<<endl;
    }
}
