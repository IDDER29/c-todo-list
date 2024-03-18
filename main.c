#include <stdio.h>
#include <stdlib.h>

int minites_To_hours(int min){
    int minites = min%60;
    int hours = min/60;

}

void display_the_todo_lists()
{

    printf("call the function that display the to-do list titles that are exist.");

}

void display_the_todo_list_items()
{

    printf("this function display the to-do list items that are exist.");

       /*
    printf("\n<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n");
    printf("=> the title is : %s\n", title);
    printf("<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n\n");
    printf("=> the first task is : %s\n", task);
    printf("=> the second task is : %s\n", task);
    printf("=> the third task is : %s\n", task);
    printf("=> the forth task is : %s\n", task);
    ...
    ...
    ...

    */

}

void display_the_todo_list_item_details()
{

    printf("this function display the to-do list item details and provide options to edit it.");

       /*
    printf("\n<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n");
    printf("=> the title is : %s\n", title);
    printf("<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n\n");
    printf("=> the task is : %s\n", task);
    printf("=> the priority is : %d\n", priority);
    printf("=> the duration is : %d\n", duration);
    printf("curente condition (starting, done ).");


    */
    printf("=> Option 1: Mark To-Do item as Complete\n");
    printf("=> Option 2: Create a New To-Do item\n");
    printf("=> Option 3: Delete To-Do item\n");
    printf("=> Option 4: go to the prevuse page\n");
    printf("=> Option 5: go to the firs menu\n");


}

void add_new_tasks_to_the_todo_list()
{

    char *task = NULL;
    int priority ;
    int duration;

    task = (char*)malloc(sizeof(char) * 50);
    if (task == NULL)
    {
        printf("Memory allocation failed for task.\n");
        return;
    }


    printf("\n--- create a new to-do list ---\n\n");




    // start geting the tasks of the todo list
    printf("\n-> Please describe your task: ");
    scanf(" %[^\n]", task);

    //fgets(task, 49, stdin);
    //getchar();

    printf("\n-> What is it's level of priority (1,2,3,4) : ");
    scanf("%d", &priority);

    printf("\n-> How long did you anticipate this would take to complete in minutes? : ");
    scanf("%d", &duration);

    printf("=> the task is : %s\n", task);
    printf("=> the priority is : %d\n", priority);
    printf("=> the duration is : %d\n", duration);

}

void create_a_new_todo_list()
{
    char *title = NULL;
    char userResponseToCreateNewTask;


    title = (char*)malloc(sizeof(char) * 50);
    if (title == NULL)
    {
        printf("Memory allocation failed for title.\n");
        return;
    }
    // get the title of the to-do list
    printf("-> Enter a title that reflects your goals for this to-do list : ");
    scanf(" %[^\n]", title);

    //fgets(title, 49, stdin);
    //getchar();


    printf("\n<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n");
    printf("=> the title is : %s\n", title);
    printf("<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n\n");

    do
    {
        printf("-> Do you want to add a New task to your new to do list Y/n ? : ");
        scanf(" %c", &userResponseToCreateNewTask);
        // check if the user want to create a new to-do list or not
        if(userResponseToCreateNewTask == 'Y' || userResponseToCreateNewTask == 'y')
        {

            // call the function that is responsible for creating new to-do listes
            printf("starting creating a new to-do Task...");
            add_new_tasks_to_the_todo_list();
        }
        else if(userResponseToCreateNewTask == 'N' || userResponseToCreateNewTask == 'n')
        {

            // show the existing to do lists.
            printf("No Task list will be created");
            break;
        }
        else
        {
            // handle invalid inputs
            printf("Please enter 'Y' for yes or 'N' for no.");

        }
    }
    while(1);

    free(title); // Free allocated memory for title before returning
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
        create_a_new_todo_list();
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

    return 0;
}
