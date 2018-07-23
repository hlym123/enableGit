/**********************************************************************************************

**********************************************************************************************/



// File -> 使用编程器上传   无需启动引导，可直接烧录应用程序

/*
arduino在编译、链接、下载之后，hex文件自动删除了，造成软件仿真（如用proteus仿真）及其他单片机板应用的不便。
	Hex文件的提取: 
	1： 在arduino工具的File->preferences中找到preferences.txt文件。 
	2：用记事本打开preferences.txt,选择hex文件存放的路径，在最后行加入    build.path=d:\arduino\MyHexDir,    
	3：关闭arduino。 
	4：关闭preferences.txt ，关闭时对话框显示是否保存，选择保存。 Note：1：hex文件存放的路径可以由自己来定。
*/


/*
Bootloader local

...\arduino-1.6.5\hardware\arduino\avr\bootloaders\optiboot

*/



/*
 Arduino内存优化
#include <avr/pgmspace.h> 
const data_type my_array[] PROGMEM = 
*/








/**********************************************************************************************
	Arduino language reference
	
	https://www.arduino.cc/reference/en/#functions
	
	
	1. Functions
	2. Veriables
	3. Structure
**********************************************************************************************/


 
// 1. Functions

// Digital I/O ============================================================
digitalRead() 
digitalWrite() 
pinMode() 


/**
 * Reads the value from a specified digital pin, either HIGH or LOW.
 * @pin: the number of the digital pin you want to read
 * @return: HIGH or LOW
 */
digitalRead(pin); 

/**
 * Write a HIGH or a LOW value to a digital pin.
 * @pin: the pin number
 * @value: HIGH or LOW
 */
digitalWrite(pin, value);

/**
 * Configures the specified pin to behave either as an input or an output.
 * @pin: the number of the pin whose mode you wish to set
 * @mode: INPUT, OUTPUT, or INPUT_PULLUP. 
 */
pinMode(pin, mode);



// Analog I/O ============================================================
analogRead() 
analogReference() 
analogWrite() 




/**
 * Reads the value from the specified analog pin. 
 * @pin: the number of the analog input pin to read from.
 * @return: int(0 to 1023)
 */
analogRead(pin) 

// On most Arduino boards (those with the ATmega168 or ATmega328P), this function works on pins 3, 5, 6, 9, 10, and 11. 
/**
 * Writes an analog value (PWM wave) to a pin. 
 * @pin: the pin to write to. Allowed data types: int. 
 * @value: the duty cycle: between 0 (always off) and 255 (always on). Allowed data types: int
 */
analogWrite() 


 

// Zero, Due & MKR Family =================================================
analogReadResolution() 
analogWriteResolution() 

// Advanced I/O
tone() 
noTone() 
pulseIn() 
pulseInLong() 
shiftIn() 
shiftOut() 

// tone()
Generates a square wave of the specified frequency (and 50% duty cycle) on a pin.
A duration can be specified, otherwise the wave continues until a call to noTone(). 
The pin can be connected to a piezo buzzer or other speaker to play tones.
 
// Time
delay() 
delayMicroseconds() 
micros() 
millis() 



// Math
abs() 
constrain() 
map() 
max() 
min() 
pow() 
sq() 
sqrt() 

// Trigonometry
cos() 
sin() 
tan() 

// Characters
isAlpha() 
isAlphaNumeric() 
isAscii() 
isControl() 
isDigit() 
isGraph() 
isHexadecimalDigit() 
isLowerCase() 
isPrintable() 
isPunct() 
isSpace() 
isUpperCase() 
isWhitespace() 


// Random Numbers
random() 
randomSeed() 
Bits and Bytes
bit() 
bitClear() 
bitRead() 
bitSet() 
bitWrite() 
highByte() 
lowByte() 

// External Interrupts
attachInterrupt() 
detachInterrupt() 
Interrupts
interrupts() 
noInterrupts() 

// Communication
serial 
stream 

// USB
Keyboard 
Mouse 

































