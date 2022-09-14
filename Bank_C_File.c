#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include "STD_TYPES.h"
#include <conio.h>
#include <windows.h>

#include "Bank_H_File.h"

AccountInfo_t Accounts[NUMBER_OF_CUSTOMERS];
static u32 i = 0;

/////////////////// System Functions ///////////////////////////////

void Wellcom()
{

    system("color 6");
    CLEAR_SCREEN();
    SetConsoleTitle(" Bank System | DIU");
    printf(" \n\n\n\n\n\t\t\t\t\t***************************************************");
    printf("\n\t\t\t\t\t*                                                 *");
    printf("\n\t\t\t\t\t*             Wellcom To Bank System              *");
    printf("\n\t\t\t\t\t*                                                 *");
    printf("\n\t\t\t\t\t***************************************************");
    printf("\n\n\n\n\n\t\t\t\t\tPress any key to continue...... ");
    getch();
}
void exitTheSystem(void)
{

    CLEAR_SCREEN();
    printf(" \n\n\n\n\n\t\t\t\t\t***************************************************");
    printf("\n\t\t\t\t\t*                                                 *");
    printf("\n\t\t\t\t\t*         Thanks For Using Bank System            *");
    printf("\n\t\t\t\t\t*                                                 *");
    printf("\n\t\t\t\t\t***************************************************");

    delay(5000);
    CLEAR_SCREEN();
    exit(0);
}
void startTheSystem(void)
{
    CLEAR_SCREEN();
    u32 systemChoice;

    printf("Choose from these options:\n\n\
           1-for Administrator mode.\n\
           2-for Client mode.\n\
           3-for Exit.\n\n");
    printf("Enter your choice: ");
    scanf("%d", &systemChoice);
    switch (systemChoice)
    {
    case 1:
        CLEAR_SCREEN();
        Admin_Login();
        break;
    case 2:
        CLEAR_SCREEN();
        Client_Mode();
        break;
    case 3:
        CLEAR_SCREEN();
        exitTheSystem();
        break;
    default:
        CLEAR_SCREEN();
        printf(" \n\n\n\n\n\t\t\t\t\t     * * * * * * * * * * * * * * * * * * * * ");
        printf("\n\n\t\t\t\t\t     *      You entered invalid option     *");
        printf("\n\n\t\t\t\t\t     * * * * * * * * * * * * * * * * * * * *");

        delay(3000);
        CLEAR_SCREEN();
        startTheSystem();

        break;
    }
}

///////////////////Common Functions ///////////////////////////////

