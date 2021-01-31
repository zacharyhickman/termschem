#include "build/temp/_tui.c"
#include "src/tui.h"
#include "src/charhelper.h"
#include "src/arrayhelper.h"
#include "src/mtxhelper.h"
#include "build/temp/_test_tui.c"
#include "test/../src/tui.h"
#include "test/support/unity.h"






void setUp(void)

{

}



void tearDown(void)

{

}



void test_tui_handle_input(void)

{

 tui_handle_input(

                 (0410 +(

                 10

                 ))

                          );



 do {if ((panel_hidden(panel_notify_exit))) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(20)));}} while(0);

}
