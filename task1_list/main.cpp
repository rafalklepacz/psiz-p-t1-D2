#include "pch.h"
#include "list.h"
#include <ctime>

List mojaLista;

int main()
{
	List* pFirstFloor = initList();
	List* pSecFloor = initList();

	addCar(pFirstFloor, (char*)"asdasd");
	addCar(pFirstFloor, (char*)"asdasd");
	printf("%d\n", numberOfElements(pFirstFloor));
	
	deinitList(pFirstFloor);
	deinitList(pSecFloor);
}
