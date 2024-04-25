//
// Created by ASUS ZenBook on 3/1/2024.
//

#ifndef C_PROGRAMMING_DECRYPTION_H
#define C_PROGRAMMING_DECRYPTION_H
#include "projectHeader.h"

struct ct *Decryption(struct ct *Encrypted_Data,  char *keys) {
    printf("\nDecryption Started!\n");
    int sizeOfEncryptedData = size_of_charArray(Encrypted_Data->data);
    int sizeOfKeys = size_of_charArray(keys);

    // Allocate memory for the decrypted data
    struct ct *decryptedDataArray = (struct ct *)malloc(sizeof(struct ct));

    // Decrypt each character
    for(int i = 0; i < sizeOfEncryptedData; i++){
        char encryptedChar = Encrypted_Data->data[i];
        for(int j = 0; j<sizeOfKeys; j++){
            encryptedChar = encryptedChar ^ keys[j];
        }
        decryptedDataArray->data[i] = encryptedChar;
    }

    // Add null terminator to make it a valid string
    decryptedDataArray->data[sizeOfEncryptedData] = '\0';

    return decryptedDataArray;
};

#endif //C_PROGRAMMING_DECRYPTION_H
