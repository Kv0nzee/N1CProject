//
// Created by ASUS ZenBook on 2/25/2024.
//

#ifndef C_PROGRAMMING_PROJECTHEADER_H
#define C_PROGRAMMING_PROJECTHEADER_H

#include "stdio.h"
#include "stdlib.h"
#include <string.h>

struct ct {
    char data[50];
};

//structure declare
struct to_record{
    char transRecord[200];
};

struct Db {
    int uId;
    int balanceFactor;
    int height;
    struct Db *left;
    struct Db *right;
    char userName[30];
    char email[30];
    char pass[30];
    int phoneNumber;
    char address[30];
    int postalCode;
    double amount;
    int trans_counter;
    struct to_record trans[100];
};

// globe variables
int gUserCount = 0;
int gLoginCheck = -1;
int emailValidation = -1;
struct Db* root = NULL;

// function declare
void inorder(struct Db* root, int depth);
int getHeight(struct Db* node);
struct Db* create(int phoneNumber);
int max(int l, int r);
int getBalanceFactor(struct Db* node);
struct Db* leftRotate(struct Db* node);
struct Db* rightRotate(struct Db* node);
struct Db* insertNode(struct Db* root, int key);
struct Db* searchUserByPhoneNumber(struct Db* root, int data);
struct Db* findMin(struct Db* root);
struct Db* deleteNode(struct Db* root, int key);

void menu();
void login();
void registration();
struct Db* searchUserByEmail(struct Db* root, const char* email);
int email_valid(char email[30]);
void copy_two_charArray(char first[30],char second[30]);
void my_privilege(struct Db* user);
int compare_two_char_array(char first[30],char second[30]);
int size_of_charArray(char arr[30]);
void copy_two_charArray(char first[30],char second[30]);

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
            printf("\n\n__________Data Recording Complete!___________\n");
            exit(1);
        }else{
            printf("choose from the provided options only\n");
            continue;
        }
    }
}

void registration(){
    char username[30];
    char email[30];
    char password[30];
    int  phoneNumber = 0;
    char address[30];
    int  postalCode = 0;

    printf("Welcome from Registration\n");
    printf("Enter Username:");
    scanf(" %[^\n]", &username);

    //check email exist or not
    int email_exist = -1;
    int emailValidation = -1;
    printf("Enter email:");
    while(email_exist == -1 || emailValidation == -1){
        scanf(" %[^\n]", &email);
        emailValidation = email_valid(email);
        struct Db* user = searchUserByEmail(root, email);
        if( user == NULL){
            email_exist = 1;
        }
        if(emailValidation == -1){
            printf("Your email is not valid! %s\n",email);
            printf("Enter your new email address!\n");
            continue;
        }
    }

    printf("Enter password:");
    scanf(" %[^\n]", &password);
    printf("Enter phoneNumber:");
    scanf("%d", &phoneNumber);
    printf("Enter address:");
    scanf(" %[^\n]", &address);
    printf("Enter postal Code:");
    scanf("%d", &postalCode);

    root = insertNode(root,phoneNumber);
    struct Db* user = searchUserByPhoneNumber(root, phoneNumber);
    copy_two_charArray(user->userName, username);
    printf("\nChecking for username: %s",user->userName);
    copy_two_charArray(user->email, email);
    printf("\nChecking for email: %s",user->email);
    copy_two_charArray(user->pass, password);
    printf("\nChecking for password: %s",user->pass);
    printf("\nChecking for phoneNumber: %d",user->phoneNumber);
    copy_two_charArray(user->address, address);
    printf("\nChecking for address: %s",user->address);
    user->postalCode = postalCode;
    printf("\nChecking for phoneNumber: %d",user->postalCode);

    user->amount = 1000;
    user->uId = gUserCount;
    user->trans_counter = 0;
    gUserCount++;
}

// Function to search for a user by email
struct Db* searchUserByEmail(struct Db* root, const char* email) {
    if (root == NULL) return NULL;

    if (strcmp(root->email, email) == 0)
        return root;

    struct Db** leftResult = searchUserByEmail(root->left, email);
    if (leftResult != NULL) return leftResult;

    return searchUserByEmail(root->right, email);
}

void login(){
    inorder(root, 0);
    int lPhoneNumber;
    char lPass[30];
    printf("Login!!\n");
    printf("Enter your Phone Number");
    scanf("%d", &lPhoneNumber);
    printf("Enter your password");
    scanf(" %[^\n]", lPass);

    struct Db* user = searchUserByPhoneNumber(root, lPhoneNumber);
    if(user && strcmp(user->pass, lPass) == 0){
        gLoginCheck = 1;
        printf("\nLogin Success Welcome!\n");
        my_privilege(user);
    }else{
        printf("\nLogin Failed Try Again!\n");
        menu();
    }
}

void my_privilege(struct Db* user){
    int mOption = 0;

//    if(data[uId].uId<3){
//        admin_sector(uId);
//    }else {
        printf("Welcome Sir: %s\n", user->userName);
        printf("Your PhoneNumber: %d\n", user->phoneNumber);

        printf("What you want to do!\n");
        printf("Enter 0 To  Exit:\nEnter 1 to Menu:\nEnter 2 to change user info:\n Enter 3 To transfer money:");
        scanf("%d", &mOption);
        if (mOption == 0) {
            return;
        } else if (mOption == 1) {
            menu();
        } else if (mOption == 2) {
//            user_info_change(uId);
        }else if(mOption==3){
//            to_transfer_checking(uId);
        } else {
            printf("choose from the provided options only\n");
            my_privilege(user);
        }
//    }
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

#endif //C_PROGRAMMING_PROJECTHEADER_H
