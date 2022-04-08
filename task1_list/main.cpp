#include "pch.h"
#include "list.h"
#include <ctime>

List mojaLista;

int main()
{
	List* pFirstFloor = initList();
	List* pSecFloor = initList();

	addCar(pFirstFloor, (char*)"qwe");
	addCar(pFirstFloor, (char*)"asd");
	addCar(pFirstFloor, (char*)"zxc");

	printf("numberOfElements: %d\n", numberOfElements(pFirstFloor));
	printAll(pFirstFloor);

	removeCar(pFirstFloor, (char*)"zxc");

	printf("numberOfElements: %d\n", numberOfElements(pFirstFloor));
	printAll(pFirstFloor);
	
	deinitList(pFirstFloor);
	deinitList(pSecFloor);
}
