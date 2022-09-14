#ifndef BANKK_H_INCLUDED
#define BANKK_H_INCLUDED

#include "STD_TYPES.h"

#define CLEAR_SCREEN() system("cls")

#define EPSILON 0.000001
#define NUMBER_OF_CUSTOMERS 10
#define ID_OF_ACCOUNT 1001

#define MAX_RANDOM_PASSWORD 9999
#define MIN_RANDOM_PASSWORD 0
#define RANDOM_PASSWORD_LENGTH 4

#define ADMIN_USERNAME "Admin"
#define ADMIN_PASSWORD_LENGTH 4
#define ADMIN_PASSWORD "1234"

typedef enum
{
    ACTIVE = 1,
    RESTRICTED,
    CLOSED
} AccountStatus_t;

typedef enum
{
    SUCCESS_OPERATION = 1,
    FAIL_NOT_SUFFICIENT_MONEY,
    FAIL_NOT_AN_ACTIVE_USER
} TransactionStatus_t;

FILE *fp;
typedef struct
{
    u8 fullName[50];
    u8 fullAddress[50];
    u8 age;
    f64 national_ID;
    u32 BankAccount_ID;
    u8 guardian;
    f64 guardianNational_ID;
    u32 balance;
    AccountStatus_t accountStatus; // Default set to ACTIVE
    u32 password;                  // Auto generated
} AccountInfo_t;

/////////////////// System Functions ///////////////////////////////

void Wellcom();
void startTheSystem(void);
void exitTheSystem(void);

///////////////////Common Functions ///////////////////////////////

u8 Check_Account(u32 bankAccountID);
void Make_Transaction(u32 SenderID);
void Get_Cash(u32 userID);
void Deposit_InAccount(u32 userID);

///////////////////// Admin Functions /////////////////////////////

void Admin_Login();
void adminMode(void);
void createNewAccount(void);
void openExistingAccount(void);
void Admin_changeAccountStatus(u32 userID);
void Show_Accounts_Info(void);
void Opration_ON_Client(u32 ClinetID);

//////////////////// Client Functions ///////////////////////////////

void Client_Mode(void);
void Clint_Menu(u32 bankAccount_ID);
void Chang_Pass(u32 bankAccountId);
void Balance_Inquiry(u32 Clinet_ID);

/////////////////////////////////////////////////////////////////////

    u32 random_(u32 minVal, u32 maxVal);
void delay(u32 milli_seconds);
u8 doubleCompare(f64 num1, f64 num2);

#endif // BANK_INTERFACE_H_INCLUDED
