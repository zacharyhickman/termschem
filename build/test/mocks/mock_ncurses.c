#include <string.h>
#include <stdlib.h>
#include <setjmp.h>
#include "cmock.h"
#include "mock_ncurses.h"


static struct mock_ncursesInstance
{
  unsigned char placeHolder;
} Mock;

extern jmp_buf AbortFrame;
extern int GlobalExpectCount;
extern int GlobalVerifyOrder;

void mock_ncurses_Verify(void)
{
}

void mock_ncurses_Init(void)
{
  mock_ncurses_Destroy();
}

void mock_ncurses_Destroy(void)
{
  CMock_Guts_MemFreeAll();
  memset(&Mock, 0, sizeof(Mock));
  GlobalExpectCount = 0;
  GlobalVerifyOrder = 0;
}

