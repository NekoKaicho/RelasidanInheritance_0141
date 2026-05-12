#include <iostream>
#include <vector>
#include <string>
using namespace std;

class User {
protected:
    static int globalId;
    int id;
    string nama;
    string email;

    user(string pNama, string pEmail) : nama(pNama), email(pEmail) {
        id = generateId();
    }

      int generateId() {
        globalId++;
        return globalId;
    }

    virtual ~user() {}  // fix 1: virtual destructor
};
int user::globalId = 0;
 
class member : public user {
public:
    bool status;
 
    member(string pNama, string pEmail) : user(pNama, pEmail), status(true) {
        cout << "Member \"" << nama << "\" dibuat (ID: " << id << ")\n";
    }

    void showProfile() {
        cout << "ID     : " << id << "\n";
        cout << "Nama   : " << nama << "\n";
        cout << "Email  : " << email << "\n";
        cout << "Status : " << (status ? "Aktif" : "Non-Aktif") << "\n";
        cout << "-----------------------\n";
    }
};
