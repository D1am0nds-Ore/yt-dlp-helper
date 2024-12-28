#include "checker.h"
using namespace std;

bool PyChecker::isPyInstalled() {
	int result = system("python --version >null 2>&1");
	if (result == 0) return true;
	result = system("python3 --version >null 2>&1");
	if (result == 0) return true;
	return false;
}