u8 Check_Account(u32 bankAccountID)
{

    u8 exist = 0;
    for (u32 index = 1; index <= i; index++)
    {
        if (Accounts[index].BankAccount_ID == bankAccountID)
        {
            exist = 1;
            break;
        }
    }
    return exist;
}
void Make_Transaction(u32 SenderID)
{
    CLEAR_SCREEN();
    u32 receiverID, money;
    u8 ID_exists2;

    printf("please Enter the Bank Account ID you want to transfer the money to: ");
    scanf("%d", &receiverID);
    ID_exists2 = Check_Account(receiverID);

    if (ID_exists2)
    {
        if (Accounts[receiverID].accountStatus == ACTIVE)
        {
            printf("please Enter amount of money: ");
            scanf("%d", &money);
            if (Accounts[SenderID].balance >= money)
            {

                Accounts[receiverID].balance += money;
                Accounts[SenderID].balance -= money;

                CLEAR_SCREEN();

                printf(" \n\n\n\n\n\t\t\t\t\t     * * * * * * * * * * * * * * * * * * * * * * * * * * * * ");
                printf("\n\n\t\t\t\t\t     *      Transaction process is Done Successfully!      *");
                printf("\n\n\t\t\t\t\t     * * * * * * * * * * * * * * * * * * * * * * * * * * * *");

                delay(3000);
                CLEAR_SCREEN();
            }
            else
            {
                CLEAR_SCREEN();
                printf(" \n\n\n\n\n\t\t\t\t\t     * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *");
                printf("\n\n\t\t\t\t\t     *      Operation failed because there is no sufficient money!       *");
                printf("\n\n\t\t\t\t\t     * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *");
                delay(3000);
                CLEAR_SCREEN();
            }
        }
        else
        {
            CLEAR_SCREEN();
            printf(" \n\n\n\n\n\t\t\t\t\t     * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *");
            printf("\n\n\t\t\t\t\t     *      Operation failed because the user isn't an active user!      *");
            printf("\n\n\t\t\t\t\t     * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *");
            delay(3000);
            CLEAR_SCREEN();
        }
    }
    else
    {
        printf(" \n\n\n\n\n\t\t\t\t\t     * * * * * * * * * * * * * * * * * * * * ");
        printf("\n\n\t\t\t\t\t     *      This ID doesn't exist...       *");
        printf("\n\n\t\t\t\t\t     * * * * * * * * * * * * * * * * * * * *");
        delay(3000);
        CLEAR_SCREEN();
    }
}
void Get_Cash(u32 userID)
{

    u32 Getcash;
    CLEAR_SCREEN();
    // Please enter the withdrawal amount
    printf("Enter the withdrawal amount, please : ");
    scanf("%d", &Getcash);
    if (Accounts[userID].balance > Getcash)
    {
        Accounts[userID].balance -= Getcash;

        CLEAR_SCREEN();
        printf(" \n\n\n\n\n\t\t\t\t\t* * * * * * * * * * * * * * * * * * * * * * * * * * * * ");
        printf("\n\n\t\t\t\t\t*       Getting the cash is Done Successfully!        *");
        printf("\n\n\t\t\t\t\t* * * * * * * * * * * * * * * * * * * * * * * * * * * *");

        delay(3000);
    }
    else
    {
        CLEAR_SCREEN();
        printf(" \n\n\n\n\n\t\t\t\t\t* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *");
        printf("\n\n\t\t\t\t\t*    Operation failed because there is no sufficient money!     *");
        printf("\n\n\t\t\t\t\t* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *");
        delay(4000);
    }
    CLEAR_SCREEN();
}
void Deposit_InAccount(u32 userID)
{
    CLEAR_SCREEN();
    u32 depositCash;
    printf("To deposit money into this account, please enter the desired amount in cash : ");
    scanf("%d", &depositCash);
    Accounts[userID].balance += depositCash;
    CLEAR_SCREEN();
    printf(" \n\n\n\n\n\t\t\t\t\t* * * * * * * * * * * * * * * * * * * * * * * * * * * * ");
    printf("\n\n\t\t\t\t\t*       Deposit In Account is Done Successfully!      *");
    printf("\n\n\t\t\t\t\t* * * * * * * * * * * * * * * * * * * * * * * * * * * *");

    delay(3000);
    CLEAR_SCREEN();
}

///////////////////// Admin Functions /////////////////////////////

void Admin_Login()
{
    printf("*********************************************************************                          \n");
    printf("*                      Admin Mode                                   *                          \n");
    printf("*********************************************************************                          \n");

    u8 adminUsername[20] = {0}, choice;
    printf("Enter username please: ");
    scanf("%s", adminUsername);

    printf("\nEnter password please: ");
    // To make Password Invisible and predetermined with (ADMIN_PASSWORD_LENGTH) digits
    u8 adminPassword[5] = {0};
    for (u8 index = 0; index < ADMIN_PASSWORD_LENGTH; index++)
    {
        adminPassword[index] = getch();
        printf("*");
    }
    adminPassword[4] = '\0';
    if ((!strcmp(adminUsername, ADMIN_USERNAME)) && (!strcmp(adminPassword, ADMIN_PASSWORD)))
    {
        CLEAR_SCREEN();
        adminMode();
    }
    else
    {
        CLEAR_SCREEN();
        printf(" \n\n\n\n\n\t\t\t\t\t* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *");
        printf("\n\t\t\t\t\t*      You Enter invalid username or password, please try again...      *");
        printf("\n\t\t\t\t\t* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *");
        printf("\n\nDo you want to continue?\n1-for Yes.\n2-for No.\n\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            CLEAR_SCREEN();
            Admin_Login();
            break;
        case 2:
        default:
            CLEAR_SCREEN();
            startTheSystem();
            break;
        }
    }
}

