#include "../bloom.h"
#include <stdio.h>
#include <stddef.h>
#include <stdint.h>



int LLVMFuzzerTestOneInput(uint8_t *data, size_t size) {
    struct bloom bloom;
    int status = bloom_init2(&bloom, 1000000, 0.01);
    //bloom_add(&bloom, buffer, buflen);
    printf("============\n");
    int s_data = (size_t) data;
    
   // if (bloom_check(&bloom, buffer, buflen)) {
   //     printf("It may be there!\n");
   // }	
   return 0;
    
}
