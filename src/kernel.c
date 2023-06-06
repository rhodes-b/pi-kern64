#include "general.h"
#include "mini_uart.h"
#include <stdint.h>

void kernel_main(u32 r0, u32 r1, u32 atags) {
	
	uart_init();
	uart_send_string("Hello, Kernel!\n");

	while (1) {
		uart_send(uart_recv());
	}
}