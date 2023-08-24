#ifndef SHELL_H
#define SHELL_H

typedef struct {
    int readFileDesc;
} info_t;

int checkInteractiveMode(info_t *infoData);
int checkDelimiter(char character, char *delimiter);
int checkAlphabetic(int character);
int convertToInteger(char *str);

#endif
