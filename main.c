#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_DESCRIPTION_LENGTH 100

// Structure to represent a single task
struct TodoTask
{
    char* description;
    int priority;
    int expected_duration; // in minutes
    bool completed;
};

// Structure to represent a to-do list
struct TodoList
{
    char title[50];
    int number_of_tasks;
    struct TodoTask* tasks; // Array of tasks
};

// Function prototypes
int displayMainMenu();
void display_todo_lists(struct TodoList* lists, int num_lists);

// depanage functions

void add_task(struct TodoList* list, char *description, int priority, int duration, bool completed, int numOfTasks)
{
    (list)->tasks = realloc((list)->tasks, (numOfTasks + 1) * sizeof(struct TodoTask));
    if ((list)->tasks == NULL)
    {
        printf("Failed to allocate memory for tasks.\n");
        exit(1);
    }
    list->tasks[numOfTasks].description = description;
    list->tasks[numOfTasks].priority = 1;
    list->tasks[numOfTasks].expected_duration = 11;
    list->tasks[numOfTasks].completed = true;
    // change the number of tasks in the todo list structure
    printf("index of the task is %d",list->number_of_tasks);
    printf("task description of the task %d is %s", numOfTasks, list->tasks[numOfTasks].description);

    list->number_of_tasks++;
}

// Function to print the number of tasks in a TodoList
void print_number_of_tasks(struct TodoList* list)
{
    printf("\nNumber of tasks are: %d\n", list->number_of_tasks);
}

struct TodoList* create_todo_list()
{
    printf("\n//////////////// ** creat a todo list ** ////////////////\n");

    struct TodoList* new_list = (struct TodoList*)malloc(sizeof(struct TodoList));
    printf("Enter a title for your to-do list (max 50 characters): ");
    scanf(" %[^\n]", new_list->title);
    new_list->number_of_tasks = 0;
    new_list->tasks = NULL;
    return new_list;
}

int main()
{
    printf("//////////////// ** main ** ////////////////\n");
    int userOptionChoice;
    char contineu_adding_task;
    int num_todo_lists = 0;
    struct TodoList *todo_lists = NULL;

// Create a new to-do list depanage
//////////////////////////////////////11111 first list
    ///////////////////////////////////////////////////// 11111
    todo_lists = (struct TodoList*) realloc(todo_lists, (num_todo_lists + 1) * sizeof(struct TodoList));
    if (todo_lists == NULL)
    {
        printf("Failed to allocate memory for todo_lists.\n");
        exit(1);
    }

    *(todo_lists+num_todo_lists) = *create_todo_list();

    int numOfTasks = (todo_lists+num_todo_lists)->number_of_tasks;
    add_task((todo_lists+num_todo_lists), "first task", 1, 11, true,numOfTasks);
    print_number_of_tasks((todo_lists+num_todo_lists));

    int nuOfTasks = (todo_lists+num_todo_lists)->number_of_tasks;
    add_task((todo_lists+num_todo_lists), "second task", 1, 11, true,nuOfTasks);
    print_number_of_tasks((todo_lists+num_todo_lists));

    int nOfTasks = (todo_lists+num_todo_lists)->number_of_tasks;
    add_task((todo_lists+num_todo_lists), "third task", 1, 11, true,nOfTasks);
    print_number_of_tasks((todo_lists+num_todo_lists));
    num_todo_lists++;



    ///////////////////////////////////////222
    todo_lists = (struct TodoList*) realloc(todo_lists, (num_todo_lists + 1) * sizeof(struct TodoList));
    if (todo_lists == NULL)
    {
        printf("Failed to allocate memory for todo_lists.\n");
        exit(1);
    }
    *(todo_lists+num_todo_lists) = *create_todo_list();

    add_task((todo_lists+num_todo_lists), "first task 2", 1, 11, true,(todo_lists+num_todo_lists)->number_of_tasks);
    print_number_of_tasks((todo_lists+num_todo_lists));

    add_task((todo_lists+num_todo_lists), "2 task 2", 1, 11, false,(todo_lists+num_todo_lists)->number_of_tasks);
    print_number_of_tasks((todo_lists+num_todo_lists));
    num_todo_lists++;


    // Main loop to handle user interaction
    while (1)
    {
        // Display main menu and get user input
        userOptionChoice = displayMainMenu();

        switch (userOptionChoice)
        {
        case 1:

            // View existing to-do lists
            display_todo_lists(todo_lists, num_todo_lists);
            break;
        /*
              case 2:
                // Create a new to-do list
                todo_lists = realloc(todo_lists, (num_todo_lists + 1) * sizeof(struct TodoList));
                todo_lists[num_todo_lists] = *create_todo_list();

                do {
                  add_new_task_to_list(todo_lists, num_todo_lists);
                  printf("Do you want to add another task (Y/n): ");
                  scanf(" %c", &contineu_adding_task);
                } while(contineu_adding_task == 'Y' || contineu_adding_task == 'y');

                num_todo_lists++;
                break;

              case 3:
                // Exit the program
                freeToDoLists(todo_lists, num_todo_lists);
                printf("Exiting the program.\n");
                exit(0);
                break;
        */
        default:
            printf("Invalid input. Please try again.\n");
        }
    }

    return 0;
}