void adminMode(void)
{
    u8 choice1, choice2;
    printf("*********************************************************************                          \n");
    printf("*                      Admin Mode                                   *                          \n");
    printf("*********************************************************************                          \n");

    printf("Choose from these options:\n\n\
           1-Create New Account.\n\
           2-Open Existing Account.\n\
           3-Show Accounts Info.\n\
           4-Main Menu.\n\
           5-Exit .\n\n");
    printf("Enter your choice: ");
    scanf("%d", &choice1);

    switch (choice1)
    {
    case 1:
        CLEAR_SCREEN();
        createNewAccount();
        break;
    case 2:
        CLEAR_SCREEN();
        openExistingAccount();
        break;
    case 3:
        CLEAR_SCREEN();
        Show_Accounts_Info();
        break;
    case 4:
        CLEAR_SCREEN();
        startTheSystem();
        break;
    case 5:
        CLEAR_SCREEN();
        exitTheSystem();
        break;
    default:
        CLEAR_SCREEN();
        printf(" \n\n\n\n\n\t\t\t\t\t     * * * * * * * * * * * * * * * * * * * * ");
        printf("\n\n\t\t\t\t\t     *      You entered invalid option     *");
        printf("\n\n\t\t\t\t\t     * * * * * * * * * * * * * * * * * * * *");

        printf("\n\nDo you want to continue?\n1-for Yes.\n2-for No.\n\nEnter your choice: ");
        scanf("%d", &choice2);
        switch (choice2)
        {
        case 1:
            CLEAR_SCREEN();
            adminMode();
            break;

        default:
            CLEAR_SCREEN();
            startTheSystem();
            break;
        }
        break;
    }
}

void createNewAccount(void)
{
    i++;
    printf("*********************************************************************                          \n");
    printf("*                      Admin Mode                                   *                          \n");
    printf("*********************************************************************                          \n");

    printf("\nEnter the full name please:  ");
    scanf("%s", &Accounts[i].fullName);
    fflush(stdin);
    printf("Enter the full address please:  ");
    scanf("%s", &Accounts[i].fullAddress);
    fflush(stdin);
    printf("Enter the national ID please:  ");
    scanf("%lf", &Accounts[i].national_ID);
    fflush(stdin);
    printf("Enter the age please:  ");
    scanf("%d", &Accounts[i].age);
    fflush(stdin);
    if (Accounts[i].age < 21)
    {
        Accounts[i].guardian = 1;
        printf("Enter the guardian national ID please:  ");
        scanf("%lf", &Accounts[i].guardianNational_ID);
        fflush(stdin);
    }
    else
    {
        Accounts[i].guardian = 0;
    }
    printf("Enter the balance please:  ");
    scanf("%d", &Accounts[i].balance);
    // fflush(stdin);

    Accounts[i].accountStatus = ACTIVE;
    Accounts[i].password = random_(MIN_RANDOM_PASSWORD, MAX_RANDOM_PASSWORD);
    Accounts[i].BankAccount_ID = i;

    CLEAR_SCREEN();

    printf(" \n\n\n\t\t     * * * * * * * * * * * * * * * * * * * * * * * * * * * * ");
    printf("\n\t\t     *      Registration process is Done Successfully!     *");
    printf("\n\t\t     * * * * * * * * * * * * * * * * * * * * * * * * * * * *");

    delay(3000);
    CLEAR_SCREEN();
    adminMode();
}



