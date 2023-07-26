#include "../include/program.h"

int main(int argc, char *argv[])
{
    struct saveFileStruct storage[DEFAULT_STORAGE_SIZE];
    long commandsQuantity = getStorage(storage);
    char *command = argv[1];

    if (strcmp(command, "help") == 0)
    {
        showHelpMessage();
    }
    else if (strcmp(command, "add") == 0)
        addCommand(strdup(argv[2]), strdup(argv[3]));
    else if (strcmp(command, "list") == 0 || strcmp(command, "ls") == 0)
        showStorage(storage, commandsQuantity);

    else if (strcmp(command, "remove") == 0 || strcmp(command, "rm") == 0)
        removeCommand(storage, &commandsQuantity, strdup(argv[2]));
    else if (strcmp(command, "clear") == 0)
        deleteSaveFile();
    else
        executeCommand(storage, &commandsQuantity, argv[1]);
    return 0;
}
