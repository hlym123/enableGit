'''

	MicroPython Documentation
	
	@date: 2017.11.20

'''



'''
1.1 General board control 
'''
import pyb

pyb.repl_uart(pyb.UART(1, 9600))
pyb.wfi()
pyb.freq()
pyb.freq(60000000)
pyb.stop()


'''
1.2 Delay and timing
'''
import time

time.sleep(1)  		# sleep for 1 second
time.sleep_ms(500)
time.sleep_us(10)
start = time.ticks_ms()
delta = time.ticks_diff(time.ticks_ms() - start)


''' 
1.3 LED 
'''
from pyb import LED

led = LED(1)
led.toggle()
led.on()
led.of()


'''
1.4 Pins and GPIO
'''
from pyb import Pin

p_out = Pin('X1', Pin.OUT_PP)
p_out.high()
p_out.low()

p_in = Pin('X1', Pin.IN, Pin.PULL_UP)
p_in.value()  # get value, 0 or 1


'''
1.5 Servo control
'''
from pyb import Servo

s1.Servo(1)
s1.angle(45)
s1.angle(-60, 1500)  	# move to -60 degrees in 1500ms
s1.speed(50)			# for continuous rotation servos

'''
1.6 External interrupts
'''
from pyb import Pin, ExtInt

callback = lambda e: print("intr")
ext = ExtInt(Pin('Y1'), ExtInt.IRQ_RISING, Pin.PULL_NONE, callback)


'''
1.7 Timers
'''
from pyb import Timer

tim = Timer(1, freq=1000)
time.counter()	# get counter value
time.freq(0.5)	# 0.5Hz
time.callback(lambda t: pyb.LED(1).toggle())


'''
1.8 PWM
'''
from pyb import Pin, Timer

p = Pin('X1')
tim = Timer(2, freq=1000)
ch = Timer.channel(1, Timer.PWM, pin=p)
ch.pulse_width_percent(50)


'''
1.9 ADC
'''
from pyb import Pin, ADC

adc = ADC(Pin('X19'))
adc.read()	# read value, 0 - 4095


'''
1.10 DAC
'''
from pyb import Pin, DAC

dac = DAC(Pin('X5'))
dac.write(120)	# output between 0 and 255


'''
1.11 UART
'''
from pyb import UART

uart1 = UART(1, 9600)
uart1.write('hello')
uart1.read(5)  			# read up to 5 bytes 


'''
1.12 SPI Bus
'''
from pyb import SPI

spi1 = SPI(1, SPI.MASTER, baudrate=200000, polarity=1, phase=0)
spi1.send('hello')
spi1.recv(5)				# receive 5 bytes on the bus
spi1.sedn_recv('hello')		# send a receive 5 byrtes


'''
1.13 I2C Bus
'''
from pyb import I2C

i2c1 = I2C(1, I2C.MASTER, baudrate=100000)
i2c1.sacn()							# returns list of slave address
i2c1.send('hello', 0x42)			# send 5 bytes to slave with address ox42
i2c1.recv(5, 0x42)
i2c1.mem_read(2, 0x42, 0x10)		# read 2 bytes from slave 0x42, slave memory 0x10
i2c1.mem_write('xy', 0x42, 0x10)	# write 2 bytes to slave 0x42, slave memory 0x10

 










































