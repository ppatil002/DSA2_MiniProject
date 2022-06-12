#include <stdio.h>
#include <string.h>
#include "stmr.h"
#include "options.h"

int main()
{
    while (1)
    {
        printf("\t\t\tWELCOME TO PORT STEMMER LIBRARY\n");
        printf("\tSelect the options\n");
        printf("\t1) Train the DataSet from File\n");
        printf("\t2) Print the Avaliable WordNet\n");
        printf("\t3) Print the Specific Relation of Stemed Word\n");
        printf("\t4) Finding the Port Stemmer of particular word\n");
        printf("\t5) To Exit the program\n");

        int option;
        printf("Enter the Option: ");
        scanf("%d", &option);
        printf("\n");
        if (option == 1)
        {
            option1();
            printf("-----------------------------------------\n");
        }
        else if (option == 2)
        {
            option2();
            printf("-----------------------------------------\n");
        }
        else if (option == 3)
        {
            option3();
            printf("-----------------------------------------\n");
        }
        else if (option == 4)
        {
            option4();
            printf("-----------------------------------------\n");
        }
        else if (option == 5)
        {
            break;
        }
        else
        {
            printf("Please Enter Valid Option\n");
            printf("-----------------------------------------\n");
        }
    }
    return 0;
}
