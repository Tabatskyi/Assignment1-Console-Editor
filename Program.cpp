#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE  
#define _CRT_NONSTDC_NO_DEPRECATE

#include <stdio.h>

int main()
{
	start:
	char command;
	printf("> ");

	(void)scanf("%c", &command);

	switch (command)
	{
	case 'a':
		printf("not implemented yet");
			break;
	case 'n':
		printf("not implemented yet");
			break;
	case 's':
		printf("not implemented yet");
			break;
	case 'l':
		printf("not implemented yet");
			break;
	case 'p':
		printf("not implemented yet");
			break;
	case 'i':
		printf("not implemented yet");
			break;
	case 'f':
		printf("not implemented yet");
			break;
	default:
		printf("unknown function\n");
		(void)scanf("%c", &command);
		goto start;
			break;
	}
	printf("\n");

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
		}
		fclose(file);
	}

	return 0;
}
