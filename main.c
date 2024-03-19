#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char description[20];
    int Priority;
    int expacted_duration;
}todo_task;

// structure for the To-do list that will host the title of it and the tasks on it
typedef struct{
    char title[50];
    int number_of_tasks ;

    todo_tasks todo_task[5];

}todo_list;



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

void display_the_todo_list_item_details()
{

    printf("This function display the to-do list item details and provide options to edit it.");

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
    printf("=> Option 4: go back to the prevuse page\n");
    printf("=> Option 5: go to the firs menu\n");


}

void add_new_tasks_to_the_todo_list()
{
    todo_list todoList[5];

    char *task = NULL;
    int priority ;
    int duration;

    task = (char*)malloc(sizeof(char) * 50);
    if (task == NULL)
    {
        printf("Memory allocation failed for task.\n");
        return;
    }


    printf("\n--- Create a new to-do list ---\n\n");




    // start geting the tasks of the todo list
    printf("\n-> Please describe your task: ");
    scanf(" %[^\n]", task);

    //getchar();
    //fgets(task, 49, stdin);

    printf("\n-> What is it's level of priority (1,2,3,4) : ");
    scanf("%d", &priority);

    printf("\n-> How long did you anticipate this would take to complete in minutes? : ");
    scanf("%d", &duration);

    todo_list.todo_task[0];
    todo_list.todo_tasks[todoList[0].number_of_tasks].Priority = priority;
    todo_list.todo_tasks[todoList[0].number_of_tasks].expacted_duration = duration;

    /*
    printf("=> the task is : %s\n", task);
    printf("=> the priority is : %d\n", priority);
    printf("=> the duration is : %d\n", duration);
    */
    printf("The task was add sucssfuly");

}

void create_a_new_todo_list(FILE* fptr)
{
    todo_list todoList[5];
    char *title = NULL;
    //char filename[64];
    char userResponseToCreateNewTask;
    //FILE *new_todo_list;

    title = (char*)malloc(sizeof(char) * 50);
    if (title == NULL)
    {
        printf("Memory allocation failed for title.\n");
        return;
    }
    // get the title of the to-do list
    printf("-> Enter a title that reflects your goals for this to-do list : ");
    scanf(" %[^\n]", title);

    todoList[0].title = title;
    todoList[0].number_of_tasks= -1;


    //fprintf(fptr, title);
    //fprintf(fptr, "\n");
    //sprintf(filename, "%s.txt", title);


    //new_todo_list = fopen(filename, "a");



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
            todoList[0].number_of_tasks= todoList[0].number_of_tasks +1;
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

    //fclose(new_todo_list);
    free(title); // Free allocated memory for title before returning
}

int main()
{
    FILE *fptr;
    fptr = fopen("to-do_list_titles.txt", "a");
    int userOptionChoice;

    // starting the app
    printf("#### TODO LIST APP ####\n\n");



    //display the start menu
askTheUserToChoose:
    printf("=> Option 1: View To-Do List\n");
    printf("=> Option 2: Create a New To-Do List\n");
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
        create_a_new_todo_list(fptr);
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
    fclose(fptr);
    return 0;
}
