#include "stdio.h"
#include "stdlib.h"

// function declare
void copy_two_charArray(char first[30],char second[30]);
void registration();
void menu();
void login();
void login_checking(char l_email[30],char l_pass[20]);
int size_of_charArray(char arr[30]);
int compare_two_char_array(char first[30],char second[30]);
void my_privilege(int uId);
void user_info_change(int uId);

// globe variables
int gUserCount = 0;
int gLoginCheck = -1;

//structure declare
struct Db{
    int uId;
    char userName[30];
    char email[30];
    char pass[30];
    int phoneNumber;
    char address[30];
    int postalCode;
};

struct Db data[10];

int main(){

    menu();

    return 0;
}

void menu(){
    while(1){
        int option = 0;

        printf("\nWelcome to our system\n");
        printf("Choose Options: \n1:Login \n2:Register \n3:Exit \nEnter your choices(numbers only)");
        scanf("%d", &option);

        if(option == 1){
            login();
        }else if(option == 2){
            registration();
        }else if(option == 3){
            exit(1);
        }else{
            printf("choose from the provided options only\n");
            continue;
        }
    }
}

void login(){
    char lEmail[30];
    char lPass[30];
    printf("Login!!\n");
    printf("Enter your Email");
    scanf(" %[^\n]", &lEmail);
    printf("Enter your password");
    scanf(" %[^\n]", &lPass);

    login_checking(lEmail, lPass);
    if(gLoginCheck != -1){
        printf("\nLogin Success Welcome!\n");
        my_privilege(gLoginCheck);
    }else{
        printf("\nLogin Failed Try Again!\n");
        menu();
    }
}

void my_privilege(int uId){

    int mOption = -1;
    printf("Welcome Sir: %s\n", data[uId].userName);
    printf("Your PhoneNumber: %d\n", data[uId].phoneNumber);

    printf("What you want to do!\n");
    printf("Enter 0 To  Exit:\nEnter 1 to Menu:\nEnter 2 to change user info:");
    if(mOption == 0){
        exit(1);
    }else if(mOption == 1){
        menu();
    }else if(mOption == 2){
        user_info_change(uId);
    }else{
        printf("choose from the provided options only\n");
        my_privilege(uId);
    }
}

void user_info_change(int uId){
    int cOption=0;
    printf("Press 1: To change Name:\nPress 2: To change Email:\n");
    printf("Press 3: To change Password:\nPress 4: To change PhoneNumber:\n");
    printf("Press 5: To change Address:\nPress 6: To change PostCode:\n");
    printf("Press 7: For your privilege:");
    scanf("%d",&cOption);

    switch (cOption) {
        case 1: {
            char newUserName[30];
            printf("To Change username: \n");
            printf("This is your user name: %s\n", data[uId].userName);
            printf("Enter your new user name:");
            scanf(" %[^\n]", newUserName);
            copy_two_charArray(data[uId].userName, newUserName);
            printf("This is your new user name: %s", data[uId].userName);
            break;
        }
        case 2: {
            char newEmail[30];
            printf("To Change email: \n");
            printf("This is your email: %s\n", data[uId].email);
            printf("Enter your new email:");
            scanf(" %[^\n]", newEmail);
            copy_two_charArray(data[uId].email, newEmail);
            printf("This is your new email: %s", data[uId].email);
            break;
        }
        case 3: {
            char newPassword[30];
            printf("To Change password: \n");
            printf("Enter your new password:");
            scanf(" %[^\n]", newPassword);
            copy_two_charArray(data[uId].pass, newPassword);
            printf("Password changed successfully.");
            break;
        }
        case 4: {
            int newPhoneNumber;
            printf("To Change phone number: \n");
            printf("Enter your new phone number:");
            scanf("%d", &newPhoneNumber);
            data[uId].phoneNumber = newPhoneNumber;
            printf("Phone number changed successfully.");
            break;
        }
        case 5: {
            char newAddress[30];
            printf("To Change address: \n");
            printf("Enter your new address:");
            scanf(" %[^\n]", newAddress);
            copy_two_charArray(data[uId].address, newAddress);
            printf("Address changed successfully.");
            break;
        }
        case 6: {
            int newPostalCode;
            printf("To Change postal code: \n");
            printf("Enter your new postal code:");
            scanf("%d", &newPostalCode);
            data[uId].postalCode = newPostalCode;
            printf("Postal code changed successfully.");
            break;
        }
        case 7: {
            printf("Privilege changed successfully.");
            my_privilege(uId);
            break;
        }
        default:
            printf("Invalid option!\n");
            user_info_change(uId);
    }
}

void login_checking(char email[30], char pass[30]){
    int i = 0;
    gLoginCheck = -1;

    for(i = 0; i < gUserCount; i++){
        int emailCheck = compare_two_char_array(data[i].email, email);
        if(emailCheck == 1){
            int passCheck = compare_two_char_array(data[i].pass, pass);
            if(passCheck == 1){
                printf("\n Email And Password correct");
                gLoginCheck = data[i].uId;
                break;
            }
        }
    }
}

void registration(){
    char username[30];
    char email[30];
    char password[30];
    int phoneNumber = 0;
    char address[30];
    int postalCode = 0;

    printf("Welcome from Registration\n");
    printf("Enter Username:");
    scanf(" %[^\n]", &username);
    printf("Enter email:");
    scanf(" %[^\n]", &email);
    printf("Enter password:");
    scanf(" %[^\n]", &password);
    printf("Enter phoneNumber:");
    scanf("%d", &phoneNumber);
    printf("Enter address:");
    scanf(" %[^\n]", &address);
    printf("Enter postal Code:");
    scanf("%d", &postalCode);

    copy_two_charArray(data[gUserCount].userName, username);
    printf("\nChecking for username: %s",data[gUserCount].userName);
    copy_two_charArray(data[gUserCount].email, email);
    printf("\nChecking for email: %s",data[gUserCount].email);
    copy_two_charArray(data[gUserCount].pass, password);
    printf("\nChecking for password: %s",data[gUserCount].pass);
    data[gUserCount].phoneNumber = phoneNumber;
    printf("\nChecking for phoneNumber: %d",data[gUserCount].phoneNumber);
    copy_two_charArray(data[gUserCount].address, address);
    printf("\nChecking for address: %s",data[gUserCount].address);
    data[gUserCount].postalCode = postalCode;
    printf("\nChecking for phoneNumber: %d",data[gUserCount].postalCode);

    data[gUserCount].uId = gUserCount;
    gUserCount++;
}

void copy_two_charArray(char first[30],char second[30]){

    int i = 0;
    for(i = 0; i < 30; i++){
        if(second[i] == '\0'){
            break;
        }else{
            first[i] = second[i];
        }
    }
}

int compare_two_char_array(char first[30],char second[30]){

    int size1 = size_of_charArray(first);
    int size2 = size_of_charArray(second);
    int sameCount = 0;

    if(size1 == size2){
        for(int i = 0; i < size1; i++){
            if(first[i] == second[i]){
                sameCount++;
            }
        }
    }

    if(size1 == sameCount){
        return 1;
    }else{
        return 0;
    }
}

int size_of_charArray(char arr[30]){
    int size = 0;
    for(int i=0; i< 30; i++){
        if(arr[i] == '\0'){
            break;
        }
        size++;
    }

    return size;
}