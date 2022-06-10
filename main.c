#include <stdio.h>
#include "pico/stdlib.h"
#include <math.h>
#include "hardware/adc.h"

int main() {
  stdio_init_all();
  printf ("measuring gpi026/n");

  adc_init();
  adc_gpio_init(27);

   adc_select_input(1);

   float rAux = 10000 ;
   float vcc  = 3.3 ;
   float beta = 3977 ;
    float temp0 = 298;
    float r0 = 10000 ;
    float vm , rntc , temperaturaC , temperaturaK ;
    while  (1) {
      vm= (vcc / 4095.0) * adc_read();
      rntc = rAux / ((vcc/vm)-1);
      temperaturaK = beta / (log(rntc/r0) + (beta/temp0));
      temperaturaC = temperaturaK - 273;

      printf ("rntc: %2f temperaturaC: %.2fV/n", rntc, temperaturaC);
      sleep_ms(3000);
    }
}