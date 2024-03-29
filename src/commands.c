#include "../include/commands.h"

void addCommand(char *command, char *dir)
{
    DEBUG_PRINT("Adding Command...\n");
    FILE *f = fopen(SAVE_PATH, "rb+");
    struct saveFileStruct data;
    fseek(f, 0, SEEK_END);
    data.command[0] = '\0';
    data.dir[0] = '\0';
    strncat(data.command, command, MAX_COMMAND_LENGHT - 1);
    strncat(data.dir, dir, MAX_COMMAND_LENGHT - 1);
    fwrite(&data, sizeof(data), 1, f);
    fclose(f);
    printf("\033[32mCommand Added Successfully\033[0m");
}

void removeCommand(struct saveFileStruct *storage, long *commandsQuantity, char *command)
{
    int i = 0;
    for (i = 0; i < *commandsQuantity; i++)
    {
        if (strcmp(storage[i].command, command) == 0)
        {
            while (i < *commandsQuantity - 1)
            {
                storage[i] = storage[i + 1];
                i++;
            }
            (*commandsQuantity)--;
            free(&storage[i]);
            FILE *f = fopen(SAVE_PATH, "wb");
            fseek(f, 0, SEEK_SET);
            fwrite(storage, sizeof(struct saveFileStruct), *commandsQuantity, f);
            fclose(f);
            printf("\033[32mCommand Removed Successfully\033[0m");
            return;
        }
    }
    printf("\033[31mThat command does not exist\033[0m");
}

void executeCommand(struct saveFileStruct *storage, long *commandsQuantity, char *command)
{
    int i;
    for (i = 0; i < *commandsQuantity; i++)
    {
        if (strcmp(command, storage[i].command) == 0)
        {
            char finalCommand[(long int)strlen(storage[i].dir) + 12];

            strcpy(finalCommand, "start \"\" \"");
            strcat(finalCommand, storage[i].dir);
            strcat(finalCommand, "\"");
            system(finalCommand);
            printf("\033[32mExcuting \"%s\"...\033[0m", command);
            return;
        }
    }
    printf("\033[31mCommand \"%s\" not found\033[0m", command);
}
