#ifndef SHELL_H
#define SHELL_H

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>

typedef struct list_s
{
	int num;
	char *str;
	struct list_s *next;
} list_t;

typedef struct info_s
{
	char *arg;
	char **argv;
	char *path;
	char *fname;
	size_t argc;
	list_t *history;
	list_t *env;
	list_t *alias;
	char **environ;
	char **cmd_buf;
	int env_changed;
	int linecount_flag;
	int histcount;
	int readfd;
} info_t;

char *fillMemory(char *target, char byte, unsigned int count);
void freeStringArray(char **stringArray);
void *reallocateMemory(void *pointer, unsigned int oldSize, unsigned int newSize);

list_t *addNode(list_t **head, const char *str, int num);
list_t *addNodeEnd(list_t **head, const char *str, int num);
size_t printListStr(const list_t *h);
int deleteNodeAtIndex(list_t **head, unsigned int index);
void freeList(list_t **head_ptr);

size_t listLength(const list_t *h);
char **listToStrings(list_t *head);
size_t printList(const list_t *h);
list_t *nodeStartsWith(list_t *node, char *prefix, char c);
ssize_t getNodeIndex(list_t *head, list_t *node);

int bfree(void **ptr);

int isCommand(info_t *info, char *path);
char *duplicateChars(char *pathstr, int start, int stop);
char *findPath(info_t *info, char *pathstr, char *cmd);

char *_memset(char *s, char b, unsigned int n);
void ffree(char **pp);
void *_realloc(void *ptr, unsigned int oldSize, unsigned int newSize);

#endif

