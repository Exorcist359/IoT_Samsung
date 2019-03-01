#include "xtimer.h"
#include "timex.h"
#include "periph/gpio.h"

int main(void)
{
    // Инициализация пина PC9 на выход
	gpio_init(GPIO_PIN(PORT_C,9), GPIO_OUT);
    xtimer_ticks32_t last_wakeup = xtimer_now();
    while(1){
        // Переключение состояния пина PC9
    	gpio_toggle(GPIO_PIN(PORT_C,9));
        // Сон на 1 секунду
    	xtimer_periodic_wakeup(&last_wakeup, 1000000);
    }
    return 0;
}
