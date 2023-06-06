#include "peripherals/registers.h"
#include "general.h"

static inline void delay(i32);


static inline void put32(u32 reg, i32 data) {
    *(volatile u32*)reg = data;
}

static u32 get32(u32 reg) {
    return *(volatile u32*) reg;
}

void uart_send (char c) {
	// Wait for UART to become ready to transmit.
	while ( get32(UART0_FR) & (1 << 5) ) { }
	put32(UART0_DR, c);
	
}

char uart_recv(void) {
	// Wait for UART to have received something.
    while ( get32(UART0_FR) & (1 << 4) ) { }
    return get32(UART0_DR);
	
}

void uart_send_string(char* str) {
	for (int i = 0; str[i] != '\0'; i ++) {
		uart_send((char)str[i]);
	}
}

void uart_init ( void )
{
	u32 selector;

	selector = get32(GPIO_FSEL1);
	selector &= ~(7<<12);                   // clean gpio14
	selector |= 2<<12;                      // set alt5 for gpio14
	selector &= ~(7<<15);                   // clean gpio15
	selector |= 2<<15;                      // set alt5 for gpio15
	put32(GPIO_FSEL1, selector);

	put32(GPIO_PUD,0);
	delay(150);
	put32(GPIO_PUDCLK0, (1<<14)|(1<<15));
	delay(150);
	put32(GPIO_PUDCLK0, 0);

	put32(AUX_ENABLES,1);                   // Enable mini uart (this also enables access to its registers)
	put32(AUX_MU_CNTL_REG, 0);               // Disable auto flow control and disable receiver and transmitter (for now)
	put32(AUX_MU_IER_REG, 0);                // Disable receive and transmit interrupts
	put32(AUX_MU_LCR_REG, 3);                // Enable 8 bit mode
	put32(AUX_MU_MCR_REG, 0);                // Set RTS line to be always high
	put32(AUX_MU_BAUD_REG, 270);             // Set baud rate to 115200

	put32(AUX_MU_CNTL_REG,3);               // Finally, enable transmitter and receiver
}

static inline void delay(i32 count) {
    asm volatile("__delay_%=: subs %[count], %[count], #1; bne __delay_%=\n"
			: "=r"(count): [count]"0"(count): "cc");
}
