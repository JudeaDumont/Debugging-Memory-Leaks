// Memory_Leak.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

// debug_new.cpp
// compile by using: cl /EHsc /W4 /D_DEBUG /MDd debug_new.cpp
#define _CRTDBG_MAP_ALLOC
#include <cstdlib>
#include <crtdbg.h>
#include <iostream>

#ifdef _DEBUG
    #define new new( _NORMAL_BLOCK , __FILE__ , __LINE__ )
    // Replace _NORMAL_BLOCK with _CLIENT_BLOCK if you want the
    // allocations to be of _CLIENT_BLOCK type
#else
    //#define DBG_NEW new
#endif


int main()
{
	_CrtSetReportMode(_CRT_ERROR, _CRTDBG_MODE_DEBUG);
	_CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_DEBUG);
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	int* a_IntArrayLeak = new int[2];     //This is on the heap, leak
	int a_IntNoLeak[10];				  //This is on the stack only
	int* pOnTheStack = nullptr;
	int nOnTheStack = 8;
	pOnTheStack = &nOnTheStack;
	int* nOnTheHeap = new int();

	std::cout << _CrtDumpMemoryLeaks();   
	return 0;
}

