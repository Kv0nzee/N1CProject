//
// Created by ASUS ZenBook on 3/1/2024.
//

#ifndef C_PROGRAMMING_ENCRYPTION_H
#define C_PROGRAMMING_ENCRYPTION_H
#include "stdio.h"
#include "projectHeader.h"

Kaung *Encryption(char *plainText, char *keys){

    printf("This is plainText %s\n", plainText);
    printf("This is key %s\n", keys);

    int sizeOfPlainText = size_of_charArray(plainText);
    int sizeOfKeys = size_of_charArray(keys);
    Kaung *encryptedArray =   (Kaung *) malloc(sizeof(Kaung));

    for(int e = 0; e<sizeOfPlainText; e++){
            int plain = plainText[e];
        for(int k = 0; k<sizeOfKeys; k++){
            plain =  plain^keys[k];
        }
        encryptedArray[e].data[e] =  plain;
    }
    return (Kaung *) encryptedArray->data;
}

#endif //C_PROGRAMMING_ENCRYPTION_H
