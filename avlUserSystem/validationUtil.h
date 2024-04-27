#ifndef C_PROGRAMMING_VALIDATIONUTIL_H
#define C_PROGRAMMING_VALIDATIONUTIL_H
#include "projectHeader.h"
#include "stdio.h"

int email_valid(char email[30]) {
    // Validate first part of email
    int first_valid = 1;
    int first_count = 0;
    for (int i = 0; email[i] != '@' && i < 30; ++i) {
        if ((email[i] >= '0' && email[i] <= '9') || (email[i] >= 'a' && email[i] <= 'z')) {
            first_count++;
        } else {
            first_valid = 0;
            break;
        }
    }

    // Validate second part of email
    int second_valid = 0;
    if (first_valid && first_count > 0 && first_count < 30 && email[first_count] == '@') {
        const char *domains[] = {"@gmail.com", "@yahoo.com", "@outlook.com", "@apple.com", "@n1c.com"};
        const char *domain = &email[first_count];
        for (int i = 0; i < 5; i++) {
            if (strcmp(domain, domains[i]) == 0) {
                second_valid = 1;
                break;
            }
        }
    }

    if (first_valid && second_valid) {
        printf("\n\n [+] Email validation complete!\n");
        return 1;
    } else {
        printf("\n\n [-] Email validation failed!\n");
        return -1;
    }
}

#endif //C_PROGRAMMING_VALIDATIONUTIL_H
