#include <stdio.h>

int func4(int edx, int esi, int edi)
{
	int eax = edx;
	eax = eax - esi;
	int ecx = eax;
	ecx = (ecx >>31) & (0x1);
	eax = eax + ecx;
	eax = eax >> 1;
	ecx = eax + esi;
	if (ecx <= edi)
	{
		eax = 0;
		if (ecx >= edi)
		{
			return eax;
		}
		else
		{
			esi = ecx + 1;
			eax = func4(edx, esi, edi);
			eax = eax + eax + 1;
			return eax;
		}
	}
	else
	{
		edx = ecx - 1;
		eax = func4(edx, esi, edi);
		eax = eax + eax;
		return eax;
	}
}

int main()
{
	int edx = 14;
	int esi = 0;
	int arg = 0;
	int returnVal = func4(edx, esi, 0);
	printf("it worked: %d\n\r", returnVal);

	returnVal = func4(edx, esi, 1);
	printf("it worked: %d\n\r", returnVal);

	returnVal = func4(edx, esi, 2);
	printf("it worked: %d\n\r", returnVal);

	returnVal = func4(edx, esi, 3);
	printf("it worked: %d\n\r", returnVal);

	returnVal = func4(edx, esi, 4);
	printf("it worked: %d\n\r", returnVal);

	returnVal = func4(edx, esi, 5);
	printf("it worked: %d\n\r", returnVal);

	returnVal = func4(edx, esi, 6);
	printf("it worked: %d\n\r", returnVal);


	returnVal = func4(edx, esi, 7);
	printf("it worked: %d\n\r", returnVal);

	returnVal = func4(edx, esi, 8);
	printf("it worked: %d\n\r", returnVal);

	returnVal = func4(edx, esi, 9);
	printf("it worked: %d\n\r", returnVal);

	returnVal = func4(edx, esi, 10);
	printf("it worked: %d\n\r", returnVal);

	returnVal = func4(edx, esi, 11);
	printf("it worked: %d\n\r", returnVal);


	returnVal = func4(edx, esi, 12);
	printf("it worked: %d\n\r", returnVal);

	returnVal = func4(edx, esi, 13);
	printf("it worked: %d\n\r", returnVal);

	returnVal = func4(edx, esi, 14);
	printf("it worked: %d\n\r", returnVal);

	return 0;
}
