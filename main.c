/**
 * @file main.c
 * @brief Simple LED blink example for Raspberry Pi Pico/Pico W using Doxygen-compatible comments.
 * @author Vincent BEGOC (adapted from Raspberry Pi example)
 * @copyright Copyright (c) 2020 Raspberry Pi (Trading) Ltd.
 * @license SPDX-License-Identifier: BSD-3-Clause
 */

 // For basic functionality
#include "pico/stdlib.h"

// Pico W devices use a GPIO on the WIFI chip for the LED,
// so when building for Pico W, CYW43_WL_GPIO_LED_PIN must be defined
#include "pico/cyw43_arch.h"

/**
 * @brief Turns the onboard LED on or off.
 * @param led_state If true, the LED is turned on; if false, it is turned off.
 * @note For Pico W, this function uses the WiFi chip GPIO to control the LED.
 */
void pico_set_led(bool led_state) {
    // Ask the wifi "driver" to set the GPIO on or off
    cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, led_state);
}

/**
 * @brief Main function: Blinks the onboard LED at a fixed interval.
 * @return int Returns 0 on success (though this program runs indefinitely).
 */
int main() {
    // For Pico W devices we need to initialise the driver etc
    int rc = cyw43_arch_init();
    // Check if the initialisation worked, otherwise programm stops here
    hard_assert(rc == PICO_OK);

    // Define a blink delay
    uint32_t blink_delay_ms = 100;

    while (true) {
        pico_set_led(true);
        sleep_ms(blink_delay_ms);
        pico_set_led(false);
        sleep_ms(blink_delay_ms);
    }
}
