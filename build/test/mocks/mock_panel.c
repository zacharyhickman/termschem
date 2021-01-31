#include <string.h>
#include <stdlib.h>
#include <setjmp.h>
#include "cmock.h"
#include "mock_panel.h"


static struct mock_panelInstance
{
  unsigned char placeHolder;
} Mock;

extern jmp_buf AbortFrame;
extern int GlobalExpectCount;
extern int GlobalVerifyOrder;

void mock_panel_Verify(void)
{
}

void mock_panel_Init(void)
{
  mock_panel_Destroy();
}

void mock_panel_Destroy(void)
{
  CMock_Guts_MemFreeAll();
  memset(&Mock, 0, sizeof(Mock));
  GlobalExpectCount = 0;
  GlobalVerifyOrder = 0;
}

