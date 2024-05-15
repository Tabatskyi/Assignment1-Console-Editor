#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE  
#define _CRT_NONSTDC_NO_DEPRECATE

#include <stdio.h>
#include <stdlib.h> 
#include <string.h>

int currentLinesNum = 100;
int currentLenghNum = 256;

char** memory;
int currentLine = 0;

void freeMemory(char** memory)
{
    for (int i = 0; i < currentLinesNum; i++) 
    {
        free(memory[i]);
    }
    free(memory);
}

int main() {
    memory = (char**)malloc(currentLinesNum * sizeof(char*));
    if (!memory) 
    {
        printf("Memory allocation failed.\n");
        return 1;
    }
    for (int i = 0; i < currentLinesNum; i++) 
    {
        memory[i] = (char*)malloc(currentLenghNum * sizeof(char));
        if (!memory[i]) {
            printf("Memory allocation failed.\n");

            freeMemory(memory);
            return 1;
        }
        memory[i][0] = 0;  
    }

    char command;
    char* inputBuffer = (char*)malloc(currentLinesNum * sizeof(char));
    FILE* file;
    char filename[100] = "myfile.txt";

start:
    printf(">");
    (void)scanf(" %c", &command);

    switch (command) 
    {
    case 'a':
        printf(">Enter text to append: ");
        (void)scanf(" %[^\n]s", inputBuffer);

        if (strlen(memory[currentLine]) + strlen(inputBuffer) < currentLenghNum) 
        {
            strcat(memory[currentLine], inputBuffer);
        }
        else 
        {
            perror(">Error: Line length exceeds the maximum allowed.\n");
        }
        break;
    case 'n':
        printf(">New line started\n");
        if (currentLine < currentLinesNum - 1) 
        {
            currentLine++;
        }
        else 
        {
            perror(">Error: Reached maximum number of lines.\n");
        }
            break;
    case 's':
        printf(">Enter filename for saving: ");
        (void)scanf(" %s", filename);

        file = fopen(filename, "w");
        if (file != NULL) {
            for (int i = 0; i <= currentLine; i++) 
            {
                fprintf(file, "%s\n", memory[i]);
            }
            fclose(file);
            printf(">Save successful\n");
        }
        else 
        {
            printf(">Error opening file\n");
        }
            break;
    case 'l':
        printf(">Enter filename for loading: ");
        (void)scanf(" %s", filename);

        file = fopen(filename, "r");
        if (file != NULL) 
        {
            currentLine = 0;
            while (fgets(inputBuffer, currentLenghNum, file) != NULL && currentLine < currentLinesNum) 
            {
                inputBuffer[strlen(inputBuffer) - 1] = 0;  
                strcpy(memory[currentLine], inputBuffer);

                if (currentLine++ >= currentLinesNum) 
                {
                    printf(">Reached maximum capacity\n");
                    break;
                }
            }
            fclose(file);
            currentLine--;
            printf(">Load successful\n");
        }
        else 
        {
            perror(">Error opening file\n");
        }
        break;
    case 'p':
        for (int i = 0; i <= currentLine; i++) 
        {
            printf("%d: %s\n", i + 1, memory[i]);
        }
        break;
    case 'i':
        int line, index;
        printf(">Choose line: ");
        (void)scanf(" %d", &line);
        printf(">Choose index: ");
        (void)scanf(" %d", &index);



        break;
    case 'f':
        printf(">not implemented yet\n");
        break;
    default:
        printf(">unknown function\n");
        break;
    }
    goto start;

    freeMemory(memory);

    return 0;
}
