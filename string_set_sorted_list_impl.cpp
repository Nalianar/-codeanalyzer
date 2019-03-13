#include "stdafx.h"
#include "char_set.h"
#include "char_list.h"

#include <cassert>


struct CharSet
{
	CharList m_data;
};


CharSet * CharSetCreate()
{
	CharSet * pSet = new CharSet;
	CharListInit(pSet->m_data);
	return pSet;
}


void CharSetDestroy(CharSet * _pSet)
{
	CharListDestroy(_pSet->m_data);
	delete _pSet;
}


void CharSetClear(CharSet & _set)
{
	CharListClear(_set.m_data);
}


bool CharSetIsEmpty(const CharSet & _set)
{
	return CharListIsEmpty(_set.m_data);
}


bool CharSetHasKey(const CharSet & _set, const char * _key)
{
	CharList::Node * pNode = _set.m_data.m_pFirst;
	while (pNode)
	{
		if (!strcmp(pNode->m_value, _key))
			return true;
		else if (strcmp(pNode->m_value, _key) > 0)
			return false;
		pNode = pNode->m_pNext;
	}
	return false;
}


void CharSetInsertKey(CharSet & _set, const char * _key)
{
	if (CharListIsEmpty(_set.m_data))
		CharListPushBack(_set.m_data, _key);

	else
	{
		CharList::Node * pNode = _set.m_data.m_pFirst;
		if (strcmp(_key, pNode->m_value) < 0)
			CharListPushFront(_set.m_data, _key);

		else
		{
			CharList::Node * pPrevNode = nullptr;
			while (pNode)
			{
				if (!strcmp(pNode->m_value, _key))
					return;

				else if (!pNode->m_pNext)
				{
					CharListPushBack(_set.m_data, _key);
					return;
				}

				else if (strcmp(pNode->m_pNext->m_value, _key) > 0)
				{
					CharListInsertAfter(_set.m_data, pNode, _key);
					return;
				}

				else
					pNode = pNode->m_pNext;
			}

			assert(!"We should never get here");
		}
	}
}


void CharSetDeleteKey(CharSet & _set, const char * _key)
{
	CharList::Node * pNode = _set.m_data.m_pFirst;
	while (pNode)
	{
		if (!strcmp(pNode->m_value, _key))
		{
			CharListDeleteNode(_set.m_data, pNode);
			return;
		}
		else if (strcmp(pNode->m_value, _key) > 0)
			break;

		pNode = pNode->m_pNext;
	}

	assert(!"Key is unavailble!");
}




