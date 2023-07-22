
#include "headers/commands.h"

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
}

void removeCommand(struct saveFileStruct *storage, int commandsQuantity, char *command)
{
    int i = 0;
    for (i = 0; i < commandsQuantity; i++)
    {
        if (strcmp(storage[i].command, command) == 0)
        {
            // TODO
        }
    }
}

void executeCommand(struct saveFileStruct *storage, int commandsQuantity, char *command)
{
    int i;
    for (i = 0; i < commandsQuantity; i++)
    {
        if (strcmp(command, storage[i].command) == 0)
        {
            char finalCommand[strlen(storage[i].command) + 7];
            strcpy(finalCommand, "start ");
            strcat(finalCommand, storage[i].dir);
            system(finalCommand);
            printf("Excuting Command...\n");
            break;
        }
    }
}
