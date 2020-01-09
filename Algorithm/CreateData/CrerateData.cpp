#include <Windows.h>
#include <stdio.h>
#include <time.h>


void main()
{
	srand((UINT)time(NULL));

	FILE* fp;

	fopen_s(&fp, "data.txt", "w");

	for (size_t i = 0; i < USHRT_MAX; i++)
		fprintf(fp, "%d, %d\n", i, rand());

	fclose(fp);

	printf("New File\n");
	system("pause");


}