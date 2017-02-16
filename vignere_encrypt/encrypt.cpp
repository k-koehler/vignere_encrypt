/*
Kevin Koehler
Vignere Encypt
22 June 2016
*/

#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <sstream>
#include <streambuf>
#include <locale>
#include <cctype>

#include "Password.h"
#include "enc_constants.h"

//MAKE: g++ *.h *.cc  encrypt.cpp -Wall -pedantic -o v_encpt
	 
int find_index(const char flag){
	for(std::size_t i=0; i<enc_constants::SIZE; ++i){
		if (enc_constants::ALPHABET[i]==flag || std::toupper(enc_constants::ALPHABET[i])==flag) return i;
	}
	return -1;
}

int main(int argc, char* argv[]){

	//check for errors
	if(argc !=2){
		std::cout << "Error! Usage: <filename>\n";
	} else {
		
		//grab input
		std::ifstream input(argv[1]);
		std::stringstream buf;
		buf << input.rdbuf();
		std::string str = buf.str();
		
		//codify string 
		//no spaces, no caps, etc.
		std::locale loc;
		std::string uncyphered_text;
		for(std::size_t i=0; i<str.length(); ++i){
			if(find_index(str[i])!=-1) uncyphered_text+=std::tolower(str[i],loc);
		}
		
		//first let's create a key
		Password pwd;
		pwd.setPassword();
		
		//encrypt using vignere cypher
		std::string encyphered_text;
		for(std::size_t i=0; i<uncyphered_text.length(); ++i){
			char current_char = pwd.getPasscode()[i%pwd.getPasscode().length()];
			int current_char_index = find_index(current_char);
			int current_cypher_index = find_index(uncyphered_text[i]);
			encyphered_text+=enc_constants::ALPHABET[(current_char_index+current_cypher_index)%enc_constants::SIZE];
		}
	
		//write to file
		std::ofstream text_out;
		text_out.open(argv[1]);
		text_out << encyphered_text;
		text_out.close();
	
		std::cout << "\nEncryption completed.\n";
		
		pwd.clearMemory();
	
	}
}

