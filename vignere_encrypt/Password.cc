#include "Password.h"

void Password::setPassword(){
	std::cout << "Enter your password: ";
	passcode = set_password_sneakily();
}

#ifdef OS_LINUX 
#include <termios.h>
#include <unistd.h>

std::string Password::set_password_sneakily(){
	//method for hiding console input
	//taken from stackoverflow
	using namespace std;
	termios oldt;
	tcgetattr(STDIN_FILENO, &oldt);
	termios newt = oldt;
	newt.c_lflag &= ~ECHO;
	tcsetattr(STDIN_FILENO, TCSANOW, &newt);
	
	string s;
	cin >> s;
	
	//cleanup terminal for later use
	tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
	
	return s;
}

#elif _WIN32
#include <windows.h>
using namespace std;
//taken from http://www.cplusplus.com/articles/E6vU7k9E/
string getpass()
{
	
	bool show_asterisk=false;
	
	const char BACKSPACE=8;
	const char RETURN=13;

	string password;
	unsigned char ch=0;


	DWORD con_mode;
	DWORD dwRead;

	HANDLE hIn=GetStdHandle(STD_INPUT_HANDLE);

	GetConsoleMode( hIn, &con_mode );
	SetConsoleMode( hIn, con_mode & ~(ENABLE_ECHO_INPUT | ENABLE_LINE_INPUT) );

	while(ReadConsoleA( hIn, &ch, 1, &dwRead, NULL) && ch !=RETURN)
		{
			 if(ch==BACKSPACE)
				 {
						if(password.length()!=0)
							{
								 if(show_asterisk)
										 cout <<"\b \b";
								 password.resize(password.length()-1);
							}
				 }
			 else
				 {
						 password+=ch;
					 if(show_asterisk)
							 cout <<'*';
			 }
	}
	return password;
}

std::string Password::set_password_sneakily(){
	return getpass();
}
#endif
	

