#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char pathname[40];
    char file[40][40];
    int file_count = 0;
    char *start = pathname;
    char *slash;
    int i;
    
    scanf("%s", pathname);
    if (*start == '/')
        start++;
    while (start != NULL)
    {
        slash = strchr(start, '/');
        if (slash == NULL)
        {
            strcpy(file[file_count], start);
            file_count++;
            start = NULL;
        }
        else
        {
            strncpy(file[file_count], start, slash - start);
            file[file_count][slash - start] = '\0';
            file_count++;
            start = slash + 1;
        }
    }
    for (i = 0; i < file_count; i++)
        printf("%s\n", file[i]);
    
    return 0;
}
