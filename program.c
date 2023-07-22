#include <stdio.h>
#include <string.h>

#ifndef CONSTANTS_H
#define CONSTANTS_H
#include "constants.h"
#endif

#ifndef STORAGE_H
#define STORAGE_H
#include "storage.h"
#endif

#ifndef COMMANDS_H
#define COMMANDS_H
#include "commands.h"
#endif

int main(int argc, char *argv[])
{
    struct saveFileStruct storage[DEFAULT_STORAGE_SIZE];
    long commandsQuantity = getStorage(storage);

    char *command = argv[1];

    if (strcmp(command, "help") == 0)
        printf("You asked for help");
    else if (strcmp(command, "add") == 0)
    {
        addCommand(strdup(argv[2]), strdup(argv[3]));
        commandsQuantity++;
    }
    else if (strcmp(command, "list") == 0 || strcmp(command, "ls") == 0)
    {
        showStorage(storage, commandsQuantity);
    }
    else if (strcmp(command, "remove") == 0 || strcmp(command, "rm") == 0)
    {
        showStorage(storage, commandsQuantity);
    }
    else
    {
        executeCommand(storage, commandsQuantity, argv[1]);
    }

    return 0;
}