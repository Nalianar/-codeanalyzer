#include "stdafx.h"
#include "char_list.h"

#include <cassert>

void CharListInit(CharList & _list)
{
	_list.m_pFirst = _list.m_pLast = nullptr;
}


void CharListDestroy(CharList & _list)
{
	CharListClear(_list);
}


void CharListClear(CharList & _list)
{
	CharList::Node * pCurrent = _list.m_pFirst;
	while (pCurrent)
	{
		CharList::Node * pTemp = pCurrent->m_pNext;
		delete[] pCurrent->m_value;
		delete pCurrent;
		pCurrent = pTemp;
	}

	_list.m_pFirst = _list.m_pLast = nullptr;
}


bool CharListIsEmpty(const CharList & _list)
{
	return _list.m_pFirst == nullptr;
}


int CharListSize(const CharList & _list)
{
	int nElements = 0;
	const CharList::Node * pNode = _list.m_pFirst;
	while (pNode)
	{
		++nElements;
		pNode = pNode->m_pNext;
	}

	return nElements;
}


void CharListPushBack(CharList & _list, const char * _data)
{
	CharList::Node * pNewNode = new CharList::Node;
	pNewNode->m_value = new char[strlen(_data) + 1];
	my_copy(pNewNode->m_value, _data);
	pNewNode->m_pNext = nullptr;

	if (!_list.m_pFirst)
	{
		assert(!_list.m_pLast);
		_list.m_pFirst = pNewNode;
	}
	else
		_list.m_pLast->m_pNext = pNewNode;

	_list.m_pLast = pNewNode;
}


void CharListPushFront(CharList & _list, const char * _data)
{
	CharList::Node * pNewNode = new CharList::Node;
	pNewNode->m_value = new char[strlen(_data) + 1];
	my_copy(pNewNode->m_value, _data);
	pNewNode->m_pNext = _list.m_pFirst;

	_list.m_pFirst = pNewNode;

	if (!_list.m_pLast)
		_list.m_pLast = pNewNode;
}


void CharListInsertAfter(CharList & _list, CharList::Node * _pPrevNode, const char * _data)
{
	assert(!CharListIsEmpty(_list));

	if (_pPrevNode == _list.m_pLast)
		CharListPushBack(_list, _data);

	else
	{
		CharList::Node * pNewNode = new CharList::Node;
		pNewNode->m_value = new char[strlen(_data) + 1];
		my_copy(pNewNode->m_value, _data);

		pNewNode->m_pNext = _pPrevNode->m_pNext;

		_pPrevNode->m_pNext = pNewNode;
	}
}


void CharListInsertBefore(CharList & _list, CharList::Node * _pNextNode, const char * _data)
{
	assert(!CharListIsEmpty(_list));

	if (_pNextNode == _list.m_pFirst)
		CharListPushFront(_list, _data);

	else
	{
		CharList::Node * pCurrent = _list.m_pFirst;
		while (pCurrent && pCurrent->m_pNext != _pNextNode)
			pCurrent = pCurrent->m_pNext;

		assert(pCurrent);

		CharList::Node * pNewNode = new CharList::Node;
		pNewNode->m_value = new char[strlen(_data) + 1];
		my_copy(pNewNode->m_value, _data);
		pNewNode->m_pNext = _pNextNode;

		pCurrent->m_pNext = pNewNode;

	}
}


void CharListPopFront(CharList & _list)
{
	assert(!CharListIsEmpty(_list));

	CharList::Node * pFirst = _list.m_pFirst;

	if (_list.m_pFirst == _list.m_pLast)
		_list.m_pFirst = _list.m_pLast = nullptr;

	else
		_list.m_pFirst = pFirst->m_pNext;

	delete[] pFirst->m_value;
	delete pFirst;
}


void CharListPopBack(CharList & _list)
{
	assert(!CharListIsEmpty(_list));

	CharList::Node * pLast = _list.m_pLast;

	if (_list.m_pFirst == _list.m_pLast)
		_list.m_pFirst = _list.m_pLast = nullptr;

	else
	{
		CharList::Node * pCurrent = _list.m_pFirst;
		while (pCurrent->m_pNext != _list.m_pLast)
			pCurrent = pCurrent->m_pNext;

		_list.m_pLast = pCurrent;
		pCurrent->m_pNext = nullptr;
	}

	delete[] pLast->m_value;
	delete pLast;
}


void CharListDeleteAfter(CharList & _list, CharList::Node * _pPrevNode)
{
	assert(!CharListIsEmpty(_list));

	assert(_list.m_pLast != _pPrevNode);

	CharList::Node * pDyingNode = _pPrevNode->m_pNext;
	_pPrevNode->m_pNext = pDyingNode->m_pNext;

	if (_list.m_pLast == pDyingNode)
		_list.m_pLast = _pPrevNode;

	delete[] pDyingNode->m_value;
	delete pDyingNode;
}


void CharListDeleteBefore(CharList & _list, CharList::Node * _pNextNode)
{
	assert(!CharListIsEmpty(_list));

	assert(_list.m_pFirst != _pNextNode);

	CharList::Node * pPrevNode = _list.m_pFirst, *pCurrentNode = _list.m_pFirst->m_pNext;
	if (pCurrentNode == _pNextNode)
	{
		delete[] _list.m_pLast;
		delete _list.m_pFirst;
		_list.m_pFirst = _pNextNode;
	}

	else
	{
		while (pCurrentNode->m_pNext != _pNextNode)
		{
			pPrevNode = pCurrentNode;
			pCurrentNode = pCurrentNode->m_pNext;
		}

		pPrevNode->m_pNext = _pNextNode;
		delete[] pCurrentNode->m_value;
		delete pCurrentNode;
	}
}


void CharListDeleteNode(CharList & _list, CharList::Node * _pNode)
{
	if (_list.m_pFirst == _pNode)
		CharListPopFront(_list);

	else if (_list.m_pLast == _pNode)
		CharListPopBack(_list);

	else
		CharListDeleteBefore(_list, _pNode->m_pNext);
}


void CharListPrint(const CharList & _list, std::ostream & _stream, char _sep)
{
	const CharList::Node * pCurrent = _list.m_pFirst;
	while (pCurrent)
	{
		_stream << pCurrent->m_value << _sep;
		pCurrent = pCurrent->m_pNext;
	}
}
