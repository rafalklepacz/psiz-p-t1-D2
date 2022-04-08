#include "pch.h"
#include "list.h"
#include <ctime>
#include <cstring>

List* initList(void)
{
	List* pRoot = (List*)malloc(sizeof(*pRoot));

	if (pRoot)
	{
		pRoot->pPlateNum = (char*)"pRoot";
		pRoot->entryTime = std::time(nullptr);
		pRoot->pNext = NULL;

		return pRoot;
	}

	return NULL;
}

void deinitList(List* pRoot)
{
	free(pRoot);
	pRoot = NULL;
}

void addCar(List* pRoot, char* plateNum)
{
    List *pLastElement = pRoot;
    List *pNewElement = NULL;
    while(pLastElement->pNext != NULL)
    {
        pLastElement = pLastElement->pNext;
    }
    pNewElement = (List*)malloc(sizeof(*pNewElement));
    pNewElement->pPlateNum = (char*)malloc(strlen(plateNum) + 1u);
    strcpy(pNewElement->pPlateNum, plateNum);
    time(&(pNewElement->entryTime));
    pNewElement->pNext = NULL;
    pLastElement->pNext = pNewElement;
}

void removeCar(List* pRoot, char* plateNum)
{

}
void printAll(List* pRoot) {

}

int numberOfElements(List* pRoot)
{
    int number = 0;
	if (pRoot == NULL)
	{
		return number;
	}

    List *pLastElement = pRoot;
    while(pLastElement->pNext != NULL)
    {
        pLastElement = (pLastElement->pNext);
        number++;
    }
    return number;
}