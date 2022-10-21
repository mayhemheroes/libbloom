/*
 *  Copyright (c) 2016-2022, Jyri J. Virkki
 *  All rights reserved.
 *
 *  This file is under BSD license. See LICENSE file.
 */

#include <assert.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdint.h>
#include <stddef.h>

#include "bloom.h"

#ifdef __linux
#include <sys/time.h>
#include <time.h>
#endif

int LLVMFuzzerTestOneInput(const uint8_t *Data, size_t Size)
{
  printf("Entering...\n");
  struct bloom bloom;

  uint8_t n;  
  uint8_t copy[Size];
  memcpy(copy, Data, Size); // make a non-const copy of the fuzz data
  
  bloom_init2(&bloom, copy[0], 0.01);
  
  for (n = 1; n < (uint8_t) 1000; n++) {
    bloom_add(&bloom, &n, sizeof(uint8_t));
  }
  
  //bloom_add(&bloom, copy, sizeof(uint8_t));
  
 
  

  if (bloom_check(&bloom, Data, Size)) { 
    bloom_print(&bloom);
    printf("It may be there!\n");
  }
  bloom_free(&bloom);
  printf("Done!\n");
  return 0;
}
