#include <stdio.h>
#include <stdlib.h>

int main()
{
    int userOptionChoice;

    // starting the app
    printf("#### TODO LIST ####\n\n");

    // welcome the user
    //printf("Hello user!\n\n");

    //display the start menu
askTheUserToChoose:
    printf("=> Option 1: View To-Do List\n");
    printf("=> Option 2: create a New To-Do List\n");
    printf("=> Option 3: Exit\n");

    /* after choosing the first option

    printf("- Option 3: Mark To-Do List Complete\n");
    printf("- Option 4: Delete To-Do List\n");

    */


    printf("\n-> What would you like to do next? : ");
    scanf("%d", &userOptionChoice);

    switch(userOptionChoice){
    case 1:
        printf("call the function that display the to-do list titels that are existes ");
        break;
    case 2:
        printf("call the function that create a new to-do list ");
        break;
    case 3:
        printf("the app is closed.");
        exit(1);
        break;
    default:
        printf("\n--------------------------------------\n");
        printf("Invalid input. Please try again.\n");
        printf("--------------------------------------\n\n");
        goto askTheUserToChoose;

    }
   /* // check if the user want to create a new to-do list or not
    if(userResponseToCreateNewList == 'Y' || userResponseToCreateNewList == 'y')
    {

        // call the function that is responsible for creating new to-do listes
        printf("starting creating a new to-do list...");
    }
    else if(userResponseToCreateNewList == 'N' || userResponseToCreateNewList == 'n')
    {

        // show the existing to do lists.
        printf("no to-do list will be created");
    }
    else
    {
        // handle invalid inputs
        printf("Please enter 'Y' for yes or 'N' for no.");
        goto askTheUserToCreatNewToDo;
    }
    */
    return 0;
}