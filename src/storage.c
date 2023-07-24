#include "../include/storage.h"

FILE *createSaveFile()
{
    DEBUG_PRINT("Creating savefile...\n");
    FILE *saveFile = fopen(SAVE_PATH, "wb+");
    return saveFile;
}

long getFileSize(FILE *f)
{
    long actualPos = ftell(f);
    long size;
    fseek(f, 0, SEEK_END);
    size = ftell(f);
    fseek(f, actualPos, SEEK_SET);
    return size;
}

void showStorage(struct saveFileStruct *storage, long n)
{
    int i;
    printf("\n");
    for (i = 0; i < n; i++)
    {
        printf("\033[34mCommand:\033[0m %s\n", storage[i].command);
        printf("\033[36mPath:\033[0m %s\n\n", storage[i].dir);
    }
}

void loadStorage(FILE *f, struct saveFileStruct *storage)
{
    DEBUG_PRINT("Loading Storage...\n");
    fread(storage, sizeof(struct saveFileStruct), getFileSize(f) / sizeof(struct saveFileStruct), f);
}

// Returns the commandsQuantity
int getStorage(struct saveFileStruct *storage)
{
    DEBUG_PRINT("Getting Storage...\n");
    FILE *saveFile = fopen(SAVE_PATH, "rb+");

    if (saveFile == NULL)
        saveFile = createSaveFile();

    long saveFileSize = getFileSize(saveFile);
    long commandsQuantity = saveFileSize / sizeof(struct saveFileStruct);

    if (commandsQuantity > DEFAULT_STORAGE_SIZE)
    {
        DEBUG_PRINT("Resizing Storage... \n");
        storage = (struct saveFileStruct *)realloc(storage, getFileSize(saveFile));
    }

    loadStorage(saveFile, storage);

    fclose(saveFile);
    return commandsQuantity;
}
