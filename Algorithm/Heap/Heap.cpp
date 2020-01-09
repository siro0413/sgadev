/*
	자식은 무조건 부모보다 크다
		 	    2   
			/       \
		  8		    22
		 / \	   /  \
	   36  42	  26  38
	///////단/////
				12
		87				111
----------------------------------
	34 들어올시		75 들어올시
----------------------------------
		34				75
	87 변경			111 변경
----------------------------------
	16 들어올시
----------------------------------
		16
	87		34 변경
	
*/

#include <Windows.h>
#include <stdio.h>
#include "Heap.h"

void main()
{
	Heap<int> heap(3);

	heap.Insert(12);
	heap.Insert(87);
	heap.Insert(111);
	heap.Insert(34);
	heap.Insert(16);
	heap.Insert(75);

	heap.Print();

	heap.RemoveMin();
	heap.Print();

	heap.RemoveMin();
	heap.Print();

	heap.RemoveMin();
	heap.Print();

	heap.RemoveMin();
	heap.Print();

	heap.RemoveMin();
	heap.Print();

	heap.RemoveMin();
	heap.Print();

	system("pause");
}