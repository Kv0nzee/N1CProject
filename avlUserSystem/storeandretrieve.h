#ifndef C_PROGRAMMING_STOREANDRETRIEVE_H
#define C_PROGRAMMING_STOREANDRETRIEVE_H

#include "stdio.h"
#include "stdlib.h"
#include "projectHeader.h"

void storeUserDataToFileHelper(struct Db* root, FILE *fp) {
    if (root == NULL) {
        return;
    }

    storeUserDataToFileHelper(root->left, fp);

    fprintf(fp, "%d;%s;%s;%d;%s;%d;%s;%lf;%d;%d\n", root->uId, root->userName, root->email, root->phoneNumber, root->address, root->postalCode, root->pass, root->amount, root->trans_counter, root->height);

    storeUserDataToFileHelper(root->right, fp);
}

void storeUserDataToFile(struct Db* root) {
    FILE *fp;
    fp = fopen("userdata.txt", "w"); // Open the file in w

    if (fp == NULL) {
        printf("Error opening file!\n");
        return;
    }

    storeUserDataToFileHelper(root, fp);

    fclose(fp);
}

// Function to retrieve user data from the text file
void retrieveUserDataFromFile() {
    FILE *fp;
    fp = fopen("userdata.txt", "r"); // Open the file in read mode

    if (fp == NULL) {
        printf("Error opening file!\n");
        return;
    }

    // Read user data from the file
    struct Db user;
    while (fscanf(fp, "%d;%[^;];%[^;];%d;%[^;];%d;%[^;];%lf;%d;%d\n", &user.uId, user.userName, user.email, &user.phoneNumber, user.address, &user.postalCode, user.pass, &user.amount, &user.trans_counter, &user.height) != EOF) {
        root = insertNode(root, user.phoneNumber);
        struct Db* newUser = searchUserByPhoneNumber(root, user.phoneNumber);
        copy_two_charArray(newUser->userName, user.userName);
        copy_two_charArray(newUser->email, user.email);
        copy_two_charArray(newUser->pass, user.pass); // Include password
        copy_two_charArray(newUser->address, user.address);
        newUser->postalCode = user.postalCode;
        newUser->amount = user.amount;
        newUser->trans_counter = user.trans_counter;
        newUser->height = user.height;
    }

    fclose(fp); // Close the file
}

#endif //C_PROGRAMMING_STOREANDRETRIEVE_H