void openExistingAccount(void)
{
    CLEAR_SCREEN();
    printf("*********************************************************************                          \n");
    printf("*                      Admin Mode                                   *                          \n");
    printf("*********************************************************************                          \n");

    u32 Clinet_Account_ID;

    u8 ID_exists1 = 0, choice = 0;
    printf("Enter client bank account ID please: ");
    scanf("%d", &Clinet_Account_ID);
    ID_exists1 = Check_Account(Clinet_Account_ID);
    if (ID_exists1)
    {
        CLEAR_SCREEN();
        if (Accounts[Clinet_Account_ID].accountStatus == ACTIVE)
        {
            Opration_ON_Client(Clinet_Account_ID);
        }
        else
        {
            printf("*********************************************************************                          \n");
            printf("*               This Account State is INACTIVE                      *                          \n");
            printf("*********************************************************************                          \n");
            printf("\nDo you want to change Accout State ?\n1-for Yes.\n2-for No.\n\nEnter your choice:: ");
            scanf("%d", &choice);
            switch (choice)
            {
            case 1:
                CLEAR_SCREEN();
                Admin_changeAccountStatus(Clinet_Account_ID);

                openExistingAccount();
                break;
            case 2:
                CLEAR_SCREEN();

                adminMode();
                break;
            default:
                CLEAR_SCREEN();

                printf(" \n\n\n\n\n\t\t\t\t\t     * * * * * * * * * * * * * * * * * * * * ");
                printf("\n\n\t\t\t\t\t     *      You entered invalid option      *");
                printf("\n\n\t\t\t\t\t     * * * * * * * * * * * * * * * * * * * * ");
                delay(3000);

                CLEAR_SCREEN();
                adminMode();

                break;
            }
        }
    }
    else
    {
        CLEAR_SCREEN();
        printf(" \n\n\n\n\n\t\t\t\t\t     * * * * * * * * * * * * * * * * * * * * ");
        printf("\n\n\t\t\t\t\t     *        This ID doesn't exist         *");
        printf("\n\n\t\t\t\t\t     * * * * * * * * * * * * * * * * * * * * ");
        delay(3000);
        CLEAR_SCREEN();
        adminMode();
    }
}
void Admin_changeAccountStatus(u32 userID)
{
    u8 ChoiceStatus;

    CLEAR_SCREEN();
    printf("Choose from these options to enter the bank account status:\n\n\
            1- Set Account to Active State.\n\
            2- Set Account to Restricted State.\n\
            3- Set Account to Closed. \n\n");

    printf("Enter your choice: ");
    scanf("%d", &ChoiceStatus);
    switch (ChoiceStatus)
    {
    case 1:
        Accounts[userID].accountStatus = ACTIVE;
        CLEAR_SCREEN();

        printf(" \n\n\n\n\n\t\t\t\t\t     * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *");
        printf("\n\n\t\t\t\t\t     *      Changing the account status is Done Successfully!      *");
        printf("\n\n\t\t\t\t\t     * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *");
        delay(3000);
        break;
    case 2:
        Accounts[userID].accountStatus = RESTRICTED;
        CLEAR_SCREEN();

        printf(" \n\n\n\n\n\t\t\t\t\t     * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *");
        printf("\n\n\t\t\t\t\t     *      Changing the account status is Done Successfully!      *");
        printf("\n\n\t\t\t\t\t     * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *");
        delay(3000);
        break;
    case 3:
        Accounts[userID].accountStatus = CLOSED;
        CLEAR_SCREEN();

        printf(" \n\n\n\n\n\t\t\t\t\t     * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *");
        printf("\n\n\t\t\t\t\t     *      Changing the account status is Done Successfully!      *");
        printf("\n\n\t\t\t\t\t     * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *");
        delay(3000);
        break;

    default:
        printf(" \n\n\n\n\n\t\t\t\t\t     * * * * * * * * * * * * * * * * * * * * * * * * * * * * ");
        printf("\n\n\t\t\t\t\t     *        You entered invalid account status...        *");
        printf("\n\n\t\t\t\t\t     * * * * * * * * * * * * * * * * * * * * * * * * * * * *");
        delay(3000);
        break;
    }

    CLEAR_SCREEN();
}
void Show_Accounts_Info(void)
{

    if (i > 0)
    {

        for (u32 index = 1; index <= i; index++)
        {
            printf("BankAccount_ID =     %d\n", Accounts[index].BankAccount_ID);
            printf("fullName       =     %s\n", Accounts[index].fullName);
            printf("fullAddress    =     %s\n", Accounts[index].fullAddress);
            printf("Age            =     %d\n", Accounts[index].age);
            printf("accountStatus  =     %d\n", Accounts[index].accountStatus);
            printf("Balance        =     %d\n", Accounts[index].balance);
            printf("guardian       =     %d\n", Accounts[index].guardian);
            printf("Gnational_ID   =     %0.0f\n", Accounts[index].guardianNational_ID);
            printf("national_ID    =     %0.0f\n", Accounts[index].national_ID);
            printf("password       =     %d\n", Accounts[index].password);

            printf("***************************************************\n");
            printf("***************************************************\n");
        }
    }

    else
    {
        printf("\n\n****************************************************************\n");
        printf("*                     No account found                         *\n");
        printf("****************************************************************\n");
    }

    u8 choice;
    printf("\n\nDo you want to continue?\n1-for To Back \n2-for Go To Main Menue\n\nEnter your choice: ");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        CLEAR_SCREEN();
        adminMode();
        break;
    case 2:
    default:
        CLEAR_SCREEN();
        startTheSystem();
        break;
    }
}
void Opration_ON_Client(u32 ClinetID)
{
    u8 choice = 0;
    CLEAR_SCREEN();

    printf("*********************************************************************                          \n");
    printf("*                    This Account State is ACTIVE                   *                          \n");
    printf("*********************************************************************                          \n");

    printf("Choose from these options:\n\n\
               1- Make Transaction.\n\
               2- Change Account Status.\n\
               3- Get Cash.\n\
               4- Deposit in Account.\n\
               5- Return to main menu.\n\n");

    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        Make_Transaction(ClinetID);

        adminMode();
        break;
    case 2:

        Admin_changeAccountStatus(ClinetID);

        adminMode();
        break;

    case 3:

        Get_Cash(ClinetID);
        adminMode();
        break;

    case 4:
        Deposit_InAccount(ClinetID);
        adminMode();
        break;
    case 5:
        CLEAR_SCREEN();
        adminMode();
        break;
    default:
        CLEAR_SCREEN();
        printf(" \n\n\n\n\n\t\t\t\t\t     * * * * * * * * * * * * * * * * * * * * ");
        printf("\n\n\t\t\t\t\t     *      You entered invalid option      *");
        printf("\n\n\t\t\t\t\t     * * * * * * * * * * * * * * * * * * * * ");
        delay(3000);
        delay(3000);
        CLEAR_SCREEN();
        Opration_ON_Client(ClinetID);

        break;
    }
}

