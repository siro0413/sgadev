#include <Windows.h>
#include <stdio.h> //qsort -> c
#include <algorithm>//sort -> c++

#include "Timer.h"

struct Data
{
	UINT Number;
	UINT Score;
};

void ReadData(Data* datas)
{
	FILE* file = NULL;
	fopen_s(&file, "./CreateData/Data.txt", "r");
	{
		for (UINT i = 0; i < USHRT_MAX; i++)
			fscanf_s(file, "%d,%d", &datas[i].Number, &datas[i].Score); 
	}
	fclose(file);
}

void WriteData(Data* datas)
{
	FILE* file;
	fopen_s(&file, "Result.txt", "w");
	{
		for (UINT i = 0; i < USHRT_MAX; i++)
			fprintf(file, "%d,%d\n", datas[i].Number, datas[i].Score);
	}
	fclose(file);
}

void Swap(Data* a, Data* b)
{
	Data temp = *a;
	*a = *b;
	*b = temp;
}

int Partition(Data* datas, int left, int right)
{
	int first = left;
	int pivot = datas[first].Score;

	left++;
	while (left <= right)
	{
		while (datas[left].Score <= pivot && left < right)
			left++;
		while (datas[right].Score > pivot && left <= right)
			right--;

		if (left < right)
			Swap(&datas[left], &datas[right]);
		else
			break;
	}

	Swap(&datas[first], &datas[right]);

	return right;
}

void QuickSort(Data* datas, int left, int right)
{
	if (left < right)
	{
		int index = Partition(datas, left, right);

		QuickSort(datas, left, index - 1);
		QuickSort(datas, index + 1, right);
	}
}

// 같은 경우 0, 오름차순 1, 내림차순 -1
int Compare(const void* val1, const void* val2)
{
	Data* data1 = (Data*)val1;
	Data* data2 = (Data*)val2;

	if (data1->Score > data2->Score)
		return 1;
	else if (data1->Score < data2->Score)
		return -1;
	else
		return 0;

}

bool Compare2(const Data& val1, const Data& val2)
{
	return val1.Score > val2.Score;
}

void main()
{
	Data datas[USHRT_MAX];
	ReadData(datas);

	Timer timer;

	timer.Start();
	{
		//우리꺼
		QuickSort(datas, 0, USHRT_MAX - 1);
		//WriteData(datas);
	}
	timer.End();
	printf("우리꺼 : %f\n", timer.RunningTime());

	timer.Start();
	{
		//C 스타일
		qsort(datas, USHRT_MAX, sizeof(Data), Compare);
		//WriteData(datas);
	}
	timer.End();
	printf("qsort : %f\n", timer.RunningTime());

	timer.Start();
	{
		//C++ 스타일
		std::sort(datas, datas + USHRT_MAX, Compare2);
	}
	timer.End();
	printf("std::sort : %f\n", timer.RunningTime());
	

	

	

	system("pause");
}