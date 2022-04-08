#include "pch.h"
#include "list.h"
#include <ctime>
#include <cstring>

List *initList(void)
{
    List *pRoot = (List *)malloc(sizeof(*pRoot));

    if (pRoot)
    {
        pRoot->pPlateNum = (char *)"pRoot";
        pRoot->entryTime = std::time(nullptr);
        pRoot->pNext = NULL;

        return pRoot;
    }

    return NULL;
}

void deinitList(List *pRoot)
{
    free(pRoot);
    pRoot = NULL;
}

void addCar(List *pRoot, char *plateNum)
{
    List *pLastElement = pRoot;
    List *pNewElement = NULL;
    while (pLastElement->pNext != NULL)
    {
        pLastElement = pLastElement->pNext;
    }
    pNewElement = (List *)malloc(sizeof(*pNewElement));
    pNewElement->pPlateNum = (char *)malloc(strlen(plateNum) + 1u);
    strcpy(pNewElement->pPlateNum, plateNum);
    time(&(pNewElement->entryTime));
    pNewElement->pNext = NULL;
    pLastElement->pNext = pNewElement;
}

void removeCar(List *pRoot, char *plateNum)
{
    bool elementFound = false;
    List *pIterElementBefre = NULL;
    List *pIterElement = pRoot;
    List *pIterElementAfter = pRoot->pNext;
    while ((NULL != pIterElement) && !elementFound)
    {
        if (0 != strstr(pIterElement->pPlateNum, plateNum))
        {
            elementFound = true;
        }
        else
        {
            if (NULL != pIterElement->pNext)
            {
                pIterElementBefre = pIterElement;
                if (NULL != pIterElement->pNext)
                    pIterElementAfter = (pIterElement->pNext->pNext);
                else
                    pIterElementAfter = NULL;
                pIterElement = (pIterElement->pNext);
            }
        }
    }
    if (elementFound)
    {
        if (NULL == pIterElementAfter)
        {
            pIterElementBefre->pNext = NULL;
        }
        else
        {
            pIterElementBefre->pNext = pIterElementAfter;
        }
        free(pIterElement->pPlateNum);
        free(pIterElement);
    }
}
void printAll(List *pRoot)
{
    if (pRoot == NULL)
    {
        printf("list is empty");
    }

    List *pLastElement = pRoot;
    int n = 0;
    while (pLastElement->pNext != NULL)
    {
        pLastElement = (pLastElement->pNext);
        n++;
        printf("%d. %s\n", n, pLastElement->pPlateNum);
    }
}

int numberOfElements(List *pRoot)
{
    int number = 0;
    if (pRoot == NULL)
    {
        return number;
    }

    List *pLastElement = pRoot;
    while (pLastElement->pNext != NULL)
    {
        pLastElement = (pLastElement->pNext);
        number++;
    }
    return number;
}