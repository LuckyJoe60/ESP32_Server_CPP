#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
 
  
extern "C" 
{
    void app_main()
    {
        gpio_pad_select_gpio(GPIO_NUM_2);
        /* Set the GPIO as a push/pull output */
        gpio_set_direction(GPIO_NUM_2, GPIO_MODE_OUTPUT);
        while(1) 
        {
            /* Blink off (output low) */
            gpio_set_level(GPIO_NUM_2, 0);
            vTaskDelay(1000 / portTICK_RATE_MS);
            /* Blink on (output high) */
            gpio_set_level(GPIO_NUM_2, 1);
            vTaskDelay(1000 / portTICK_RATE_MS); 
        }
    }
}