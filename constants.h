// #define DEBUG

#ifdef DEBUG
#define DEBUG_PRINT(x) printf(x)
#else
#define DEBUG_PRINT(x) \
    do                 \
    {                  \
    } while (0)
#endif

#define SAVE_PATH "./save.sf"
#define MAX_COMMAND_LENGHT 50
#define MAX_DIR_LENGHT 200
#define DEFAULT_STORAGE_SIZE 10
