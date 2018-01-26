#ifndef Password_H
#define Password_H

#include <string>
#include <iostream>
#include <fstream>
#include <streambuf>
#include <cstring>

//detect windows/linux
#if defined(_WIN32) || defined(_WIN64)
#define OS_WIN
#endif

#if defined(__linux__)
#define OS_LINUX
#endif


class Password {
	std::string passcode;
	std::string set_password_sneakily();
public:
	void setPassword();
	std::string getPasscode(){ return passcode; }
	void clearMemory(){ passcode = "00000000000000000000000000000000000000000000000"; }
};

#endif
	
