#include <stdio.h>
#include <stdlib.h>
#include <string.h>



struct TodoTask
{
    char *description;
    int Priority;
    int expected_duration;
};

struct TodoList
{
    char title[50];
    int number_of_tasks;
    struct TodoTask *todo_tasky;
};

int minites_To_hours(int min)
{
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

void display_the_todo_list_item_details(struct TodoList *ptrTDL)
{
    char userResponseToCreateNewTask;
    printf("\n");

    printf("=============================================\n");
    printf("** Task Information **\n");
    printf("=============================================\n");

    /*
    printf("\n<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n");
    printf("=> the title is : %s\n", title);
    printf("<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n\n");
    printf("=> the task is : %s\n", task);
    printf("=> the priority is : %d\n", priority);
    printf("=> the duration is : %d\n", duration);
    printf("curente condition (starting, done ).");


    */

    //display the vlaues
    printf("\nnumber of tasks : %d\n", ptrTDL->number_of_tasks);



for(int i = 0; i < (ptrTDL->number_of_tasks); i++){
        printf("\033[1;34m"); // Set text color to blue
    printf("-----------------------------------------------------------------------\n");
    printf("Task Description: %s\n", ptrTDL->todo_tasky[i].description);
    printf("-----------------------------------------------------------------------\n");
    printf("\033[1;32m"); // Set text color to green
    printf("Task Priority:    %d\n", ptrTDL->todo_tasky[i].Priority);
    printf("-----------------------------------------------------------------------\n");
    printf("\033[1;33m"); // Set text color to yellow
    printf("Task Duration:    %d minutes\n", ptrTDL->todo_tasky[i].expected_duration);
    printf("-----------------------------------------------------------------------\n");
    printf("\033[0m");
    printf("\n=============================================\n\n");

}



    printf("\033[1;31m");
    printf("=> Option 1: Mark To-Do item as Complete\n");
    printf("=> Option 2: Create a New To-Do item\n");
    printf("=> Option 3: Delete To-Do item\n");
    printf("=> Option 4: go back to the prevuse page\n");
    printf("=> Option 5: go to the firs menu\n");
    printf("\033[0m");
    printf("\n");

    printf("Do you want to add a new task to your list (Y/N)? ");
        scanf(" %c", &userResponseToCreateNewTask);
        // check if the user want to create a new to-do list or not
        if(userResponseToCreateNewTask == 'Y' || userResponseToCreateNewTask == 'y')
        {

            // call the function that is responsible for creating new to-do listes
            printf("Great! Let's add a new task...\n");
            add_new_tasks_to_the_todo_list(ptrTDL);
        }


}

void add_new_tasks_to_the_todo_list(struct TodoList *ptrTDL)
{
    system("cls");
    // printf("\033[H\033[J");
    int index = ptrTDL->number_of_tasks;
    ptrTDL->number_of_tasks= ptrTDL->number_of_tasks + 1;

    printf("new task num of tasks : %d\n",ptrTDL->number_of_tasks);


    ptrTDL->todo_tasky = realloc(ptrTDL->todo_tasky, (ptrTDL->number_of_tasks) * sizeof(struct TodoTask));
    if (ptrTDL->todo_tasky == NULL)
    {
        printf("Memory allocation failed.\n");
        return 1; // Or handle the error appropriately
    }

    printf("\n=============================================\n");
    printf("** %s **\n", ptrTDL->title);
    printf("=============================================\n\n");





    printf("\n-> Please describe your task (max 100 characters) : ");

    ptrTDL->todo_tasky[index].description = malloc(101); // Allocate memory for the description
    if (ptrTDL->todo_tasky->description == NULL)
    {
        printf("Memory allocation failed.\n");
        return;
    }
    scanf(" %[^\n]", ptrTDL->todo_tasky[index].description);

    printf("\nSelect the priority level of this task:\n");
    printf("  1. Urgent\n");
    printf("  2. High\n");
    printf("  3. Medium\n");
    printf("  4. Low\n");
    printf("Enter your choice (1-4): ");
    scanf("%d", &(ptrTDL->todo_tasky[index].Priority));

    printf("\n-> How long do you anticipate this task will take to complete (in minutes)?: ");
    scanf("%d", &(ptrTDL->todo_tasky[index].expected_duration));

    printf("\033[1;32m"); // Set text color to green
    printf("\n\n[SUCCESS]: The task has been added successfully.\n\n");
    printf("\033[0m");


    display_the_todo_list_item_details((ptrTDL));

}
void create_a_new_todo_list(int number_of_todo_lists)
{
    printf("\n");
    char userResponseToCreateNewTask;
    struct TodoList *ptrTDL;

    // allocating memory for number_of_todo_lists
    ptrTDL = (struct TodoList*) malloc(number_of_todo_lists * sizeof(struct TodoList));


    printf("=============================================\n");
    printf("** Create a New To-Do List **\n");
    printf("=============================================\n\n");

    /*
        char *title = NULL;
        //char filename[64];

        //FILE *new_todo_list;

        title = (char*)malloc(sizeof(char) * 50);
        if (title == NULL)
        {
            printf("Memory allocation failed for <title.\n");
            return;
        }

        // get the title of the to-do list
        printf("-> Enter a title that reflects your goals for this to-do list : ");
        scanf(" %[^\n]", title);

        /*  todoList[0].title = title;
          todoList[0].number_of_tasks= -1;*/


    //fprintf(fptr, title);
    //fprintf(fptr, "\n");
    //sprintf(filename, "%s.txt", title);


    //new_todo_list = fopen(filename, "a");
    printf("Enter a title for your to-do list (max 50 characters): ");
    scanf(" %[^\n]", ptrTDL->title);



    /*
    printf("\n<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n");
    printf("=> the title is : %s\n", ptrTDL->title);
    printf("<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n\n");
    */
    printf("\033[1;32m"); // Set text color to green

    printf("\n\n**  Success!  **\n");
    printf("Your To-do List has been created successfully.\n");
    printf("List Name: %s\n",ptrTDL->title);
    printf("Number of Items: 0 (Start adding tasks!)\n\n",ptrTDL->number_of_tasks);

    printf("\033[0m");



        printf("Do you want to add a new task to your list (Y/N)? ");
        scanf(" %c", &userResponseToCreateNewTask);
        // check if the user want to create a new to-do list or not
        if(userResponseToCreateNewTask == 'Y' || userResponseToCreateNewTask == 'y')
        {

            // call the function that is responsible for creating new to-do listes
            printf("Great! Let's add a new task...\n");
            ptrTDL->number_of_tasks = 0;
            add_new_tasks_to_the_todo_list(ptrTDL);
        }
        else if(userResponseToCreateNewTask == 'N' || userResponseToCreateNewTask == 'n')
        {

            // exite the to-do list show the existing to do lists.
            printf("Okay, exiting the to-do list creator.\n");

        }
        else
        {
            // handle invalid inputs
            printf("Please enter 'Y' for yes or 'N' for no.");

        }


    //fclose(new_todo_list);
    //free(title); // Free allocated memory for title before returning

}

int main()
{
    //FILE *fptr;
    //fptr = fopen("to-do_list_titles.txt", "a");
    int userOptionChoice;
    int number_of_todo_lists = 0;

    // starting the app f
    // Option 1: Welcome message

    printf("\033[48;5;232m");
    printf("  __      __       .__                               \n");
    printf(" /  \\    /  \\ ____ |  |   ____  ____   _____   ____  \n");
    printf(" \\   \\/\\/   // __ \\|  | _/ ___\\/  _ \\ /     \\_/ __ \\ \n");
    printf("  \\        /\\  ___/|  |_\\  \\__(  <_> )  Y Y  \\  ___/ \n");
    printf("   \\__/\\  /  \\___  >____/\\___  >____/|__|_|  /\\___  >\n");
    printf("        \\/       \\/          \\/            \\/     \\/ \n");


    printf("\n=============================================\n");
    printf("**  To-Do List App  **\n");
    printf("=============================================\n\n");



    //display the start menu
askTheUserToChoose:
    /*
    printf("=> Option 1: View To-Do List\n");
    printf("=> Option 2: Create a New To-Do List\n");
    printf("=> Option 3: Exit\n");
    */


    // Display menu options in a clear and concise format
    printf("** Main Menu **\n");
    printf("  1. View To-Do List\n");
    printf("  2. Create a New To-Do List\n");
    printf("  3. Exit\n\n");

    // Prompt the user for input with clear instructions
    printf("Enter your choice (1-3): ");
    scanf("%d", &userOptionChoice);

    /* after choosing the first option

    printf("- Option 3: Mark To-Do List Complete\n");
    printf("- Option 4: Delete To-Do List\n");

    */
    /*

    printf("\n-> What would you like to do next? : ");
    scanf("%d", &userOptionChoice);

    */

    switch(userOptionChoice)
    {
    case 1:
        display_the_todo_lists();
        break;
    case 2:
        number_of_todo_lists++;
        create_a_new_todo_list(number_of_todo_lists);
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
    //fclose(fptr);
    return 0;
}
