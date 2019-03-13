#ifndef _AUXILIARY_FUN_H_
#define _AUXILIARY_FUN_H_

#include "char_set.h"

char *my_copy(char *l, const char *r);

void CKeyWords(CharSet & _pSet);

void CppKeyWords(CharSet & _pSet);

void openFileTest(const char * _path);

void setWorkingTest();

void cmdTest(int _argc);

char * m_strtok(char *s, const char *delim);

void setWorkingTestClear();

void setWorkingTestKeys();


#endif //  _AUXILIARY_FUN_H_
