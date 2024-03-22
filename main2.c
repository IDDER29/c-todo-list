#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


typedef struct
{
    char *description;
    int Priority;
    int expected_duration;
    bool completer;
}TodoTask;

typedef struct
{
    char title[50];
    int number_of_tasks;
    TodoTask* todo_tasky;
}TodoList;

int display_the_todo_lists( TodoList *ptrTDL, int number_of_todo_lists)
{
    int choice;
    if(number_of_todo_lists == 0)
    {
        printf("there is no to do list was created please create a todo list than came back and try agine.");
        return 0;
    }
    char userResponseToCreateNewTask;
    printf("\n");

    printf("=============================================\n");
    printf("** Task Information **\n");
    printf("=============================================\n");

    //display the vlaues

    for(int i = 0; i < number_of_todo_lists; i++)
    {
        printf("\033[1;34m"); // Set text color to blue
        printf("-----------------------------------------------------------------------\n");
        printf("ToDo List %d Title: %s\n",i+1, ptrTDL[i].title);
        printf("\033[0m");
        printf("\nnumber of tasks : %d\n", ptrTDL[i].number_of_tasks);
        printf("\n==========================*********===================\n\n");
        for(int j=0;j<ptrTDL[i].number_of_tasks;j++)
        {
            printf("\n%s",ptrTDL[i].todo_tasky[j].description);
        }

    }

            do{
                        printf("\033[1;31m");
                        printf("=> Option 1: Mark Task as Completed\n");
                        printf("=> Option 2: Add a New To-Do Task\n");
                        printf("=> Option 3: Delete To-Do List\n");
                        printf("=> Option 4: Delete Task from Todo List\n");
                        printf("=> Option 5: Modify Todo List\n");
                        printf("=> Option 6: Modify Task\n");
                        printf("=> Option 7: Display Filtred Priorities\n");
                        printf("\033[0m");
                        printf("\n");
                        scanf("%d",&choice);

            }while(choice<1 || choice >7);

return choice;
}

void add_new_tasks_to_the_todo_list( TodoList *ptrTDL, TodoTask *ptrTDTDK,int num_of_todolist)
{
    //system("cls");
    // printf("\033[H\033[J");
    int index = ptrTDL->number_of_tasks;
    printf("***********\n****%d\n",index);
    printf("new task num of tasks : %d\n",ptrTDL->number_of_tasks+1);

    printf("\n=============================================\n");
    printf("** %s ok**\n",ptrTDL->title );
    printf("=============================================\n\n");

    printf("\n-> Please describe your task (max 100 characters) : ");
    ptrTDTDK[index].description = malloc(101); // Allocate memory for the description
    printf("\n\n************************ \n");
    if (ptrTDTDK[index].description == NULL)
    {
        printf("Memory allocation failed of description.\n");
        return;
    }
    printf("\n\n************************ \n");
    scanf(" %[^\n]", ptrTDTDK[index].description);

    printf("\nSelect the priority level of this task:\n");
    printf("  1. Urgent\n");
    printf("  2. High\n");
    printf("  3. Medium\n");
    printf("  4. Low\n");
    printf("Enter your choice (1-4): ");
    scanf("%d", &ptrTDTDK[index].Priority);

    printf("\n-> How long do you anticipate this task will take to complete (in minutes)?: ");
    scanf("%d", &(ptrTDTDK[index].expected_duration));

    printf("\033[1;32m"); // Set text color to green
    printf("\n\n[SUCCESS]: The task has been added successfully.\n\n");
    printf("\033[0m");
    ptrTDL[num_of_todolist].number_of_tasks++;

}

 TodoList *create_a_new_todo_list( TodoList *ptrTDL,int number_of_todo_lists)
{
    printf("\n");


    // allocating memory for number_of_todo_lists
    ptrTDL = realloc(ptrTDL,number_of_todo_lists * sizeof(TodoList));

    ptrTDL[number_of_todo_lists-1].number_of_tasks = 0;

    printf("=============================================\n");
    printf("** Create a New To-Do List **\n");
    printf("=============================================\n\n");



    printf("Enter a title for your to-do list (max 50 characters): ");
    scanf(" %[^\n]", ptrTDL[number_of_todo_lists-1].title);


    printf("\033[1;32m"); // Set text color to green

    printf("\n\n**  Success!  **\n");
    printf("Your To-do List has been created successfully.\n");
    printf("List Name: %s\n",ptrTDL[number_of_todo_lists-1].title);
    printf("Number of Items: %d (Start adding tasks!)\n\n",ptrTDL[number_of_todo_lists-1].number_of_tasks);

    printf("\033[0m");

    return ptrTDL;
}

int main()
{
    system("cls");

    int userOptionChoice;
    int number_of_todo_lists = 0;
    int num_of_todolist;

     TodoList *ptrTDL=NULL;

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

        printf("\n********Nmb%d\n",number_of_todo_lists);
        display_the_todo_lists(ptrTDL,number_of_todo_lists);
        goto askTheUserToChoose;
        break;
    case 2:
        ptrTDL = create_a_new_todo_list(ptrTDL,number_of_todo_lists+1);
        number_of_todo_lists++;

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

                        if(ptrTDL->number_of_tasks == 0)
                        {
                            ptrTDL->todo_tasky =  (TodoTask*)  malloc(sizeof(TodoTask));

                            if(ptrTDL->todo_tasky==NULL)
                            {
                                printf("MALLOC****dzzdzoidjzedzjhzdjd*****%d",ptrTDL->number_of_tasks+1);
                                return 1;
                            }
                        }
                        else{
                                ptrTDL->todo_tasky =  (TodoTask*)  realloc(ptrTDL->todo_tasky,(ptrTDL->number_of_tasks+1)*sizeof(TodoTask));
                        if(ptrTDL->todo_tasky==NULL)
                        {
                            printf("REALLOC****dzzdzoidjzedzjhzdjd*****%d",ptrTDL->number_of_tasks+1);
                            return 1;
                        }

                        }


                add_new_tasks_to_the_todo_list(ptrTDL,ptrTDL->todo_tasky,number_of_todo_lists-1);


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
