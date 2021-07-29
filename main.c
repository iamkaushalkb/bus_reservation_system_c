/* 
   * Bus Reservation System
   * Project Created by BEI TEAM MASK
   * Members : Samikchhya Karki, Aashiq Kumar Mahato, Kaushal Kumar Bhattarai, Mandeep Mishra 
   * First Sememster Mini Project
   * © Copyright 2021 Bus Reservation System | Made by BEI TEAM MASK
   * Only for educational purposes
*/
// Including Headers
/* Standard Input and Output Header File */
#include <stdio.h>
/* Console Input and Output Header file */
#include <conio.h>
/*
  * Specific Header File which contains declarations 
  * For all of the functions in the Windows API
*/
#include <windows.h>
/*
  * String.h is the header in the C standard library 
  * Which contains macro definitions, constants and declarations of functions 
  * And types used not only for string handling
  * But also various memory handling functions; the name is thus something of a misnomer. 
*/
#include <string.h>
/*
  * The header file stdlib stands for Standard Library. 
  * It has the information of memory allocation/freeing functions.
*/
#include <stdlib.h>
// Declaring Functions
void verify_account();     // Account Verification Function
int authentication_menu(); // Authentication Menu Function
void createaccount();      // Account Registration Function
void login();              // Login Function
int dashboard();           // Dashboard Function
void gotoxy(int, int);     // Gotoxy function
FILE *fp;
struct user u, U;
int choice;
char fname[20], lname[20], uname[20], pss[20], C;
struct user
{
    char pass[20];
    char username[20];
    char fname[20];
    char lname[20];
};
int main()
{
    // For Authentication Menu
    while (1) // While Loop with condition 1 that means always true
    {
        switch (authentication_menu()) // Using Switch Case for Authentication Menu
        {
        case 1:
            createaccount(); // If user selected option is 1 => Calls createaccount function
            break;

        case 2:
            verify_account(); // If user selected option is 2 => Calls verify_account function
            break;

        case 3:
            login(); // If user selected option is 3 => Calls login function
            break;

        case 4:
            exit(0); // If user selected option is 4 => exit the authentication menu
        default:
            printf("Invalid Choice! ");
            break;
        }
    }
    return 0;
}
// Authenticiation Menu
int authentication_menu()
{
    int login_choice; // Choice variable as login_choice
    system("cls");    // Clearing Previous Section
    // List of Choices
    printf("[1] Create Account:  \n");
    printf("[2] Verify Account Details:  \n");
    printf("[3] Login:  \n");
    printf("[4] Exit:  \n");
    printf("Enter your choice :  "); // Asking For User Choices
    scanf("%d", &login_choice);      // Accepting Choice as login_choice variable
    return login_choice;
}
void verify_account()
{
    FILE *fp;
    struct user u;
    system("cls");
    gotoxy(52, 3);
    printf("    Your Details Are..\n\n");
    // Reading from file
    // Set File Path according to your folder destination of your project files
    fp = fopen("D:\\Bus Reservation System\\Files\\account_details.txt", "rb+");
    if (fp == NULL) // Checking Existence of file
    {
        printf("\"File not found\"");
        return 1;
    }
    while (fread(&u, sizeof(struct user), 1, fp)) // Reading data form file
    {
        printf("\n    Name: %s %s \n", u.fname, u.lname);
        printf("\n    Username: %s\n\n    Password = %s \n\n", u.username, u.pass);
    }
    fclose(fp);
    gotoxy(75, 16);
    printf("Press any key to continue...");
    getch();
    system("cls");
}
void createaccount()
{
    struct user U;
    FILE *fp;
    system("cls");
    gotoxy(57, 3);
    puts("<--<<Create Account>>-->");
    printf("\n\n");
    printf("    Enter First Name: ");
    fflush(stdin);
    gets(U.fname);
    printf("\n");
    printf("    Enter Last Name: ");
    gets(U.lname);
    printf("\n");
    printf("    Enter Username: ");
    scanf("%s", U.username);
    printf("\n");
    printf("    Enter Password: ");
    scanf("%s", U.pass);
    // Reading from file
    // Set File Path according to your folder destination of your project files
    fp = fopen("D:\\Bus Reservation System\\Files\\account_details.txt", "wb+");
    if (fp == NULL)
    {
        printf("\nError opened file\n");
        exit(1);
    }
    fwrite(&U, sizeof(struct user), 1, fp);
    fclose(fp);
    system("cls");
    gotoxy(55, 20);
    printf(" Account Created Successfully.");
    gotoxy(75, 25);
    printf("Press any key to continue...");
    getch();
    system("cls");
}
void login()
{
    char uname[20], pss[20];
    FILE *fp;
    struct user u;
    system("cls");
    gotoxy(53, 3);
    printf("<--<<LOGIN TO YOUR ACCOUNT>>->\n\n");
    printf(" Enter Username: ");
    scanf("%s", uname);
    printf("\n");
    printf(" Enter Password: ");
    scanf("%s", pss);
    // Reading from file
    // Set File Path according to your folder destination of your project files
    fp = fopen("D:\\Bus Reservation System\\Files\\account_details.txt", "rb+");
    if (fp == NULL)
    {
        printf("\"File not found\"");
        return 1;
    }
    while (fread(&u, sizeof(struct user), 1, fp))
    {
        if (strcmp(uname, u.username) == 0 && strcmp(pss, u.pass) == 0) // if authentication succed
        {
            printf(" \n Username And Password is Correct.\n");
            printf(" Press any key to continue...");
            getch();
            gotoxy(57, 12);
            system("cls"); // Clearing Previous Section
            printf(" Welcome %s %s \n", u.fname, u.lname);
            // For Dashboard Menu
            while (1) // While Loop with condition 1 that means always true
            {
                switch (dashboard()) // Using Switch Case for Dashboard Menu
                {
                case 1:
                    system("cls"); // Clearing Previous Section
                    printf("\nBooking Under Construction\n"); 
                    break;

                case 2:
                    system("cls"); // Clearing Previous Section
                    printf("\nBoooking Status Under Construction2\n"); 
                    break;

                case 3:
                    system("cls"); // Clearing Previous Section
                    printf("\nDelete Booking Under Construction3\n"); 
                    break;

                case 4:
                    exit(0); // If user selected option is 4 => exit the authentication menu
                default:
                    printf("\nInvalid Choice! \n");
                    break;
                }
            } // Calling dashboard function which will redirect to dashboard
            getch();
        }
        else
        {
            printf("\n Username And Password is Incorrect.\n\n");
            printf(" Press any key to continue...");
            getch();
        }
    }
    fclose(fp);
    system("cls");
}
int dashboard()
{
    int dashboard_choice; // Choice variable as dashboard_choice
    // List of Choices
    printf("\n[1] BOOK BUS:  \n");
    printf("[2] VIEW BOOKING STATUS:  \n");
    printf("[3] DELETE BOOKING:  \n");
    printf("[4] Exit:  \n");
    printf("Enter your choice :  "); // Asking For User Choices
    scanf("%d", &dashboard_choice);  // Accepting Choice as dashboard_choice variable
    return dashboard_choice;
}
void gotoxy(int x, int y)
{
    COORD c;
    c.X = x;
    c.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}