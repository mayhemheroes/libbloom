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
  struct bloom bloom;


  return 0;
}
