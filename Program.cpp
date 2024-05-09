#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main()
{
	FILE* file;
	char mystring[100];
	file = fopen("MyFile.txt", "r");
	if (file == NULL)
	{
		printf("Error opening file");
	}
	else
	{
		if (fgets(mystring, 100, file) != NULL)
		{
			printf("%s\n", &mystring);
			goto nahui;

		nahui:
			printf("idi nahui\n");

		}
		fclose(file);
	}

	return 0;
}
