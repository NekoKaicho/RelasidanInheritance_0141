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

