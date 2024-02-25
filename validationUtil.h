#ifndef C_PROGRAMMING_VALIDATIONUTIL_H
#define C_PROGRAMMING_VALIDATIONUTIL_H
#include "projectHeader.h"
#include "stdio.h"
#include "transactionUtil.h"

void email_valid(char email[30]){
    // number , small letter ယူမယ် ကျန်တာ အကုန် ဘန်း // num = 48-57 , small = 97-122
    // to_valid_email[30] = {w,i,n,a,s,m,@,n,1,c,.,c,o,m};
    int first_count=0;
    char one_char;
    char first_valid=0;
    int arr_size =  size_of_charArray(email);

    for (int i = 0; i < arr_size; ++i) {
        if(email[i]=='@'){
            break;
        } else{
            first_count++;
        }
    }
    for(int x=0; x<first_count; x++){
        one_char = email[x];
        if((one_char>=48 && one_char<=57)||(one_char>=97 &&one_char<=122)){
            first_valid++;
        } else{
            first_valid=-1;
        }
    }

    if(first_count!=first_valid || first_count==arr_size || first_count==0){
        emailValidation=-1;
        return;
    } else{
        emailValidation=1;
        printf("\n\n [+]First Part checking complete!\n");
    }

    printf("Arr Size: %d\n",arr_size);
    printf("first_count %d\n",first_count);
    printf("First count index value %c\n",email[first_count]);

    // @gmail.com , @yahoo.com , @outlook.com , @apple.com , @n1c.com
    char gmail[11]={'@','g','m','a','i','l','.','c','o','m'};
    char yahoo[11]={'@','y','a','h','o','o','.','c','o','m'};
    char outlook[12]={'@','o','u','t','l','o','o','k','.','c','o','m'};
    char apple[11]={'@','a','p','p','l','e','.','c','o','m'};
    char n1c[11]={'@','n','1','c','.','c','o','m'};
    int second_count=0;
    char arr_sec_part[13];
    int for_sec_index=0;

    second_count = arr_size-first_count;
    printf("second count value : %d\n",second_count);
    printf("Second Data :");
    for(int xxx=first_count; xxx<arr_size; xxx++){
        arr_sec_part[for_sec_index] = email[xxx];
        printf("%c",arr_sec_part[for_sec_index]);
        for_sec_index++;

    }
    printf("\n");

    int g = compare_two_char_array(arr_sec_part,gmail);
    int y = compare_two_char_array(arr_sec_part,yahoo);
    int o = compare_two_char_array(arr_sec_part,outlook);
    int a = compare_two_char_array(arr_sec_part,apple);
    int n = compare_two_char_array(arr_sec_part,n1c);

    if(g||y||o||a||n){
        emailValidation=1;
        printf("\n\n [+]Second Part checking complete!\n");

    } else{
        printf("Second email validatino failed!\n");
        emailValidation=-1;
    }
}

#endif //C_PROGRAMMING_VALIDATIONUTIL_H
