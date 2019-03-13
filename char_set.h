#ifndef _CHAR_SET_HPP_
#define _CHAR_SET_HPP_

struct CharSet;


CharSet * CharSetCreate();

void CharSetDestroy(CharSet * _pSet);

void CharSetClear(CharSet & _set);

bool CharSetIsEmpty(const CharSet & _set);

bool CharSetHasKey(const CharSet & _set, const char * _key);

void CharSetInsertKey(CharSet & _set, const char * _key);

void CharSetDeleteKey(CharSet & _set, const char * _key);



#endif //  _CHAR_SET_HPP_
