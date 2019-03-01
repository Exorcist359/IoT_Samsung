#include "xtimer.h"
#include "timex.h"
#include "periph/gpio.h"

#define DEBOUNCE 100 * US_PER_MS
xtimer_ticks32_t previous;

void btn_handler(void *arg)
{
    (void)arg;
    // Избавляемся от дребезжания контакта кнопки
    if ((xtimer_now().ticks32 - previous.ticks32) < DEBOUNCE)
        return;
    
    previous = xtimer_now();
    
    if (gpio_read(GPIO_PIN(PORT_A, 0)) > 0)
        gpio_set(GPIO_PIN(PORT_C, 9));
    else 
        gpio_clear(GPIO_PIN(PORT_C, 9));
}

int main(void)
{
    previous = xtimer_now();
    gpio_init(GPIO_PIN(PORT_C, 9), GPIO_OUT);
    gpio_init_int(GPIO_PIN(PORT_A, 0), GPIO_IN, GPIO_BOTH, btn_handler, NULL);
    
    while (1)
    {
    }
    
    return 0;
}
