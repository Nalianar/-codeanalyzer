#ifndef _CHAR_LIST_H_
#define _CHAR_LIST_H_


#include "auxiliary_fun.h" 

#include <iostream>


struct CharList
{
	struct Node
	{
		char * m_value;
		Node * m_pNext;
	};

	Node * m_pFirst, *m_pLast;
};


void CharListInit(CharList & _list);

void CharListDestroy(CharList & _list);

bool CharListIsEmpty(const CharList & _list);

int CharListSize(const CharList & _list);

void CharListClear(CharList & _list);

void CharListPushBack(CharList & _list, const char * _data);

void CharListPushFront(CharList & _list, const char * _data);

void CharListInsertAfter(CharList & _list, CharList::Node * _pPrevNode, const char * _data);

void CharListInsertBefore(CharList & _list, CharList::Node * _pNextNode, const char * _data);

void CharListPopBack(CharList & _list);

void CharListPopFront(CharList & _list);

void CharListDeleteAfter(CharList & _list, CharList::Node * _pPrevNode);

void CharListDeleteBefore(CharList & _list, CharList::Node * _pNextNode);

void CharListDeleteNode(CharList & _list, CharList::Node * _pNode);

void CharListPrint(const CharList & _list, std::ostream & _o, char _sep = ' ');



#endif //  _CHAR_LIST_H_
