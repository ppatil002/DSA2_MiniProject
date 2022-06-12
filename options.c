#include <stdio.h>
#include <string.h>
#include "stmr.h"
#include "wordnet.h"
#include "options.h"

void option1()
{
    RootWord *head = NULL;

    FILE *input;
    FILE *output;
    FILE *graph;
    char str[50];
    input = fopen("files/inputData.txt", "r");
    output = fopen("files/outputData.txt", "w");
    graph = fopen("files/wordnet.txt", "w");

    char *fn(char *source)
    {
        // char source[] = "programming";
        char *word = strdup(source);
        int end = stem(word, 0, strlen(word) - 1);
        word[end + 1] = 0;
        // printf("%s\n", word);
        return word;
    }

    if (input == NULL)
    {
        printf("Error Opening Input File\n");
        exit(1);
    }
    else if (output == NULL)
    {
        printf("Error Opening Output File\n");
        exit(1);
    }
    else if (graph == NULL)
    {
        printf("Error Opening Graph File\n");
        exit(1);
    }

    while (fgets(str, 50, input) != NULL)
    {
        char *t = (char *)malloc(sizeof(str) - 1);
        memcpy(t, str, strlen(str) - 1);
        insertWordNet(t, fn(t));
        fputs(fn(t), output);
        fputs("\n", output);
    }
    printWordNet(graph);
    printf("\nTraining Completed Successfully\n");

    fclose(input);
    fclose(output);
    fclose(graph);
    return;
}

void option2()
{
    FILE *graph;
    graph = fopen("files/wordnet.txt", "r");
    if (graph == NULL)
    {
        printf("Error Opening Graph File\n");
        exit(1);
    }
    char ch;
    while ((ch = fgetc(graph)) != EOF)
    {
        putchar(ch);
    }
    printf("\n");
    fclose(graph);
}

void option3()
{
    FILE *graph;
    graph = fopen("files/wordnet.txt", "r");

    char tokenWord[20];
    printf("Please Enter the Word to find Relation: ");
    scanf("%s", tokenWord);
    char *ptr = (char *)malloc(sizeof(tokenWord));
    memcpy(ptr, tokenWord, strlen(tokenWord));
    printRelation(ptr, graph);

    fclose(graph);
}

void option4()
{
    char *fn(char *source)
    {
        // char source[] = "programming";
        char *word = strdup(source);
        int end = stem(word, 0, strlen(word) - 1);
        word[end + 1] = 0;
        printf("%s\n", word);
        return word;
    }

    char str[20];
    printf("Please Enter the Word to be stemmed: ");
    scanf("%s", str);
    char *t = (char *)malloc(sizeof(str) - 1);
    memcpy(t, str, strlen(str) - 1);
    fn(t);
}
