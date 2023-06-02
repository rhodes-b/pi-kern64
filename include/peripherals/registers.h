#ifndef	_P_REG_H
#define	_P_REG_H

// TODO, add base layout for pi 4

// base addr for registers on RASPI2/3
#define PBASE           0x3F000000
#define BUSALIAS        0xC0000000


//--------------------------------//
//            MAILBOX             //
//--------------------------------//
#define MAILBOX_BASE         (PBASE + 0xB880)
#define MAILBOX_READ0        (MAILBOX_BASE + 0x00)
#define MAILBOX_PEEK0        (MAILBOX_BASE + 0x10)
#define MAILBOX_SENDER0      (MAILBOX_BASE + 0x14)
#define MAILBOX_STATUS0      (MAILBOX_BASE + 0x18)
#define MAILBOX_CONFIG0      (MAILBOX_BASE + 0x1c)
#define MAILBOX_WRITE1       (MAILBOX_BASE + 0x20)
#define MAILBOX_PEEK1        (MAILBOX_BASE + 0x30)
#define MAILBOX_SENDER1      (MAILBOX_BASE + 0x34)
#define MAILBOX_STATUS1      (MAILBOX_BASE + 0x38)
#define MAILBOX_CONFIG1      (MAILBOX_BASE + 0x3c)



//--------------------------------//
//              GPIO              //
//--------------------------------//
#define GPIO_BASE        (PBASE + 0x200000)
// FUNCTION SELECTORS
#define GPIO_FSEL0       (GPIO_BASE + 0x00)
#define GPIO_FSEL1       (GPIO_BASE + 0x04)
#define GPIO_FSEL2       (GPIO_BASE + 0x08)
#define GPIO_FSEL3       (GPIO_BASE + 0x0C)
#define GPIO_FSEL4       (GPIO_BASE + 0x10)
#define GPIO_FSEL5       (GPIO_BASE + 0x14)
// SET & CLEAR PIN OUTPUT
#define GPIO_SET0        (GPIO_BASE + 0x1C)
#define GPIO_SET1        (GPIO_BASE + 0x20)
#define GPIO_CLR0        (GPIO_BASE + 0x28)
#define GPIO_CLR1        (GPIO_BASE + 0x2C)
// Controls actuation of pull up/down to ALL GPIO pins
#define GPIO_PUD         (GPIO_BASE + 0x94)
// Controls actuation of pull up/down for specific GPIO pin
#define GPIO_PUDCLK0     (GPIO_BASE + 0x98)
#define GPIO_PUDCLK1     (GPIO_BASE + 0x9C)

//--------------------------------//
//              UART              //
//--------------------------------//

#define UART0_BASE       (GPIO_BASE + 0x1000)

#define UART0_DR         (UART0_BASE + 0x00)
#define UART0_RSRECR     (UART0_BASE + 0x04)
#define UART0_FR         (UART0_BASE + 0x18)
#define UART0_ILPR       (UART0_BASE + 0x20)
#define UART0_IBRD       (UART0_BASE + 0x24)
#define UART0_FBRD       (UART0_BASE + 0x28)
#define UART0_LCRH       (UART0_BASE + 0x2C)
#define UART0_CR         (UART0_BASE + 0x30)
#define UART0_IFLS       (UART0_BASE + 0x34)
#define UART0_IMSC       (UART0_BASE + 0x38)
#define UART0_RIS        (UART0_BASE + 0x3C)
#define UART0_MIS        (UART0_BASE + 0x40)
#define UART0_ICR        (UART0_BASE + 0x44)
#define UART0_DMACR      (UART0_BASE + 0x48)
#define UART0_ITCR       (UART0_BASE + 0x80)
#define UART0_ITIP       (UART0_BASE + 0x84)
#define UART0_ITOP       (UART0_BASE + 0x88)
#define UART0_TDR        (UART0_BASE + 0x8C)

// UART1
#define AUX_BASE         (GPIO_BASE + 0x15000)

#define AUX_ENABLES      (AUX_BASE + 0x04)
#define AUX_MU_IO_REG    (AUX_BASE + 0x40)
#define AUX_MU_IER_REG   (AUX_BASE + 0x44)
#define AUX_MU_IIR_REG   (AUX_BASE + 0x48)
#define AUX_MU_LCR_REG   (AUX_BASE + 0x4C)
#define AUX_MU_MCR_REG   (AUX_BASE + 0x50)
#define AUX_MU_LSR_REG   (AUX_BASE + 0x54)
#define AUX_MU_MSR_REG   (AUX_BASE + 0x58)
#define AUX_MU_SCRATCH   (AUX_BASE + 0x5C)
#define AUX_MU_CNTL_REG  (AUX_BASE + 0x60)
#define AUX_MU_STAT_REG  (AUX_BASE + 0x64)
#define AUX_MU_BAUD_REG  (AUX_BASE + 0x68)

//--------------------------------//
//            TIMER               //
//--------------------------------//

#define TIMER_BASE       (PBASE + 0x3000)
#define TIMER_CS         (TIMER_BASE + 0x00)
#define TIMER_CLO        (TIMER_BASE + 0x04)
#define TIMER_CHI        (TIMER_BASE + 0x08)
#define TIMER_C0         (TIMER_BASE + 0x0C)
#define TIMER_C1         (TIMER_BASE + 0x10)
#define TIMER_C2         (TIMER_BASE + 0x14)
#define TIMER_C3         (TIMER_BASE + 0x18)

#endif  /*_P_REG_H */
