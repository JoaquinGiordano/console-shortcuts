

#ifndef COMMANDS_H
#define COMMANDS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "macros.h"
#include "constants.h"
#include "storage.h"

void addCommand(char *command, char *dir);
void removeCommand(struct saveFileStruct *storage, long *commandsQuantity, char *command);
void executeCommand(struct saveFileStruct *storage, long *commandsQuantity, char *command);

#endif
