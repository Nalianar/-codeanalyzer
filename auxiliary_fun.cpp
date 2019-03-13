#include "stdafx.h"
#include "auxiliary_fun.h" 

#include <fstream>
#include <iostream>
#include <cassert>


char *my_copy(char *l, const char *r)
{
	while (*r) *l++ = *r++;
	++*l = '\0';
	return l;
}


void CKeyWords(CharSet & _pSet)
{
	CharSetInsertKey(_pSet, "auto");
	CharSetInsertKey(_pSet, "do");
	CharSetInsertKey(_pSet, "return");
	CharSetInsertKey(_pSet, "typedef");
	CharSetInsertKey(_pSet, "goto");
	CharSetInsertKey(_pSet, "break");
	CharSetInsertKey(_pSet, "double");
	CharSetInsertKey(_pSet, "if");
	CharSetInsertKey(_pSet, "short");
	CharSetInsertKey(_pSet, "union");
	CharSetInsertKey(_pSet, "case");
	CharSetInsertKey(_pSet, "else");
	CharSetInsertKey(_pSet, "inline");
	CharSetInsertKey(_pSet, "signed");
	CharSetInsertKey(_pSet, "unsigned");
	CharSetInsertKey(_pSet, "char");
	CharSetInsertKey(_pSet, "enum");
	CharSetInsertKey(_pSet, "int");
	CharSetInsertKey(_pSet, "sizeof");
	CharSetInsertKey(_pSet, "void");
	CharSetInsertKey(_pSet, "const");
	CharSetInsertKey(_pSet, "extern");
	CharSetInsertKey(_pSet, "long");
	CharSetInsertKey(_pSet, "static");
	CharSetInsertKey(_pSet, "volatile");
	CharSetInsertKey(_pSet, "continue");
	CharSetInsertKey(_pSet, "float");
	CharSetInsertKey(_pSet, "register");
	CharSetInsertKey(_pSet, "struct");
	CharSetInsertKey(_pSet, "while");
	CharSetInsertKey(_pSet, "default");
	CharSetInsertKey(_pSet, "for");
	CharSetInsertKey(_pSet, "restrict");
	CharSetInsertKey(_pSet, "switch");
}


void CppKeyWords(CharSet & _pSet)
{
	CharSetInsertKey(_pSet, "bool");
	CharSetInsertKey(_pSet, "export");
	CharSetInsertKey(_pSet, "operator");
	CharSetInsertKey(_pSet, "this");
	CharSetInsertKey(_pSet, "virtual");
	CharSetInsertKey(_pSet, "catch");
	CharSetInsertKey(_pSet, "false");
	CharSetInsertKey(_pSet, "private");
	CharSetInsertKey(_pSet, "throw");
	CharSetInsertKey(_pSet, "wchar_t");
	CharSetInsertKey(_pSet, "class");
	CharSetInsertKey(_pSet, "friend");
	CharSetInsertKey(_pSet, "protected");
	CharSetInsertKey(_pSet, "true");
	CharSetInsertKey(_pSet, "const_cast");
	CharSetInsertKey(_pSet, "inline");
	CharSetInsertKey(_pSet, "public");
	CharSetInsertKey(_pSet, "try");
	CharSetInsertKey(_pSet, "delete");
	CharSetInsertKey(_pSet, "mutable");
	CharSetInsertKey(_pSet, "reinterpret_cast");
	CharSetInsertKey(_pSet, "typeid");
	CharSetInsertKey(_pSet, "static_cast");
	CharSetInsertKey(_pSet, "dynamic_cast");
	CharSetInsertKey(_pSet, "namespace");
	CharSetInsertKey(_pSet, "typename");
	CharSetInsertKey(_pSet, "explicit");
	CharSetInsertKey(_pSet, "new");
	CharSetInsertKey(_pSet, "template");
	CharSetInsertKey(_pSet, "using");
}


char * m_strtok(char *s, const char *delim)
{
	static char *lasts;
	register int ch;

	if (s == 0)
		s = lasts;
	do {
		if ((ch = *s++) == '\0')
			return 0;
	} while (strchr(delim, ch));
	--s;
	lasts = s + strcspn(s, delim);
	if (*lasts != 0)
		*lasts++ = 0;
	return s;
}


void cmdTest(int _argc)
{
	if (_argc == 1)
	{
		std::cout << "Any arguments in the command line." << std::endl;
		exit(1);
	}
}


void openFileTest(const char * _path)
{
	std::fstream file(_path);
	if (!file.is_open())
	{
		std::cout << "Cannot open a file." << std::endl;
		exit(1);
	}
}


void setWorkingTestKeys()
{
	CharSet * Set = CharSetCreate();

	CharSetInsertKey(*Set, "WORD1");
	CharSetInsertKey(*Set, "WORD2");
	CharSetInsertKey(*Set, "WORD3");

	assert(CharSetHasKey(*Set, "WORD1"));
	assert(CharSetHasKey(*Set, "WORD2"));
	assert(!CharSetHasKey(*Set, "WORD4"));

	CharSetDeleteKey(*Set, "WORD3");
	assert(!CharSetHasKey(*Set, "WORD3"));

	CharSetDestroy(Set);
}


void setWorkingTestClear()
{
	CharSet * Set = CharSetCreate();

	CharSetInsertKey(*Set, "WORD1");
	CharSetInsertKey(*Set, "WORD2");

	CharSetClear(*Set);

	assert(!CharSetHasKey(*Set, "WORD1"));
	assert(!CharSetHasKey(*Set, "WORD2"));
	

	CharSetDestroy(Set);
}


void setWorkingTest()
{
	setWorkingTestClear();
	setWorkingTestKeys();

}
