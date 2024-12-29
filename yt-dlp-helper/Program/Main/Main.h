#pragma once
#include <string>
#include <cstdlib>
#include <iostream>

using namespace std;

void clearScreen() {
    system("cls");
}

void runCommand(const string& command) {
    system(command.c_str());
}