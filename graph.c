#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "stmr.h"

static const int N = 100;

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

wordNet *start = NULL;

void print(RootWord *head, FILE *ptr, int write);
RootWord *addRootWord(RootWord *head, char *word);
wordNet *addWordNet(RootWord *head);
void printWordNet(FILE *ptr);
wordNet *find(char *rootToken);
void insertWordNet(char *rootToken, char *tokenWord);

RootWord *addRootWord(RootWord *head, char *word)
{
    RootWord *temp = head;
    RootWord *newnode = (RootWord *)malloc(sizeof(RootWord));
    newnode->token = word;
    newnode->next = NULL;
    if (temp == NULL)
    {
        // printf("123%s\n", newnode->token);
        return newnode;
    }
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newnode;
    // printf("%s\n", head->token);
    return head;
}

void printRootWord(RootWord *head, FILE *ptr, int write)
{
    if (head == NULL)
        return;
    if (write) // write 1==>writing the map in file
    {
        while (head != NULL)
        {
            if (ptr == NULL)
            {
                printf("Error Opening Graph File\n");
                exit(1);
                // return;
            }
            fputs(head->token, ptr);
            fputs("-->", ptr);
            printf("%s-->", head->token);
            head = head->next;
        }
        fputs("NULL\n", ptr);
        printf("NULL\n");
    }
    else // write= 0 means just printing it on terminal
    {
        while (head != NULL)
        {
            printf("%s-->", head->token);
            head = head->next;
        }
        printf("NULL\n");
    }

    return;
}

wordNet *addWordNet(RootWord *head)
{
    wordNet *temp = start;
    wordNet *newnode = (wordNet *)malloc(sizeof(wordNet));
    newnode->rootword = head;
    newnode->next = NULL;
    if (start == NULL)
    {
        return newnode;
    }
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newnode;
    return start;
}

void printWordNet(FILE *ptr)
{
    while (start != NULL)
    {
        printRootWord(start->rootword, ptr, 1);
        start = start->next;
    }
    return;
}

wordNet *find(char *rootToken)
{
    wordNet *temp = start;
    while (temp != NULL)
    {
        // if(temp->rootword->token==ch)
        if (!strcmp(temp->rootword->token, rootToken))
        {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

void insertWordNet(char *rootToken, char *tokenWord)
{
    wordNet *node = find(tokenWord);
    if (node == NULL)
    {
        // printf("%s   ", rootToken);
        RootWord *head = NULL;
        head = addRootWord(head, tokenWord);
        head = addRootWord(head, rootToken);
        start = addWordNet(head);
        // printWordNet();
    }
    else
    {
        node->rootword = addRootWord(node->rootword, rootToken);
    }
}

void printRelation(char *tokenWord, FILE *ptr)
{
    wordNet *temp = find(tokenWord);
    if (temp == NULL)
    {
        printf("Sorry %s not found in dictonary\n", tokenWord);
    }
    else
    {
        printRootWord(temp->rootword, NULL, 0);
    }
}

int main()
{

    RootWord *head = NULL;

    char *fn(char *source)
    {
        // char source[] = "programming";
        char *word = strdup(source);
        int end = stem(word, 0, strlen(word) - 1);
        word[end + 1] = 0;
        // printf("%s\n", word);
        return word;
    }

    FILE *input;
    FILE *output;
    FILE *graph;
    char str[50];
    input = fopen("fixture/abc.txt", "a+");
    output = fopen("fixture/efg.txt", "w");
    graph = fopen("fixture/123.txt", "w");

    if (NULL == input)
    {
        printf("file can't be opened \n");
    }

    while (fgets(str, 50, input) != NULL)
    {
        char *t = (char *)malloc(sizeof(str) - 1);
        memcpy(t, str, strlen(str) - 1);
        head = addRootWord(head, t);
        insertWordNet(t, fn(t));
        fputs(fn(t), output);
        fputs("\n", output);
    }

    char *tokenWord = "program";
    printRelation(tokenWord, graph);

    fclose(input);
    fclose(output);
    fclose(graph);
    return 0;
}

// final : main.o stmr.o demo.o
// 	gcc -o final main.o stmr.o demo.o

// abc : graph.o stmr.o
// 	gcc -o abc graph.o stmr.o