//////////////////// Client Functions ///////////////////////////////

void Client_Mode(void)
{
    u32 Clinet_AccountID;
    u32 Password;
    u8 passwordCorrect;
    u8 choice, ID_exists1 = 0;
    CLEAR_SCREEN();
    printf("*********************************************************************                          \n");
    printf("*                        Clint Mode                                 *                          \n");
    printf("*********************************************************************                          \n");

    printf("Enter client bank account ID please: ");
    scanf("%d", &Clinet_AccountID);
    ID_exists1 = Check_Account(Clinet_AccountID);

    if (ID_exists1)
    {
        printf("Enter your Password please: ");
        scanf("%d", &Password);
        passwordCorrect = ((Password == Accounts[Clinet_AccountID].password) ? 1 : 0);
        if (passwordCorrect)
        {
            CLEAR_SCREEN();
            if (Accounts[Clinet_AccountID].accountStatus == ACTIVE)
            {
                Clint_Menu(Clinet_AccountID);
            }
            else
            {
                CLEAR_SCREEN();

                printf(" \n\n\n\n\n\t\t\t\t\t     * * * * * * * * * * * * * * * * * * * * ");
                printf("\n\n\t\t\t\t\t     *   This Account State is INACTIVE    *");
                printf("\n\n\t\t\t\t\t     *     please call customer service    *");
                printf("\n\n\t\t\t\t\t     * * * * * * * * * * * * * * * * * * * *");

                printf("\nDo you want to continue ?\n1-for Main Menu.\n2-for Exit.\n\nEnter your choice:: ");
                scanf("%d", &choice);
                switch (choice)
                {
                case 1:
                    CLEAR_SCREEN();
                    startTheSystem();
                    break;
                case 2:
                    CLEAR_SCREEN();
                    exitTheSystem();
                    break;
                default:
                    CLEAR_SCREEN();

                    printf(" \n\n\n\n\n\t\t\t\t\t     * * * * * * * * * * * * * * * * * * * * ");
                    printf("\n\n\t\t\t\t\t     *      You entered invalid option      *");
                    printf("\n\n\t\t\t\t\t     * * * * * * * * * * * * * * * * * * * * ");
                    delay(3000);

                    CLEAR_SCREEN();
                    startTheSystem();

                    break;
                }
            }
        }
        else
        {

            CLEAR_SCREEN();
            printf(" \n\n\n\n\n\t\t\t\t\t     * * * * * * * * * * * * * * * * * * * * ");
            printf("\n\n\t\t\t\t\t     *     You entered invalid password    *");
            printf("\n\n\t\t\t\t\t     * * * * * * * * * * * * * * * * * * * *");

            delay(3000);
            CLEAR_SCREEN();
            startTheSystem();
        }
    }
    else
    {

        CLEAR_SCREEN();
        printf(" \n\n\n\n\n\t\t\t\t\t     * * * * * * * * * * * * * * * * * * * * ");
        printf("\n\n\t\t\t\t\t     *         This ID doesn't exist       *");
        printf("\n\n\t\t\t\t\t     * * * * * * * * * * * * * * * * * * * *");

        delay(3000);
        CLEAR_SCREEN();

        startTheSystem();
    }
}
void Clint_Menu(u32 Clinet_ID)
{
    u8 choice;
    CLEAR_SCREEN();
    printf("*********************************************************************                          \n");
    printf("*                    This Account State is ACTIVE                   *                          \n");
    printf("*********************************************************************                          \n");

    printf("Choose from these options:\n\n\
    1- Make Transaction.\n\
    2- Change Account Password.\n\
    3- Get Cash.\n\
    4- Deposit in Account.\n\
    5- Show current balance.\n\
    6- Return to main menu.\n\n");

    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        CLEAR_SCREEN();
        Make_Transaction(Clinet_ID);

        Clint_Menu(Clinet_ID);
        break;
    case 2:
        CLEAR_SCREEN();
        Chang_Pass(Clinet_ID);
        Clint_Menu(Clinet_ID);
        break;
    case 3:
        CLEAR_SCREEN();
        Get_Cash(Clinet_ID);
        Clint_Menu(Clinet_ID);
        break;
    case 4:
        CLEAR_SCREEN();
        Deposit_InAccount(Clinet_ID);
        Clint_Menu(Clinet_ID);
        break;
    case 5:
        CLEAR_SCREEN();
        Balance_Inquiry(Clinet_ID);
        Clint_Menu(Clinet_ID);
        break;
    case 6:
        CLEAR_SCREEN();
        startTheSystem();
        break;
    default:
        CLEAR_SCREEN();
        printf(" \n\n\n\n\n\t\t\t\t\t     * * * * * * * * * * * * * * * * * * * * ");
        printf("\n\n\t\t\t\t\t     *      You entered invalid option      *");
        printf("\n\n\t\t\t\t\t     * * * * * * * * * * * * * * * * * * * * ");
        delay(3000);
        Clint_Menu(Clinet_ID);
        break;
    }
}
void Chang_Pass(u32 bankAccountId)
{
    CLEAR_SCREEN();
    u32 oldPass, newPass;
    printf("Enter the old Password first: ");
    scanf("%d", &oldPass);
    if (Accounts[bankAccountId].password == oldPass)
    {
        printf("Now, enter the new Password: ");
        scanf("%d", &newPass);

        Accounts[bankAccountId].password = newPass;
        CLEAR_SCREEN();
        printf(" \n\n\n\n\n\t\t\t\t\t* * * * * * * * * * * * * * * * * * * * * * * * * * * *");
        printf("\n\n\t\t\t\t\t*      Changing the Password is Done Successfully!    *");
        printf("\n\n\t\t\t\t\t* * * * * * * * * * * * * * * * * * * * * * * * * * * *");

        delay(3000);
    }
    else
    {
        CLEAR_SCREEN();
        printf(" \n\n\n\n\n\t\t\t\t\t* * * * * * * * * * * * * * * * * * * * * * * * * * * *");
        printf("\n\n\t\t\t\t\t*      You entered the old password is invalid        *");
        printf("\n\n\t\t\t\t\t* * * * * * * * * * * * * * * * * * * * * * * * * * * *");
        delay(3000);
    }
}
void Balance_Inquiry(u32 Clinet_ID)
{
    CLEAR_SCREEN();
    printf("********************************************************                          \n");
    printf("*                    Balance Inquiry                   *                          \n");
    printf("********************************************************                          \n");

    printf("\n\tCurrent Balance        =     %d\n", Accounts[Clinet_ID].balance);

    u8 choice;
    printf("\n\nDo you want to continue?\n1-for To Back \n2-for Go To Main Menue\n\nEnter your choice: ");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        CLEAR_SCREEN();
        Clint_Menu(Clinet_ID);
        break;
    case 2:
        CLEAR_SCREEN();
        startTheSystem();
        break;
    default:
        CLEAR_SCREEN();
        startTheSystem();
        break;
    }
}

///////////////////////////////////////////////////////////////////////

u32 random_(u32 minVal, u32 maxVal)
{
    u8 count = 0;
    u32 result = ((rand() % ((maxVal + 1 - minVal) + minVal)));
    u32 temp = result;
    while (temp != 0)
    {
        temp /= 10;
        count++;
    }
    if (count > RANDOM_PASSWORD_LENGTH)
    {
        result = random_(minVal, maxVal);
    }
    return result;
}
void delay(u32 milli_seconds)
{
    // Storing start time
    clock_t start_time = clock();

    // looping till required time is not achieved
    while (clock() < start_time + milli_seconds)
        ;
}
u8 doubleCompare(f64 num1, f64 num2)
{
    return (fabs(num1 - num2) < EPSILON);
}
