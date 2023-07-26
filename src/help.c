#include "../include/help.h"

void showHelpMessage()
{
    printf("\n\033[36musage: cs <command> | cs <function> <parameters> \033[0m\n\n"
           "\033[36mFunctions:\033[0m\n"
           "cs add <command> <path>\t\tAdds a command\n"
           "cs rm <command> <path>\t\tRemoves a command\n"
           "cs clear \t\t\tRemoves all the commands\n"
           "cs ls \t\t\t\tLists all the commands\n"
           "cs help \t\t\tShow this message\n\n"
           "\033[36mExamples:\033[0m\n"
           "cs add example https://example.com/\n"
           "cs add myDocuments \"C:\\Users\\DefaultUser\\Documents\"\n"
           "cs add vlc \"C:\\Program Files\\VideoLAN\\VLC\\vlc.exe\"\n"
           "cs rm example\n\n");
}