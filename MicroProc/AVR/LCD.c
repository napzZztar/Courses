// ----------- LCD PIN DEFINITION ----------------
#define RS 0 // Register Select = PC0
#define RW 1 // Read/write = PC1
#define En 2 // Enable = PC2
#define LCD_DATA_PORT PORTD // LCD Data Port (D7-D0) = PORTD
#define LCD_DATA_PORT_DDR DDRD // DATA Port direction Register = DDRD
#define LCD_CONTROL_PORT PORTC // Control Port (RS, RW, En) = PORTC
#define LCD_CONTROL_PORT_DDR DDRC // Control Port direction Register = PORTC
// --------- SEND COMMAND TO LCD -------------------------
void send_command(unsigned char command)
{
 // The command we want to send is placed on the data port PD7-PD0
 LCD_DATA_PORT = command; // Send Command
 // set RS = 0: Indicates sending COMMAND
 LCD_CONTROL_PORT &= ~(1<<RS);
 // set R/W = 1: Indicates we will write command to LCD
 LCD_CONTROL_PORT &= ~(1<<RW);
 // the command will be activated after a High-to-Low signal is sent at En pin
 LCD_CONTROL_PORT |= 1<<En; // En = 1 (High)
 Delay_us(1); // wait a while
 LCD_CONTROL_PORT &= ~(1<<En); // En = 0 (Low)
 Delay_us(100); // wait a while
}
// --------- WRITE DATA TO LCD -------------------------
void send_data(unsigned char dat)
{
 // the data we want to send is placed on the data port PD7-PD0
 LCD_DATA_PORT = dat; // Send data
 // RS = 1 for sending DATA
 LCD_CONTROL_PORT |= 1<<RS;

 // set R/W = 1, Indicating we will WRITE
 LCD_CONTROL_PORT &= ~(1<<RW);
 // the data will be visible on LCD after a High-to-Low signal is sent at En pin
 LCD_CONTROL_PORT |= 1<<En; // En = 1
 Delay_us(1); // wait a while
 LCD_CONTROL_PORT &= ~(1<<En); // En = 0
 Delay_us(100); // wait a while
}
void main( )
{
 // ------------ INITIALIZE THE LCD --------------------------------------
 LCD_CONTROL_PORT_DDR = 0xFF; // Set PORTC in output mode
 LCD_DATA_PORT_DDR = 0xFF; // Set PORTD in output mode
 Delay_us(2000); // Wait for LCD to initialize
 send_command(0x38) ; // Initialize LCD: 2 lines, 5x7 matrix
 send_command(0x0E); // Display on, cursor on
 send_command(0x01); // Clear LCD screen
 Delay_us(2000) ; // Wait for a while
 send_command(0x06) ; // Shift cursor right
 // Write „AIUB? on LCD only once
 send_data('A');
 send_data('I');
 send_data('U');
 send_data('B');
 while(1)
 {
 // Nothing is done repeatedly here
 }
}
