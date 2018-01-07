#include <stdio.h>
#include <stdlib.h>

char *strtrim(char *str, const char *delim)
{
    int valid_char_count = 0;
    char *sp, *dp, cc, cd;

    sp = str;
    
    while((cc = *sp++) != '\0') {
        dp = delim;
        while((cd = *dp++) != '\0')
            if (cc == cd)
                valid_char_count++;
    }

    printf("Found %d valid chars.\n", valid_char_count);

    char *out = (char *) malloc(valid_char_count + 1);

    int i = 0;
    while((cc = *str++) != '\0') {
        dp = delim;
        while((cd = *dp++) != '\0') {
            if (!(cc == cd)) {
                *(out + i++) = cc;
                printf("%c is valid\n", cc);
            }
        }    
    }
    return out;
}

int main()
{
    printf("%s\n", strtrim(", abcd. ", " ,."));

    return 0;
}