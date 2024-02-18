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

// globe variables
int gUserCount = 0;
int gLoginCheck = -1;

//structure declare
struct Db{
    char userName[30];
    char email[30];
    char pass[30];
    int phoneNumber;
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
        menu();
    }else{
        printf("\nLogin Failed Try Again!\n");
        menu();
    }
}

void login_checking(char email[30], char pass[30]){
    int i = 0;
    gLoginCheck = -1;

    for(i = 0; i < gUserCount; i++){
        int emailCheck = compare_two_char_array(data[i].email, email);
        printf("correct");
        if(emailCheck == 1){
            int passCheck = compare_two_char_array(data[i].pass, pass);
            if(passCheck == 1){
                printf("correct");
                gLoginCheck = i;
                break;
            }
        }
    }
}

void registration(){
    char username[30];
    char email[30];
    char password[30];
    int phoneNumber;

    printf("Welcome from Registration\n");
    printf("Enter Username:");
    scanf(" %[^\n]", &username);
    printf("Enter email:");
    scanf(" %[^\n]", &email);
    printf("Enter password:");
    scanf(" %[^\n]", &password);
    printf("Enter phoneNumber:");
    scanf("%d", &phoneNumber);

    copy_two_charArray(data[gUserCount].userName, username);
    printf("\nChecking for username: %s",data[gUserCount].userName);
    copy_two_charArray(data[gUserCount].email, email);
    printf("\nChecking for email: %s",data[gUserCount].email);
    copy_two_charArray(data[gUserCount].pass, password);
    printf("\nChecking for password: %s",data[gUserCount].pass);
    data[gUserCount].phoneNumber = phoneNumber;
    printf("\nChecking for phoneNumber: %d",data[gUserCount].phoneNumber);

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