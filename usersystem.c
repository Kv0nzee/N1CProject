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
int email_scanner(char email[30]);
void email_valid(char email[30]);
void record_data();
void retrieve_data();

// globe variables
int gUserCount = 0;
int gLoginCheck = -1;
int emailValidation = -1;

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

    //check email exist or not
    int email_exist = -1;

    while(email_exist == -1 && emailValidation == -1){
        printf("Enter email:");
        scanf(" %[^\n]", &email);
        email_valid(email);
        if(emailValidation == -1){
            printf("Your email is not valid! %s\n",email);
            printf("Enter your new email address!\n");
            continue;
        }
        email_exist = email_scanner(email);
        if(email_exist==-1){
            printf("Your email already registered! %s\n",email);
            printf("Enter your new email address!\n");
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
    record_data();
    retrieve_data();
    exit(EXIT_SUCCESS);
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

int email_scanner(char email[30]){
    int isExist = -1;
    if(gUserCount == 0){
        return 1;
    }else{
        for(int i = 0; i < gUserCount; i++){
            isExist = compare_two_char_array(data[i].email, email);
            if(isExist == 1){
                return -1; //is already register
            }
        }
    }

    return 1; //you can register
}

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

void record_data(){
    FILE *fptr = fopen("database.txt", "a");

    if(!fptr){
        perror("Cant Find file");
    }

    printf("Recording data... to File!");
    for(int i = 0; i < gUserCount; i++){
        fwrite(&data[i], sizeof(Db), 1, fptr);
    }

    fclose(fptr);
    printf("Success!\n");

}

void retrieve_data(){
    FILE *fptr = fopen("database.txt", r);
    if(fptr==NULL){
        perror("Error\n");
    }

    fread(&data[i], sizeof(Db), 1, fptr);
    printf("MyRecord ID: %d , Score: %s\n",data[1].uId,data[1].userName);

}