#include <iostream>
#include <cstdlib>
#include <Windows.h>
#include <Lmcons.h>

#include "checker.h"

using namespace std;

bool PyChecker::isPyInstalled() {
    int result = system("python --version > null 2>&1");
    if (result == 0) return true;
    result = system("python3 --version > null 2>&1");
    if (result == 0) return true;
    return false;
}

string Usrname::getUsername() {
    char name[UNLEN + 1];
    DWORD name_len = UNLEN + 1;
    if (GetUserNameA(name, &name_len)) {
        return string(name);
    }
    else {
        return "UsernameError";
    }
}
