#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE  
#define _CRT_NONSTDC_NO_DEPRECATE

#include <stdio.h>
#include <string.h>


const int MAX_LINES = 100;
const int MAX_LENGTH = 256;

char memory[MAX_LINES][MAX_LENGTH];
int currentLine = 0;

int main()
{
	start:
	char command;
	char inputBuffer[MAX_LENGTH];
	printf(">");

	(void)scanf(" %c", &command);

	printf(">");

	switch (command)
	{
	case 'a':
		printf("Enter text to append: ");
		fgets(inputBuffer, MAX_LENGTH, stdin);

		inputBuffer[strcspn(inputBuffer, "\n")] = 0;
		strncpy(memory[currentLine], inputBuffer, MAX_LENGTH);

		printf("Text appended.\n");
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
		//(void)scanf("%c", &command);
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
