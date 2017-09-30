// ClassLibraryCppClient.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <objbase.h>
#include <iostream>

#import "ClassLibrary.tlb"

int _tmain(int argc, _TCHAR* argv[])
{
    CoInitialize(NULL);

    ClassLibrary::ICustomListPtr list(__uuidof(ClassLibrary::CustomList));

    std::cout << "Add 3 items" << std::endl;

    list->Add(25);
    list->Add(26);
    list->Add(27);

    std::cout << "The sum is " << list->Sum << std::endl;

    std::cout << "Set 0-th item" << std::endl;

    list->item[0] = 28;

    std::cout << "The sum is " << list->Sum << std::endl;

    std::cout << "Iterate" << std::endl;

    unsigned size = list->Count;

    std::cout << "The size is " << size << std::endl;

    for (int i = 0; i < size; ++i)
    {
        int item = list->item[i];
        std::cout << "\tItem at position " << i << " is " << item << std::endl;
    }

    std::cout << "Remove 3 items" << std::endl;

    list->Remove(28);
    list->Remove(26);
    list->Remove(27);

    size = list->Count;

    std::cout << "The size is " << size << std::endl;

    std::cout << "The sum is " << list->Sum << std::endl;

    CoUninitialize();

	return 0;
}
