#include "Main.h"
#include "../checker/checker.h"
using namespace std;

void runCommand(const string& command) {
    system(command.c_str());
}

int main() {
    PyChecker checker;
    string youtubeLink;
    string customConfig;
    int choicepre, choice;

    cout << "Choose an option:\n";
    cout << "1. Download yt-dlp\n";
    cout << "2. Update yt-dlp\n";
    cout << "3. Login to YouTube account\n";
    cout << "4. Download YouTube video\n";
    cout << "Enter your choice (1-4): ";
    cin >> choicepre;
    cin.ignore();

    switch (choicepre) {
    case 1:
        if (checker.isPyInstalled()) {
            runCommand("pip install yt-dlp");
        }
        else {
            cout << "No python installed. Install python please!\n";
        }
        break;
    case 2:
        if (checker.isPyInstalled()) {
            runCommand("pip install -U --pre \"yt-dlp[default]\"");
        }
          else {
            cout << "No python installed. Install python please!\n";
        }
        break;
    case 3:
        // Not done yet
        cout << "Login functionality not implemented yet.\n";
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
        cin >> choice;
        cin.ignore();

        switch (choice) {
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
    default:
        cout << "Invalid choice!\n";
        break;
    }

    cout << "Press any key to exit...";
    _getch();

    return 0;
}
