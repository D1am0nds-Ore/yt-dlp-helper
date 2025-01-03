#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include <conio.h>

#include "Main.h"
#include "../checker/checker.h"

using namespace std;

int main() {
    PyChecker checker;
    Usrname Username;
    string youtubeLink, customConfig, uname, pwd;
    string basicwin = "C:\\Users\\";
    string fullwin = basicwin + Username;
    int choicepre, choicevid, choicelogin;
    bool running = true;

    while (running) {
        clearScreen();

        cout << "Choose an option:\n";
        cout << "1. Download yt-dlp\n";
        cout << "2. Update yt-dlp\n";
        cout << "3. Login to YouTube account\n";
        cout << "4. Download YouTube video\n";
        cout << "5. Exit Program\n";
        cout << "Enter your choice (1-5): ";
        cin >> choicepre;
        cin.ignore();

        switch (choicepre) {
        case 1:
            if (checker.isPyInstalled()) {
                runCommand("pip install yt-dlp");
            }
            else {
                cout << "No python installed. Install python, please!\n";
            }
            break;
        case 2:
            if (checker.isPyInstalled()) {
                runCommand("pip install -U --pre \"yt-dlp[default]\"");
            }
            else {
                cout << "No python installed. Install python, please!\n";
            }
            break;
        case 3:
            cout << "Choose and option:\n";
            cout << "1.Login with username and password\n";
            cout << "2.Oauth login\n";
            cout << "Enter your choice (1-2): ";
            cin >> choicelogin;
            cin.ignore();

            switch (choicelogin) {
            case 1:
                cout << "Please insert username: ";
                cin >> uname;
                cin.ignore();
                cout << "Please insert password: ";
                cin >> pwd;
                cin.ignore();
                ifstream faaaaale(fullwin + "\\AppData\\Roaming\\yt-dlp\\config");
                if (!faaaaale) {
                    runCommand("yt-dlp -u " + uname + " -p " + pwd);
                    break;
                } else {
                    break;
                }
                break;
            case 2:
                cout << "not done yet";
                break;
            default:
                cout << "Invalid choice!\n";
                break;
            }
            break;
        case 4:
            cout << "Enter YouTube link: ";
            getline(cin, youtubeLink);
            cout << "Choose an option:\n";
            cout << "1. Download best video and audio with thumbnail\n";
            cout << "2. Download best video and audio\n";
            cout << "3. Download best audio only\n";
            cout << "4. Write thumbnail only\n";
            cout << "5. List available formats\n";
            cout << "6. Download best video with customizable config\n";
            cout << "Enter your choice (1-6): ";
            cin >> choicevid;
            cin.ignore();

            switch (choicevid) {
            case 1:
                runCommand("yt-dlp -f \"bestvideo+bestaudio\" --write-thumbnail --convert-thumbnail png " + youtubeLink);
                break;
            case 2:
                runCommand("yt-dlp -f \"bestvideo+bestaudio\" " + youtubeLink);
                break;
            case 3:
                runCommand("yt-dlp -f \"bestaudio\" " + youtubeLink);
                break;
            case 4:
                runCommand("yt-dlp --skip-download --write-thumbnail --convert-thumbnail png " + youtubeLink);
                break;
            case 5:
                runCommand("yt-dlp -F " + youtubeLink);
                break;
            case 6:
                cout << "Enter custom config for bestvideo[]: ";
                getline(cin, customConfig);
                runCommand("yt-dlp -f \"bestvideo[" + customConfig + "]+bestaudio\" " + youtubeLink);
                break;
            default:
                cout << "Invalid choice!\n";
                break;
            }
            break;
        case 5:
            running = false;
            break;
        default:
            cout << "Invalid choice!\n";
            break;
        }

        cout << "Press any key to continue...";
        _getch();
    }

    return 0;
}
