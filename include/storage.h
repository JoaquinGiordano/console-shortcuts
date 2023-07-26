#ifndef STORAGE_H
#define STORAGE_H

#include <stdio.h>
#include <stdlib.h>

#include "macros.h"
#include "constants.h"
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

struct saveFileStruct
{
    char command[MAX_COMMAND_LENGHT];
    char dir[MAX_DIR_LENGHT];
};

FILE *createSaveFile();
void deleteSaveFile();
long getFileSize(FILE *f);
void showStorage(struct saveFileStruct *storage, long n);
void loadStorage(FILE *f, struct saveFileStruct *storage);
int getStorage(struct saveFileStruct *storage);

#endif