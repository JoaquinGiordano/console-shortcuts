#include <stdio.h>
#include <stdlib.h>

#include "constants.h"

struct saveFileStruct
{
    char command[MAX_COMMAND_LENGHT];
    char dir[MAX_DIR_LENGHT];
};

FILE *createSaveFile();
long getFileSize(FILE *f);
void addCommand(char *command, char *dir);
void loadStorage(FILE *f, struct saveFileStruct *storage);
int getStorage(struct saveFileStruct *storage);

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

void addCommand(char *command, char *dir)
{
    DEBUG_PRINT("Adding Command...\n");
    FILE *f = fopen(SAVE_PATH, "rb+");
    struct saveFileStruct data;
    fseek(f, 0, SEEK_END);
    strncpy(data.command, command, MAX_COMMAND_LENGHT);
    strncpy(data.dir, dir, MAX_DIR_LENGHT);
    fwrite(&data, sizeof(data), 1, f);
    fclose(f);
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