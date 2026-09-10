void UART0_isr(void) __irq;
void InitUART0 (void);
void UART0_Tx(char ch);
char UART0_Rx(void);
void UART0_Str(char *s);
void UART0_Int(unsigned int n);
void UART0_Float(float f);
