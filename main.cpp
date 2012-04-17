/* ChibiOS/RT “Hello, World” program for the STM32VLDISCOVERY board.

   Verified on ChibiOS/RT 2.3.4.
   Connect PC serial adapter's RX-I to PA9; TX-O to PA10.

   By Colin D Bennett <colin@gibibit.com>, 16 Dec 2011.
   Converted to C++, 11 Jan 2012 -CDB.
*/

#include <ch.h>
#include <hal.h>


namespace  // Begin anonymous namespace
{

// Private function declarations
void start_serial_thread();
void print(const char * s);
void println(const char * s);

// Configuration constants
const SerialConfig sd1_config =
{
    // SerialConfig for STM32 platforms
    115200,     // bit rate
    0,          // CR1 register settings
    0,          // CR2 register settings
    0,          // CR3 register settings
};

}  // End anonymous namespace


// Function definitions

int main(void)
{
    /* Device driver and board-specific initialization. */
    halInit();

    /* Kernel initialization. The main() function becomes a thread. */
    chSysInit();

    /* Activate serial driver 1 using the driver default configuration. */
    sdStart(&SD1, &sd1_config);

    /* Print greeting to the serial port. */
    println("-= ChibiOS/RT C++ Hello World for STM32VLDISCOVERY =-");
    println("Press SPACE on serial terminal, or press USER button.");

    /* Start the thread that prints “Hello, World!” */
    start_serial_thread();

    /* Normal main() thread activity. */
    while (1)
    {
        if (palReadPad(GPIOA, GPIOA_BUTTON))
            palSetPad(GPIOC, GPIOC_LED3);
        else
            palClearPad(GPIOC, GPIOC_LED3);

        chThdSleepMilliseconds(50);
    }
}


namespace  // Begin anonymous namespace
{

// Serial thread
// Prints “Hello, World!” to the serial port 1 (ChibiOS/RT's SD1 device)
// every time the SPACE character is received on the serial port.

WORKING_AREA(wa_serial_hello_thread, 256);

msg_t serial_hello_thread(void * arg) __attribute__((noreturn));
msg_t serial_hello_thread(void * arg)
{
    (void) arg; // Unused parameter
    while (1)
    {
        char c = (char) chIOGet(&SD1);
        if (c == ' ')
            println("Hello, C++ World!");
        // Ignore all other characters.
    }
}

void start_serial_thread()
{
    chThdCreateStatic(wa_serial_hello_thread,
                      sizeof(wa_serial_hello_thread),
                      NORMALPRIO,
                      serial_hello_thread,
                      NULL);
}


// Utility functions
void print(const char * s)
{
    while (*s)
    {
        chIOPut(&SD1, *(s++));
    }
}

void println(const char * s)
{
    print(s);
    print("\r\n");
}

}  // End anonymous namespace


