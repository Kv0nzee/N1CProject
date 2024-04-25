//
// Created by ASUS ZenBook on 3/1/2024.
//

#ifndef C_PROGRAMMING_ENCRYPTION_H
#define C_PROGRAMMING_ENCRYPTION_H
#include "stdio.h"
#include "projectHeader.h"

struct ct *Encryption(char *plainText, char *keys){

    printf("This is plainText %s\n", plainText);
    printf("This is key %s\n", keys);

    int sizeOfPlainText = size_of_charArray(plainText);
    int sizeOfKeys = size_of_charArray(keys);
    // Allocate memory for the encrypted data
    struct ct *encryptedArray = (struct ct *)malloc(sizeof(struct ct));
    if (encryptedArray == NULL) {
        printf("Memory allocation failed\n");
        return NULL;
    }

    // Encrypt the plain text using XOR operation with the keys
    for (int e = 0; e < sizeOfPlainText; e++) {
        char plain = plainText[e];
        for (int k = 0; k < sizeOfKeys; k++) {
            plain = plain ^ keys[k];
        }
        encryptedArray->data[e] = plain;
    }

    // Add null terminator to make it a valid string
    encryptedArray->data[sizeOfPlainText] = '\0';

    return encryptedArray;
}

#endif //C_PROGRAMMING_ENCRYPTION_H
