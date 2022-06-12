#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "stmr.h"

typedef struct RootWord
{
    char *token;
    struct RootWord *next;
} RootWord;

typedef struct wordNet
{
    RootWord *rootword;
    struct wordNet *next;

} wordNet;

void print(RootWord *head, FILE *ptr, int write);
RootWord *addRootWord(RootWord *head, char *word);
wordNet *addWordNet(RootWord *head);
void printWordNet(FILE *ptr);
wordNet *find(char *rootToken);
void insertWordNet(char *rootToken, char *tokenWord);
void printRelation(char *tokenWord, FILE *ptr);
