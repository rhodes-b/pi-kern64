#include "peripherals/registers.h"
#include "general.h"

static inline void delay(i64);

static inline void put64(u64 reg, i64 data) {
    *(volatile u64*)reg = data;
}

static u64 get64(u64 reg) {
    return *(volatile u64*) reg;
}

void uart_send (char c) {
	// Wait for UART to become ready to transmit.
	while ( get64(UART0_FR) & (1 << 5) ) { }
	put64(UART0_DR, c);
	
}

char uart_recv(void) {
	// Wait for UART to have received something.
    while ( get64(UART0_FR) & (1 << 4) ) { }
    return get64(UART0_DR);
	
}

void uart_send_string(char* str) {
	for (int i = 0; str[i] != '\0'; i ++) {
		uart_send((char)str[i]);
	}
}

void uart_init ( void )
{
	u64 selector;
	selector = get64(GPIO_FSEL1);
	selector &= ~(7<<12);                    // clean gpio14
	selector |= 2<<12;                       // set alt5 for gpio14
	selector &= ~(7<<15);                    // clean gpio15
	selector |= 2<<15;                       // set alt5 for gpio15
	put64(GPIO_FSEL1, selector);

	put64(GPIO_PUD,0);
	delay(150);
	put64(GPIO_PUDCLK0, (1<<14)|(1<<15));
	delay(150);
	put64(GPIO_PUDCLK0, 0);

	put64(AUX_ENABLES,1);                    // Enable mini uart (this also enables access to its registers)
	put64(AUX_MU_CNTL_REG, 0);               // Disable auto flow control and disable receiver and transmitter (for now)
	put64(AUX_MU_IER_REG, 0);                // Disable receive and transmit interrupts
	put64(AUX_MU_LCR_REG, 3);                // Enable 8 bit mode
	put64(AUX_MU_MCR_REG, 0);                // Set RTS line to be always high
	put64(AUX_MU_BAUD_REG, 270);             // Set baud rate to 115200

	put64(AUX_MU_CNTL_REG,3);                // Finally, enable transmitter and receiver
}

static inline void delay(i64 count) {
    asm volatile("__delay_%=: subs %[count], %[count], #1; bne __delay_%=\n"
			: "=r"(count): [count]"0"(count): "cc");
}
