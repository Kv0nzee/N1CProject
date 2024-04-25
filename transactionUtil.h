//
// Created by ASUS ZenBook on 2/25/2024.
//

#ifndef C_PROGRAMMING_TRANSACTIONUTIL_H
#define C_PROGRAMMING_TRANSACTIONUTIL_H
#include "stdio.h"
#include "projectHeader.h"
#include "validationUtil.h"

void transaction(int sender_id , int receiver_id,double amount){

    double percentage =  amount*0.02;
    data[sender_id].amount = data[sender_id].amount - (amount  + percentage);
    data[0].amount = data[0].amount + percentage;
    data[receiver_id].amount = data[receiver_id].amount + amount;
    printf("Transaction Complete From %s to %s : amount=%lf\n",data[sender_id].userName,data[receiver_id].userName,amount);

    printf("\nTransfer Amount + Transaction Fee: -%lf",amount+percentage);
    transaction_record(sender_id , receiver_id,amount);
    all_data();
    my_privilege(sender_id);

}

void transaction_record(int sender_id , int receiver_id,double amount){
    int sender_index= data[sender_id].trans_counter;
    int receiver_index=data[receiver_id].trans_counter;
    int adminIndex = data[0].trans_counter;

    char *from="From-";
    char *sender = data[sender_id].userName;
    char *to="-To-";
    char *receiver= data[receiver_id].userName;

    char *receive="ReceiveFrom-";

    sprintf((char *) data[sender_id].trans[sender_index].transRecord, "%s%s%s%s%c%lf", from, sender, to, receiver,'-',amount);
    sprintf((char *) data[receiver_id].trans[receiver_index].transRecord, "%s%s%c%lf", receive, sender,'-',amount);

    //For Admin Record
    sprintf((char *) data[0].trans[adminIndex].transRecord, "%s%s%s%s%c%lf", from, sender, to, receiver,'-',amount);

    data[0].trans_counter++;
    data[sender_id].trans_counter++;
    data[receiver_id].trans_counter++;

}

void to_transfer_checking(int id){
    double amount = 0;
    int recieverPhoneNumber = 0;
    int phoneId = 0;
    int option = 0;
    int coutWrong = 0;
    printf("Enter you amount to transfer: ");
    scanf("%lf", &amount);

    while(data[id].amount > amount + 100){
        printf("Enter receiver phone number to send money:");
        scanf("%d",&recieverPhoneNumber);
        phoneId = to_check_phone(recieverPhoneNumber);
        if(phoneId != -1){
            transaction(id, phoneId, amount);
        } else{
            printf("This phone number is not available in our system!\n");
            coutWrong++;
            if(coutWrong>2){
                fprintf(stderr,"Wrong Phone Number!");
                my_privilege(id);
            }
        }
    }

    printf("Insufficient Amount: %lf\n",data[id].amount);
    printf("Press 1 to continue transaction:\nPress 2 To get Privilege:\n");
    scanf("%d",&option);
    if(option==1){
        to_transfer_checking(id);
    } else if(option==2){
        my_privilege(id);
    } else{
        fprintf(stderr,"Invalid Option\n");
        menu();
    }
}
#endif //C_PROGRAMMING_TRANSACTIONUTIL_H
