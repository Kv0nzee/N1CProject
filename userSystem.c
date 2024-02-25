#include "projectHeader.h"
#include "transactionUtil.h"
#include "validationUtil.h"
#include "stdio.h"

int main(){

    transaction_record(1,1, 1000);

    loading_data_from_file();
    all_data();
    menu();

    return 0;
}
//}