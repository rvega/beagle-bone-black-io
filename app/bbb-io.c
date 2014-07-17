#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include "pruio_c_wrapper.h"
#include "pruio_pins.h"

PruIo* io;
int pins[] = { P9_11, P9_12, P9_13, P9_14, P9_15, P9_16, P9_17, P9_18, P9_21, P9_22, P9_23, P9_24, P9_26, P9_27, P9_30, P9_41, P9_42 };
int pin_count = 17;

// Set all available pins in P9 as inputs with pulldown
// and switch monitor their state
void all_p9_inputs(){
   int i, pin;

   // For some reason, setting these here, messes up the 
   // pulldown config. 

   /* for(i=0; i<pin_count; i++){ */
   /*    pin = pins[i]; */
   /*    if(pruio_gpio_set(io, pin, PRUIO_IN, PRUIO_UNLOCK_NEW)) { */
   /*       printf("Pin configuration failed %i: %s\n", pin, io->Errr); */
   /*    } */
   /* } */

   if(pruio_config(io, 0, 0x1FE, 0, 4, 0)){
      printf("Config failed (%s)\n", io->Errr); 
      exit(1);
   }

   int value, j;
   while(1){
      j = 0;
      for(i=0; i<pin_count; i++){
         pin = pins[i];
         value = pruio_gpio_get(io, pin);
         printf("%i", value);
         j++;
         if(j==5){
            printf("  ");
            j=0;
         }
      }
      printf("\n");
      sleep(1);
   }
}

// Set all available pins in P9 as outputs and switch 
// their state every 2 seconds.
void all_p9_outputs(){
   int i, pin;

   for(i=0; i<pin_count; i++){
      pin = pins[i];
      if(pruio_gpio_set(io, pin, PRUIO_OUT0, PRUIO_UNLOCK_NEW)) {
         printf("Pin configuration failed %i: %s\n", pin, io->Errr);
      }
   }

   if(pruio_config(io, 0, 0x1FE, 0, 4, 0)){
      printf("Config failed (%s)\n", io->Errr); 
      exit(1);
   }

   while(1){
      for(i=0; i<pin_count; i++){
         pin = pins[i];
         pruio_gpio_out(io, pin, 1);
      }
      printf("1\n");
      sleep(2);
      for(i=0; i<pin_count; i++){
         pin = pins[i];
         pruio_gpio_out(io, pin, 0);
      }
      printf("0\n");
      sleep(2);
   }
}

void init(){
   // Check if device tree overlay is loaded, load if needed.
   int device_tree_overlay_loaded = 0; 
   FILE* f;
   f = fopen("/sys/devices/bone_capemgr.9/slots","rt");
   if(f==NULL){
      printf("Initialisation failed (fopen rt)");
      exit(1);
   }
   char line[256];
   while(fgets(line, 256, f) != NULL){
      if(strstr(line, "SAMPLE-DTO") != NULL){
         device_tree_overlay_loaded = 1; 
      }
   }
   fclose(f);

   if(!device_tree_overlay_loaded){
      f = fopen("/sys/devices/bone_capemgr.9/slots","w");
      if(f==NULL){
         printf("Initialisation failed (fopen)");
         exit(1);
      }
      fprintf(f, "SAMPLE-DTO");
      fclose(f);
      usleep(100000);
   }

   // Init pruio instance
   io = pruio_new(0, 0x98, 0, 1);
   if (io->Errr) {
      printf("Initialisation failed (%s)\n", io->Errr);
      exit(1); 
   } 
}

int main(int argc, const char *argv[]) { 
   init();
   /* all_p9_outputs(); */
   all_p9_inputs();
   pruio_destroy(io);
   return 0;
}
