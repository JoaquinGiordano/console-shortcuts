

#ifndef COMMANDS_H
#define COMMANDS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "macros.h"
#include "constants.h"
#include "storage.h"

void addCommand(char *command, char *dir);
void executeCommand(struct saveFileStruct *storage, int commandsQuantity, char *command);

#endif
