#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "stmr.h"
#include "wordnet.h"

wordNet *start = NULL;

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
    wordNet *temp = start;
    while (temp != NULL)
    {
        printRootWord(temp->rootword, ptr, 1);
        temp = temp->next;
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
        printRootWord(temp->rootword, ptr, 0);
    }
}
