/*
	�ڽ��� ������ �θ𺸴� ũ��
		 	    2   
			/       \
		  8		    22
		 / \	   /  \
	   36  42	  26  38
	///////��/////
				12
		87				111
----------------------------------
	34 ���ý�		75 ���ý�
----------------------------------
		34				75
	87 ����			111 ����
----------------------------------
	16 ���ý�
----------------------------------
		16
	87		34 ����
	
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