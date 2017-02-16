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

//MAKE: g++ *.h *.cc  decrypt.cpp -Wall -pedantic -o v_dcpt
	 
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
		std::string uncyphered_text = buf.str();
		
		//grab key for attempted deciphering
		Password pwd;
		pwd.setPassword();
		
		//decrpyt using vignere cipher method
		std::string encyphered_text;
		for(std::size_t i=0; i<uncyphered_text.length(); ++i){
			char current_char = pwd.getPasscode()[i%pwd.getPasscode().length()];
			int current_char_index = find_index(current_char);
			int current_cypher_index = find_index(uncyphered_text[i]);
			if(current_cypher_index-current_char_index<0){
				encyphered_text+=enc_constants::ALPHABET[(current_cypher_index-current_char_index+enc_constants::SIZE)];
			} else encyphered_text+=enc_constants::ALPHABET[(current_cypher_index-current_char_index)];
		}
		
		//is correct deciphering?
		std::cout << "\nSample text: ";
		for(std::size_t i=0; i<20 && i<encyphered_text.length(); ++i){
			std::cout << encyphered_text[i];
		}
		
		std::cout << "\nWould you like to overwrite the file? [y/n] ";
		char yn; std::cin >> yn;
		
		if(yn=='y'){
			//write to file
			std::ofstream text_out;
			text_out.open(argv[1]);
			text_out << encyphered_text;
			text_out.close();
	
			std::cout << "\nDecryption completed.\n";
		} else std::cout << "Exiting...goodbye!\n";
		
		pwd.clearMemory();
	
	}
}

