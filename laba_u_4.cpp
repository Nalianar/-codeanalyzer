
#include "stdafx.h"
#include <fstream>
#include <iostream>
#include <cstring>

#include "char_set.h"
#include "auxiliary_fun.h"



int main(int argc, char ** argv)
{
	setWorkingTest();
	cmdTest(argc);
	openFileTest(argv[1]);

	CharSet * CppSet = CharSetCreate();
	CharSet * CSet = CharSetCreate();

	
	CKeyWords(*CSet);
	CppKeyWords(*CppSet);

	std::ifstream file(argv[1]);
	char buffer[512];
	const char delim[] = " .,!?[]{}<>()#&*'-+=;:/|\"@~$%^";
	int wordsCpp = 0, C_Cpp_words = 0, not_Cpp_or_C = 0;

	while (!file.eof())
	{
		file.getline(buffer, sizeof(buffer));
		char * OneWord = m_strtok(buffer, delim);
		while (OneWord)
		{
			if (CharSetHasKey(*CppSet, OneWord))
				wordsCpp++;
			else if (CharSetHasKey(*CSet, OneWord))
				C_Cpp_words++;
			else
				not_Cpp_or_C++;

			OneWord = m_strtok(NULL, delim);
		}
	}

	std::cout << "Words on C++ : " << wordsCpp << std::endl;
	std::cout << "C and C++ words : " << C_Cpp_words << std::endl;
	std::cout << "None of C++ or C words : " << C_Cpp_words << std::endl;

	CharSetDestroy(CppSet);
	CharSetDestroy(CSet);
	return 0;
}

