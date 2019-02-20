#include <stdio.h>
#include <psp2/ctrl.h>
#include "debugScreen.h"

#define printf psvDebugScreenPrintf

int main(int argc, char *argv[]) {

SceCtrlData pad;
uint32_t old_buttons, current_buttons, pressed_buttons;
int enter_button;
int sel;

psvDebugScreenInit();
psvDebugScreenSetFgColor(COLOR_WHITE);

sel = 0;
old_buttons = 0, current_buttons = 0, pressed_buttons = 0;


printf("Heres a handy guide!\n"); 
printf("Pressing CROSS will say 'The FitnessGram Pacer Test.'\n"); 
printf("Pressing R TRIGGER will say 'pineas and forbes.'\n");
printf("Pressing L TRIGGER will say 'OwO.'\n");
printf("Pressing CIRCLE will clear screen\n");

  while (1) {
    sceCtrlPeekBufferPositive(0, &pad, 1);

    old_buttons = current_buttons;
    current_buttons = pad.buttons;
    pressed_buttons = current_buttons & ~old_buttons;

   if (pressed_buttons & SCE_CTRL_CROSS) { printf("The FitnessGram Pacer Test is a multistage aerobic capacity test that progressively gets more difficult as it continues. The 20 meter pacer test will begin in 30 seconds. Line up at the start. The running speed starts slowly, but gets faster each minute after you hear this signal. [beep] A single lap should be completed each time you hear this sound. [ding] Remember to run in a straight line, and run as long as possible. The second time you fail to complete a lap before the sound, your test is over. The test will begin on the word start. On your mark, get ready, start..\n"); }
   if (pressed_buttons & SCE_CTRL_LTRIGGER) { printf("there's 104 days 'til my self-mutilation and I'm so done trying to extend itso the annual problem of our generation is finding a good way to end it.\n"); }
   if (pressed_buttons & SCE_CTRL_RTRIGGER) { printf("Imagine reading a post, but over the course of it the quality seems to deteriorate and it gets wose an wose, where the swenetence stwucture and gwammer rewerts to a pwoint of uttew non swence, an u jus dont wanna wead it anymwore (o´ω｀o) awd twa wol owdewl iws jus awfwul (´･ω･`);. bwt tw powost iwswnwt obwer nyet, it gwos own an own an own an own. uwu wanyaa stwop weadwing bwut uwu cwant stop wewding, uwu stwartd thwis awnd ur gwoing two fwinibsh it nowo mwattew wat! uwu hab mwoxie kwiddowo, bwut uwu wibl gwib ub sowon. i cwan wite wike dis fwor owors, swo dwont cwalengbe mii...\n"); }
   if (pressed_buttons & SCE_CTRL_CIRCLE) { psvDebugScreenClear(0x00000000); }

   sel = 0;
   sceKernelDelayThread(10 * 1000);
  }

}

