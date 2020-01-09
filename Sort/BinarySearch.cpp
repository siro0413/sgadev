#include <Windows.h>
#include <stdio.h>

#include "Timer.h"

struct Data
{
	UINT Number;
	UINT Score;
};

//���� �о����
void ReadData(Data* datas)
{
	FILE* file;
	fopen_s(&file, "./Result.txt", "r");
	{
		for (UINT i = 0; i < USHRT_MAX; i++)
			fscanf_s(file, "%d ,%d", &datas[i].Number, &datas[i].Score);
	}
	fclose(file);
}

//���� Ž��
Data* SequenceSearch(Data* datas, UINT size, UINT target, OUT int& count)
{
	count = 0;
	Data* result = NULL;

	for (UINT i = 0; i < size; i++)
	{
		if (target == datas[i].Score)
		{
			count = i;
			result = &datas[i];

			break;
		}
	}

	return result;
}

//���� Ž��
Data* BinarySearch(Data* datas, UINT size, UINT target, OUT int& count)
{
	count = 0;

	int left = 0;
	int right = size - 1;

	while (left <= right)
	{
		int middle = (left + right) / 2;

		if (target == datas[middle].Score)
			return &datas[middle];

		else if (target > datas[middle].Score)
			left = middle + 1;
		else if (target < datas[middle].Score)
			right = middle - 1;

		count++;
	}

	return NULL;
}

void main()
{
	Data datas[USHRT_MAX];
	ReadData(datas);

	int target = 65533;
	int count = 0;

	Timer timer;

	timer.Start();
	{
		Data* result = SequenceSearch(datas, USHRT_MAX, target, count);
	}
	timer.End();
	printf("����Ž�� �ð� : %f, �� �� ���� ã�Ƴ� : %d\n", timer.RunningTime(), count);

	timer.Start();
	{
 		Data* result = BinarySearch(datas, USHRT_MAX, target, count);
	}
	timer.End();
	printf("����Ž�� �ð� : %f, �� �� ���� ã�Ƴ� : %d\n", timer.RunningTime(), count);

	system("pause");
}