#include <stdio.h>
#include <string.h>
#include "constants.h"
#include "storage.h"

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
    else
        printf("You are executing something");

    printf("Commands: %i\n", commandsQuantity);

    return 0;
}