// Functions that is used by the the functions that run in the main programe

int display_todo_lists_tasks(const struct TodoTask* tasks, int number_of_tasks)
{
    printf("\n//////////////// ** Display To-Do List Tasks ** ////////////////\n");
    printf("Number of tasks: %d\n", number_of_tasks);

    // Iterate through tasks and display them in a user-friendly format
    for (int i = 0; i < number_of_tasks; i++)
    {
        printf("%d. **Task Description:** %s\n", i + 1, (tasks+i)->description);
    }
    return Option_menu();
}

// Separate function to handle user interaction for cleaner separation of concerns
int handle_todo_list_interaction()
{
    int userChoice;


    printf("//////////////// ** handle todo list interaction ** ////////////////");
    // Enhanced menu formatting
    printf("\n** Edit Task Options **\n");
    printf("\033[1;31m");  // Set red text color for emphasis
    printf("=> Option 1: Edit Task Description\n");
    printf("=> Option 2: Edit Task Priority\n");
    printf("=> Option 3: Edit Task Expected Duration\n");
    printf("=> Option 4: Edit Task Completion Status (Done/Not Done)\n");
    printf("=> Option 5: Go Back\n");
    printf("\033[0m");  // Reset text color

    // Input validation loop for error handling
    while (1)
    {
        printf("Enter your choice (1-5): ");
        if (scanf("%d", &userChoice) != 1 || userChoice < 1 || userChoice > 5)
        {
            printf("Invalid choice. Please enter a number between 1 and 5.\n");
            scanf("%*[^\n]"); // Clear invalid input from buffer
        }
        else
        {
            break; // Valid input received
        }
    }

    printf("\n");
    return userChoice;
}

// Function to edit an existing task in a to-do list
void EditTask(struct TodoTask *Tasks,int selectedTaskIndex)
{
    printf("//////////////// ** EditTask ** ////////////////");
    // Display list of tasks and prompt user to choose which task to edit
    int num_lists ;

    printf("\033[1;34m"); // Set text color to blue
    printf("-----------------------------------------------------------------------\n");
    printf("Task Description: %s\n", (Tasks+selectedTaskIndex-1)->description);
    printf("-----------------------------------------------------------------------\n");
    printf("\033[1;32m"); // Set text color to green
    printf("Task Priority:    %d\n", (Tasks+selectedTaskIndex-1)->priority);
    printf("-----------------------------------------------------------------------\n");
    printf("\033[1;33m"); // Set text color to yellow
    printf("Task Duration:    %d minutes\n", (Tasks+selectedTaskIndex-1)->expected_duration);
    printf("-----------------------------------------------------------------------\n");
    printf("\033[0m");
    printf("\n=============================================\n\n");
    // Prompt user for new task details and update the task
    int userChoice = handle_todo_list_interaction();


    char newDescription[100];

    switch (userChoice)
    {
    case 1:
        // Edit task description
        // Assuming description is a char* and you've allocated enough memory for it
// Edit task description
        printf("Task %d current description: %s\n", selectedTaskIndex, (Tasks+selectedTaskIndex-1)->description);
        printf("Enter the new task description (max 100 characters): ");
        scanf(" %[^\n]", newDescription);
        printf("------------------");
// Allocate memory for the new description and copy it
        (Tasks+selectedTaskIndex-1)->description = malloc(strlen(newDescription) + 1); // +1 for the null terminator
        if ((Tasks+selectedTaskIndex-1)->description != NULL)
        {
            strcpy((Tasks+selectedTaskIndex-1)->description, newDescription);
        }
        else
        {
            printf("Failed to allocate memory for the new description.\n");
        }
        break;
    case 2:
        // Edit task priority
        printf("Task %d current priority: %d\n", selectedTaskIndex, (Tasks+selectedTaskIndex-1)->priority);
        printf("Enter the new task priority (1-4): ");
        scanf("%d", &((Tasks+selectedTaskIndex-1)->priority));

        break;
    case 3:
        // Edit task duration
        printf("Task %d current duration: %d minutes\n", selectedTaskIndex, (Tasks+selectedTaskIndex-1)->expected_duration);
        printf("Enter the new task duration (in minutes): ");
        scanf("%d", &((Tasks+selectedTaskIndex-1)->expected_duration));
        break;
    case 4:
        // Edit task completion status
        /*lists[selectedListIndex].tasks[taskIndex - 1].isDone = !lists[selectedListIndex].tasks[taskIndex - 1].isDone;
        printf("Task completion status toggled.\n");*/
        break;
    case 5:
        // No further action needed (go back)
        break;
    default:
        printf("Invalid option selected.\n");
    }
    // Display success message

}


