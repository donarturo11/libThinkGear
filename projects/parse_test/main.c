#include <stdlib.h>
#include <stdio.h>
#include "ThinkGear.h"
#include "BasicListener.h"
#include "thinkgear_test.h"

#define BUFSIZE 512

int main()
{
    ThinkGear* tg=NULL; 
    tg = ThinkGear_init();
    BasicListener_init(tg->ops);
    printf("ThinkGear begin test:\n");
    ThinkGear_readBytes(tg, thinkgear_test, thinkgear_test_len);
    printf("ThinkGear end test\n");
    ThinkGear_delete(tg);
    return 0;
     
}
