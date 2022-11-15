#inspiration from :
# https://www.instructables.com/Water-Salinity-meter/

#reading AC current on rpi eg:
# https://projects.raspberrypi.org/en/projects/physical-computing/13

#TODO: reading temperature depends on what sensor we are using for reading it
#afaik, temperature will give us a correction factor
# we will do r=r*(correction factor)^(temperature diff from calibration temp)

import RPi.GPIO as GPIO 
#possibly the library for one wire (which helps with the temperature sensor?)
#import OneWire 

#we will need this module since rpi does not have AC current reader
from gpiozero import MCP3008    

from time import sleep
#GPIO.setmode(GPIO.BOARD)
#pin setup:
acVoltagePin = MCP3008(0)
leftProbe=3
rightProbe=5

#GPIO setup:
GPIO.setwarnings(False)     	#disable warnings
#set pin numbering format
GPIO.setup(leftProbe, GPIO.OUT) #set GPIO as output
GPIO.setup(rightProbe, GPIO.OUT)    	#set GPIO as output

#other params used:
#AC milisecond delay
delaySeconds=0.5

#initial input voltage
Vin=3.3
Vout=0

#number of samples to take to get an avg resistance
samples=10

#value in ohms, of R1,R2:
R1=39
R2=0

buff=0
avg=0



# we will generate an ac current using pwm and then calculate the resistance
# by reading the voltage in the ac input pin

while True:
	tot=0
	for i in range(samples):
    	#generate PWM
		GPIO.output(leftProbe,GPIO.LOW)
		GPIO.output(rightProbe,GPIO.HIGH)
		sleep(delaySeconds)
		GPIO.output(leftProbe,GPIO.HIGH)
		GPIO.output(rightProbe,GPIO.LOW)
		sleep(delaySeconds)

    	#read the voltage on the analog pin, pot() gives a value b/w 0,1
		Vout=acVoltagePin.value*Vin
		buff=(Vin/Vout)-1
		R2=R1*buff
		tot=tot+R2
		print("hello")
	avg=tot/samples
	print("Average resistance is "+str(avg))
