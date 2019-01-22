'''

	OpenMV 
	
	@date: 2018.05.10

'''


# Quick reference for the openmvcam

'''
 1.1 General board control 
'''
import pyb

pyb.repl_uart(pyb.UART(3, 9600, timeout_char=1000)) # duplicate REPL on UART(3)
pyb.wfi() # pause CPU, waiting for interrupt
pyb.stop() # stop CPU, waiting for external interrupt


'''
 1.2 Delay and timing
'''



'''
	图像处理背景知识
'''

# ref: http://book.openmv.cc/
# https://blog.csdn.net/HZ_CloudRiver/article/details/78177307?locationNum=6&fps=1#t1 