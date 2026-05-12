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

class admin : public user {
public:
    admin(string pNama, string pEmail) : user(pNama, pEmail) {
        cout << "Admin \"" << nama << "\" dibuat (ID: " << id << ")\n";
    }

    void showAllMember(const vector<member*>& daftar_member) {  // fix 2: const reference
        cout << "\n=== DAFTAR SEMUA MEMBER ===\n";
        for (auto* m : daftar_member) {  // fix 3: range-based for
            m->showProfile();
        }
    }

    void toggleActivationMember(member* pMember) {
        pMember->status = !pMember->status;
        cout << "\n[!] Status member \"" << pMember->nama << "\" diubah menjadi: "
             << (pMember->status ? "Aktif" : "Non-Aktif") << "\n";
    }
};

int main() {
    admin* varAdmin = new admin("Heyden", "admin.heyden@gmail.com");
    cout << endl;

    member* m1 = new member("Saya", "saya@gmail.com");
    member* m2 = new member("Siyi", "siyi@gmail.com");
    member* m3 = new member("Soyo", "soyo@gmail.com");

    vector<member*> daftar_member;
    daftar_member.push_back(m1);
    daftar_member.push_back(m2);
    daftar_member.push_back(m3);