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

    do
    {
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
                printf(">Error: Line length out of range\n");
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
                printf(">Error: Reached maximum range of lines\n");
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
                        printf(">Error: Reached maximum capacity\n");
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
                printf("%d: %s\n", i, memory[i]);
            }
            break;

        case 'i':
            char* firstPart;
            char* secondPart;
            int line;
            int index;

            printf(">Choose line and index: ");
            (void)scanf("%d %d", &line, &index);

            if (line < 0 || line >= currentLinesNum || index < 0 || index >= currentLenghNum)
            {
                printf(">Error index out of range\n");
                break;
            }

            printf(">Enter text to insert: ");
            (void)scanf(" %[^\n]", inputBuffer);

            firstPart = (char*)malloc(currentLenghNum * sizeof(char));
            secondPart = (char*)malloc(currentLenghNum * sizeof(char));

            strncpy(firstPart, memory[line], index);
            firstPart[index] = '\0';

            strcpy(secondPart, memory[line] + index);

            if (strlen(firstPart) + strlen(inputBuffer) + strlen(secondPart) < currentLenghNum)
            {
                strcat(firstPart, inputBuffer);
                strcat(firstPart, secondPart);
                strcpy(memory[line], firstPart);
            }
            else
            {
                printf(">Error: index out of range\n");
            }

            free(firstPart);
            free(secondPart);
            break;

        case 'f':
            int position;
            bool found;

            printf(">Enter text to search: ");
            (void)scanf(" %[^\n]", inputBuffer);

            found = false;
            for (int i = 0; i <= currentLine; i++)
            {
                char* result = strstr(memory[i], inputBuffer);

                position = result - memory[i];
                while (result != NULL)
                {
                    position = result - memory[i]; 
                    printf(">Found occurrence at %d %d\n", i, position);
                    found = true;

                    result = strstr(result + strlen(inputBuffer), inputBuffer);
                }
            }
            if (!found)
            {
                printf(">No occurrence found\n");
            }
            break;

        case 'q':
            printf(">Goodbye!\n");
            break;

        default:
            printf(">unknown function\n");
            break;
        }
    } while (command != 'q');

    freeMemory(memory);

    return 0;
}
