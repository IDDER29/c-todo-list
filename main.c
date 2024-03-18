#include <stdio.h>
#include <stdlib.h>

void display_the_todo_lists()
{

    printf("call the function that display the to-do list titls that are existes ");

}

void create_a_todo_list()
{
    char *title = NULL;
    char *task = NULL;
    int priority ;
    int duration;

    title = (char*)malloc(sizeof(char) * 50);
    if (title == NULL)
    {
        printf("Memory allocation failed for title.\n");
        return;
    }
    task = (char*)malloc(sizeof(char) * 50);
    if (task == NULL)
    {
        printf("Memory allocation failed for task.\n");
        free(title); // Free allocated memory for title before returning
        return;
    }


    printf("\n--- create a new to-do list ---\n\n");

    // get the title of the to-do list
    printf("-> Enter a title that reflects your goals for this to-do list : ");
      //fgets(title, 49, stdin);
      //getchar();
    scanf(" %[^\n]", title);

    // start geting the tasks of the todo list
    printf("\n-> Please describe your task: ");
    //fgets(task, 49, stdin);
    //getchar();
    scanf(" %[^\n]", task);

    printf("\n-> What is it's level of priority (1,2,3,4) : ");
    scanf("%d", &priority);

    printf("\n-> How long did you anticipate this would take to complete in minutes? : ");
    scanf("%d", &duration);

    printf("\nthe title is %s\n", title);
    printf("the task is %s\n", task);
    printf("the priority is %d\n", priority);
    printf("the duration is %d\n", duration);

}

int main()
{
    int userOptionChoice;

    // starting the app
    printf("#### TODO LIST APP ####\n\n");

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

    switch(userOptionChoice)
    {
    case 1:
        display_the_todo_lists();
        break;
    case 2:
        create_a_todo_list();
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
