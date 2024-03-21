#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


struct TodoTask
{
    char *description;
    int Priority;
    int expected_duration;
    bool completer;
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



void display_the_todo_lists(struct TodoList *ptrTDL, int number_of_todo_lists)
{
    if(number_of_todo_lists == 0){
        printf("there is no to do list was created please create a todo list than came back and try agine.");
        return;
    }
    char userResponseToCreateNewTask;
    printf("\n");

    printf("=============================================\n");
    printf("** Task Information **\n");
    printf("=============================================\n");



    //display the vlaues
    printf("\nnumber of tasks : %d\n", ptrTDL->number_of_tasks);



    for(int i = 0; i < number_of_todo_lists; i++)
    {
        printf("\033[1;34m"); // Set text color to blue
        printf("-----------------------------------------------------------------------\n");
        printf("ToDo List %d Title: %s\n",i+1, ptrTDL[i].title);
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




}


void display_the_todo_list_items(struct TodoList *ptrTDL)
{
    char userResponseToCreateNewTask;
    printf("\n");

    printf("=============================================\n");
    printf("** Task Information **\n");
    printf("=============================================\n");



    //display the vlaues
    printf("\nnumber of tasks : %d\n", ptrTDL->number_of_tasks);



    for(int i = 0; i < (ptrTDL->number_of_tasks); i++)
    {
        printf("\033[1;34m"); // Set text color to blue
        printf("-----------------------------------------------------------------------\n");
        printf("Task %d Description: %s\n",i+1, ptrTDL->todo_tasky[i].description);
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




}

void display_the_todo_list_item_details(struct TodoList *ptrTDL)
{
    char userResponseToCreateNewTask;
    printf("\n");

    printf("=============================================\n");
    printf("** Task Information **\n");
    printf("=============================================\n");

    //display the vlaues
    printf("\nnumber of tasks : %d\n", ptrTDL->number_of_tasks);

    for(int i = 0; i < ptrTDL->number_of_tasks; i++)
    {
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
}

void edit_the_todo_list_items(struct TodoList *ptrTDL)
{
    int userChoiseTask,userEditChoiseAction;
    display_the_todo_list_items(ptrTDL);

    printf("=> which task you want to edit from 1 to %d\n", ptrTDL->number_of_tasks);
    scanf("%d",&userChoiseTask);

    printf("\033[1;34m"); // Set text color to blue
    printf("-----------------------------------------------------------------------\n");
    printf("Task Description: %s\n", ptrTDL->todo_tasky[userChoiseTask-1].description);
    printf("-----------------------------------------------------------------------\n");
    printf("\033[1;32m"); // Set text color to green
    printf("Task Priority:    %d\n", ptrTDL->todo_tasky[userChoiseTask-1].Priority);
    printf("-----------------------------------------------------------------------\n");
    printf("\033[1;33m"); // Set text color to yellow
    printf("Task Duration:    %d minutes\n", ptrTDL->todo_tasky[userChoiseTask-1].expected_duration);
    printf("-----------------------------------------------------------------------\n");
    printf("\033[0m");
    printf("\n=============================================\n\n");

    printf("\033[1;31m");
    printf("=> Option 1: edit the description of the task\n");
    printf("=> Option 2: edit the prorete\n");
    printf("=> Option 3: edit the time expacted \n");
    printf("=> Option 4: edit it's curent sutation Done/notDone\n");
    printf("=> Option 5: go to back\n");
    printf("\033[0m");
    scanf(" %d",&userEditChoiseAction);
    printf("\n");

    switch(userEditChoiseAction)
    {
    case 1:
        printf("Task %d curent Description: %s\n",userChoiseTask, ptrTDL->todo_tasky[userChoiseTask-1].description);
        printf("input your new description : ");
        scanf(" %[^\n]", ptrTDL->todo_tasky[userChoiseTask-1].description);
        break;
    case 2:
        printf("Task %d curent priority level: %d\n",userChoiseTask, ptrTDL->todo_tasky[userChoiseTask-1].Priority);
        printf("input your new priority level : ");
        scanf("%d", &(ptrTDL->todo_tasky[userChoiseTask-1].Priority));
        break;
    case 3:
        printf("Task %d curent duration: %d\n",userChoiseTask, ptrTDL->todo_tasky[userChoiseTask-1].expected_duration);
        printf("input your new expacted duration : ");
        scanf("%d", &(ptrTDL->todo_tasky[userChoiseTask-1].expected_duration));
        break;
    case 4:
        break;
    case 5:
        break;
    default:
        break;
    }

}

void delete_the_todo_list_items(struct TodoList *ptrTDL)
{
    int userChoiseTask,userChoiseTodoList,userEditChoiseAction;
    display_the_todo_lists(ptrTDL,2);
    printf("=> which todo list you want to join from 1 to %d\n", ptrTDL->number_of_tasks);
    scanf("%d",&userChoiseTodoList);
    userChoiseTodoList = userChoiseTodoList -1;
    display_the_todo_list_items((ptrTDL+userChoiseTodoList));

    printf("=> which task you want to delet from 1 to %d\n", ptrTDL->number_of_tasks);
    scanf("%d",&userChoiseTask);
    ptrTDL->number_of_tasks = ptrTDL->number_of_tasks -1;
    int lastIndex = ptrTDL->number_of_tasks ;

    ptrTDL->todo_tasky[userChoiseTask-1] = ptrTDL->todo_tasky[lastIndex] ;
    ptrTDL->todo_tasky = realloc(ptrTDL->todo_tasky,lastIndex * sizeof(struct TodoTask));
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
    printf("** %s **\n",ptrTDL );
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


}

struct TodoList *create_a_new_todo_list(struct TodoList *ptrTDL,int number_of_todo_lists)
{
    printf("\n");


    // allocating memory for number_of_todo_lists
    ptrTDL = realloc(ptrTDL,number_of_todo_lists * sizeof(struct TodoList));


    printf("=============================================\n");
    printf("** Create a New To-Do List **\n");
    printf("=============================================\n\n");




    printf("Enter a title for your to-do list (max 50 characters): ");
    scanf(" %[^\n]", ptrTDL->title);

     printf("\n=============================================\n");
    printf("** %s **\n",ptrTDL[0].title );
    printf("=============================================\n\n");

    printf("\033[1;32m"); // Set text color to green

    printf("\n\n**  Success!  **\n");
    printf("Your To-do List has been created successfully.\n");
    printf("List Name: %s\n",ptrTDL->title);
    printf("Number of Items: 0 (Start adding tasks!)\n\n",ptrTDL->number_of_tasks);

    printf("\033[0m");
    return ptrTDL;
}

int main()
{
    system("cls");

    int userOptionChoice;
    int number_of_todo_lists = 0;

    struct TodoList *ptrTDL;

    // allocating memory for number_of_todo_lists
    ptrTDL = (struct TodoList*) malloc(number_of_todo_lists * sizeof(struct TodoList));



    //display the start menu

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

askTheUserToChoose:



    // Display menu options in a clear and concise format
    printf("** Main Menu **\n");
    printf("  1. View To-Do Lists\n");
    printf("  2. Create a New To-Do List\n");
    printf("  3. Exit\n\n");

    // Prompt the user for input with clear instructions
    printf("Enter your choice (1-3): ");
    scanf("%d", &userOptionChoice);




    switch(userOptionChoice)
    {
    case 1:

        edit_the_todo_list_items(&ptrTDL);
        //delete_the_todo_list_items(&ptrTDL);
        goto askTheUserToChoose;
        break;
    case 2:
        number_of_todo_lists++;

        ptrTDL = create_a_new_todo_list(ptrTDL,number_of_todo_lists);

        char userResponseToCreateNewTask;

        while(1)
        {
            printf("Do you want to add a new task to your list (Y/N) mean? ");
            scanf(" %c", &userResponseToCreateNewTask);
            // check if the user want to create a new to-do list or not
            if(userResponseToCreateNewTask == 'Y' || userResponseToCreateNewTask == 'y')
            {

                // call the function that is responsible for creating new to-do listes
                printf("Great! Let's add a new task...\n");
                ptrTDL->number_of_tasks = 0;
                add_new_tasks_to_the_todo_list(&ptrTDL);

            }
            else if(userResponseToCreateNewTask == 'N' || userResponseToCreateNewTask == 'n')
            {

                // exite the to-do list show the existing to do lists.
                printf("Okay, exiting the to-do list creator.\n");
                goto askTheUserToChoose;
                break;

            }
            else
            {

                // handle invalid inputs
                printf("Please enter 'Y' for yes or 'N' for no.");

            }
        }

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
