#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student
{
char name[30];
char dob[10];
char fathername[30];
char mothername[30];
char contactnumber[20];
char address[50];
struct student *NEXT;
};

struct student *head = NULL;
struct student *tail = NULL;

void addStudent()
{
    getchar();
    struct student *temp = malloc(sizeof(struct student));

    printf("\nEnter name of student : ");
    getchar(); // Clear any pending newline characters
    fgets(temp->name, sizeof(temp->name), stdin);
    temp->name[strcspn(temp->name, "\n")] = '\0'; // Remove the newline charact

    printf("\nEnter the DOB (DD/MM/YYYY) : ");
    scanf("%s", temp->dob);
    getchar();

    printf("\nEnter the name of Father : ");
    scanf("%[^\n]s", temp->fathername);
    getchar();

    printf("\nEnter name of mother : ");
    scanf("%[^\n]s", temp->mothername);
    getchar();

    printf("\nEnter contact no : ");
    scanf("%s", temp->contactnumber);
    getchar();

    printf("\nEnter address : ");
    scanf("%[^\n]s", temp->address);
    getchar();
    temp->NEXT = NULL;

    if(head == NULL)
    {
    head = temp;
    tail = temp;
    }
    else
    {
    tail->NEXT = temp;
    tail = temp;

    }
}

void displayAllStudents()
{
struct student *temp = head;

if(head == NULL)
    printf("\nNo record: Linked list empty!!");
else
{
    while(temp!=NULL)
    {
        printf("\nName : %s", temp->name);
        printf("\nDOB : %s", temp->dob);
        printf("\nfather name : %s", temp->fathername);
        printf("\nmother name : %s", temp->mothername);
        printf("\nContact no : %s", temp->contactnumber);
        printf("\nAddress : %s", temp->address);
        temp = temp->NEXT;
        if(temp!=NULL) {
            printf("\n----------------");
            printf("\nPress enter key key for next record .. ");
            getchar();
        }
    }
}
}

void deleteAllStudent()
{
if(head == NULL)
    printf("\nLinked List empty..");
else
{
    unsigned long int count = 0;
    struct student *temp = head;
    while(temp != NULL)
    {
        struct student * var = temp->NEXT;
        free(temp);
        temp = var;
        count++;
    }
    printf("\n*** Number of nodes deleted : %ld***\n", count);
}
}

int main()
{
int choice = 1;

while(choice!= 0){
        printf("\n***** Main Menu *****");
        printf("\n\tPress 1 to add student");
        printf("\n\tPress 2 to display student");
        printf("\n\tPress 0 to exit...");
        printf("\nEnter your choice : ");
        scanf("%d ,&choice");

        switch(choice)
        {
            case 1: addStudent(); break;
            case 2: displayAllStudents(); break;
            case 0: deleteAllStudent(); exit(1);
            default : printf("\nInvalid choice.. Please input a valid number");
            getchar();

        }

}
return 0;
}
