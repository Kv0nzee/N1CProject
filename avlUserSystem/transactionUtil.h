#ifndef C_PROGRAMMING_TRANSACTIONUTIL_H
#define C_PROGRAMMING_TRANSACTIONUTIL_H
#include "stdio.h"
#include "projectHeader.h"
#include "validationUtil.h"

void transaction(struct Db* sender, struct Db* receiver, double amount){
    double percentage =  amount * 0.02;
    sender->amount -= (amount + percentage);
    root->amount += percentage; // i supposed root is admin
    receiver->amount += amount;

    printf("Transaction Complete From %s to %s : amount=%lf\n", sender->userName, receiver->userName, amount);
    printf("Transfer Amount + Transaction Fee: -%lf\n", amount + percentage);

    transaction_record(sender, receiver, amount);
    my_privilege(sender);
}

void transaction_record(struct Db* sender, struct Db* receiver, double amount){
    int sender_index = sender->trans_counter;
    int receiver_index = receiver->trans_counter;
    int adminIndex = root->trans_counter; // i supposed root is admin

    char from[] = "From-";
    char to[] = "-To-";
    char receive[] = "ReceiveFrom-";

    sprintf(sender->trans[sender_index].transRecord, "%s%s%s%s%c%lf", from, sender->userName, to, receiver->userName, '-', amount);
    sprintf(receiver->trans[receiver_index].transRecord, "%s%s%c%lf", receive, sender->userName, '-', amount);

    // for admin record
    sprintf(root->trans[adminIndex].transRecord, "%s%s%s%s%c%lf", from, sender->userName, to, receiver->userName, '-', amount);

    root->trans_counter++;
    sender->trans_counter++;
    receiver->trans_counter++;
}

void to_transfer_checking(struct Db* sender){
    double amount = 0;
    int receiverPhoneNumber = 0;
    struct Db* receiver = NULL;
    int option = 0;
    int countWrong = 0;

    printf("Enter the amount to transfer: ");
    scanf("%lf", &amount);

    while(sender->amount > amount + 100){
        printf("Enter receiver phone number to send money: ");
        scanf("%d", &receiverPhoneNumber);
        receiver = searchUserByPhoneNumber(root, receiverPhoneNumber);
        if(receiver != NULL){
            transaction(sender, receiver, amount);
            return;
        } else{
            printf("This phone number is not available in our system!\n");
            countWrong++;
            if(countWrong > 2){
                fprintf(stderr, "Wrong Phone Number!");
                my_privilege(sender);
            }
        }
    }

    printf("Insufficient Amount: %lf\n", sender->amount);
    printf("Press 1 to continue transaction:\nPress 2 to get Privilege:\n");
    scanf("%d", &option);
    if(option == 1){
        to_transfer_checking(sender);
    } else if(option == 2){
        my_privilege(sender);
    } else{
        fprintf(stderr, "Invalid Option\n");
        menu();
    }
}
#endif //C_PROGRAMMING_TRANSACTIONUTIL_H