// Function definitions for all the functions used in the program...
int displayMainMenu()
{

    // Display menu options in a clear and concise format
    int userOptionChoice;
    printf("** Main Menu **\n");
    printf("  1. View To-Do Lists\n");
    printf("  2. Create a New To-Do List\n");
    printf("  3. Exit\n\n");

    // Prompt the user for input with clear instructions
    printf("Enter your choice (1-3): ");
    scanf("%d", &userOptionChoice);
    return userOptionChoice;

}


void display_todo_lists(struct TodoList* lists, int num_lists)
{
    printf("\n//////////////// ** Display To-Do Lists ** ////////////////\n");

    if (num_lists == 0)
    {
        printf("There are no to-do lists created yet.\n");
        return;
    }
    while (1)
    {

        // Display list information
        for (int i = 0; i < num_lists; i++)
        {
            printf("\n--------------------------------------\n");
            printf("To-Do List %d: %s\n", i + 1, (lists + i)->title);
            printf("Number of Tasks: %d\n", (lists + i)->number_of_tasks);
            printf("\n--------------------------------------\n");
        }

        // User interaction loop

        int selectedListIndex;

        printf("\n** Actions **\n");
        printf("1. Select a To-Do List (enter list number)\n");
        printf("0. Go Back\n");
        printf("Enter your choice: ");
        scanf("%d", &selectedListIndex);

        if (selectedListIndex < 1 || selectedListIndex > num_lists)
        {
            printf("Invalid selection. Please enter a number between 1 and %d.\n", num_lists);
            scanf("%*[^\n]"); // Clear invalid input from buffer
            break;
        }
        selectedListIndex--;  // Adjust for zero-based indexing
        int userAction = display_todo_lists_tasks(((lists + selectedListIndex)->tasks), (lists + selectedListIndex)->number_of_tasks);

        // Handle the chosen action
        switch (userAction)
        {
        case 1:
            // Call a function to add a new task
            printf("the task is adding ...");
            add_task((lists + selectedListIndex), "new task", 1, 11, true,(lists + selectedListIndex)->number_of_tasks);

            break;
        case 2:
            // Call a function to edit a task
            printf("the task is editing");
            int selectedTaskIndex;
            scanf("%d", &selectedTaskIndex);
            printf("%d", selectedTaskIndex);
            EditTask(((lists + selectedListIndex)->tasks),selectedTaskIndex);

            break;
        case 3:
            // Call a function to delete a task
            // printf("the task is removed");
            delete_the_todo_list_items((lists + selectedListIndex));
            break;
        case 4:
            return;  // Exit the menu
        }


    }
}

int Option_menu()
{
// Prompt user for action
    printf("\n** Task List Actions **\n");
    printf("1. Add a new task\n");
    printf("2. Edit a task\n");
    printf("3. Delete a task\n");
    printf("4. Go Back\n");

    int userAction;
    printf("Enter your choice : ");
    // Ensure valid input
    while (scanf("%d", &userAction) != 1 || userAction < 1 || userAction > 4)
    {
        printf("Invalid choice. Please enter a number between 1 and 4.\n");
        scanf("%*[^\n]"); // Clear invalid input from buffer
        printf("\n** To-Do List Actions **\n");  // Redisplay menu
        printf("1. Add a new task\n");
        printf("2. Edit a task\n");
        printf("3. Delete a task\n");
        printf("4. Go Back\n");
    }

    return userAction;

}



void delete_the_todo_list_items(struct TodoList *ptrTDL) {
    int userChoiseTask;

    printf("=> which task you want to delete from 1 to %d\n", ptrTDL->number_of_tasks);
    scanf("%d", &userChoiseTask);

    // Check if the task index is valid
    if (userChoiseTask < 1 || userChoiseTask > ptrTDL->number_of_tasks) {
        printf("Invalid task index.\n");
        return;
    }

    // Adjust for zero-based indexing
    userChoiseTask--;

    // Shift tasks to the left to remove the selected task
    for (int i = userChoiseTask; i < ptrTDL->number_of_tasks - 1; i++) {
        ptrTDL->tasks[i] = ptrTDL->tasks[i + 1];
    }

    // Reallocate memory to remove the last task
    ptrTDL->tasks = realloc(ptrTDL->tasks, (ptrTDL->number_of_tasks - 1) * sizeof(struct TodoTask));
    if (ptrTDL->tasks == NULL) {
        printf("Failed to reallocate memory.\n");
        return; // Or handle the error as appropriate
    }

    // Decrement the number of tasks
    ptrTDL->number_of_tasks--;
}

