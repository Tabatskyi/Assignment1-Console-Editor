#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE  
#define _CRT_NONSTDC_NO_DEPRECATE

#include <stdio.h>
#include <stdlib.h> 
#include <string.h>


const int MAX_LINES = 100;
const int MAX_LENGTH = 256;

char memory[MAX_LINES][MAX_LENGTH];
int currentLine = 0;

int main()
{
	start:
	char command;
	char inputBuffer[MAX_LENGTH] = { 0 };
	FILE* file;
	char filename[100] = "myfile.txt";
	printf(">");

	(void)scanf(" %c", &command);

	switch (command)
	{
	case 'a':
		printf(">Enter text to append: ");
		(void)scanf(" %s", &inputBuffer);

		if (strlen(memory[currentLine]) + strlen(inputBuffer) < MAX_LENGTH) 
		{
			strcat(memory[currentLine], inputBuffer);
		}
		else 
		{
			printf("Error: Line length exceeds the maximum allowed.\n");
		}
			break;
	case 'n':
		printf(">New line started\n");
		if (currentLine < MAX_LINES - 1) 
		{
			currentLine++;
		}
		else 
		{
			printf("Error: Reached maximum number of lines.\n");
		}
			break;
	case 's':
		printf(">Enter filename for saving: ");
		(void)scanf(" %s", &filename);

		file = fopen(filename, "w");
		if (file != NULL)
		{
			for (int i = 0; i <= currentLine; i++) 
			{
				fprintf(file, "%s\n", memory[i]);
			}
			fclose(file);
		}
		else 
		{
			printf(">Error opening file\n");
		}
			break;
	case 'l':
		printf(">Enter filename for loading: ");
		(void)scanf(" %s", &filename);

		file = fopen(filename, "r");
		if (file == NULL)
		{
			printf(">Error opening file\n");
		}
		else
		{
			while (fgets(inputBuffer, MAX_LENGTH, file) != NULL) 
			{
				strcat(memory[currentLine], inputBuffer);
			}
			fclose(file);
		}
			break;
	case 'p':
		for (int i = 0; i <= currentLine; i++) 
		{
			printf("%d: %s\n", i + 1, memory[i]);
		}
			break;
	case 'i':
		printf(">not implemented yet\n");
			break;
	case 'f':
		printf(">not implemented yet\n");
			break;
	default:
		printf(">unknown function\n");
			break;
	}
	goto start;

	return 0;
}
