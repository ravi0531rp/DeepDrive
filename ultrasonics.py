import RPi.GPIO as GPIO
import time
import signal
import sys
GPIO.setwarnings(False)
# use Raspberry Pi board pin numbers
GPIO.setmode(GPIO.BCM)

# set GPIO Pins
pinTrigger = 18
pinTrigger2 = 21

pinEcho = 24
pinEcho2=13
def close(signal, frame):
	print("\nTurning off ultrasonic distance detection...\n")
	GPIO.cleanup() 
	sys.exit(0)

signal.signal(signal.SIGINT, close)

# set GPIO input and output channels
GPIO.setup(pinTrigger, GPIO.OUT)
GPIO.setup(pinTrigger2, GPIO.OUT)

GPIO.setup(pinEcho, GPIO.IN)
GPIO.setup(pinEcho2, GPIO.IN)

while True:
        #  sens 1
	# set Trigger1 to HIGH
	GPIO.output(pinTrigger, True)
	# set Trigger after 0.01ms to LOW
	time.sleep(0.00001)
	GPIO.output(pinTrigger, False)

	startTime = time.time()
	stopTime = time.time()
        
        
	# save start time
	while 0 == GPIO.input(pinEcho):
		startTime = time.time()
	

	# save time of arrival
	while 1 == GPIO.input(pinEcho):
		stopTime = time.time()

	# sens 2	
	# set Trigger to HIGH
	GPIO.output(pinTrigger2, True)
	# set Trigger after 0.01ms to LOW
	time.sleep(0.00001)
	GPIO.output(pinTrigger2, False)
		
	startTime2=time.time()
	stopTime2 = time.time()
	

	while 0 == GPIO.input(pinEcho2):
		startTime2 = time.time()

	while 1 == GPIO.input(pinEcho2):
		stopTime2 = time.time()

	# time difference between start and arrival
	TimeElapsed = stopTime - startTime
	Ti=stopTime2-startTime2
	# multiply with the sonic speed (34300 cm/s)
	# and divide by 2, because there and back
	distance = (TimeElapsed * 34300) / 2
	distance2 = (Ti * 34300) / 2

	print ("Distance: %.1f cm" % distance)
	print ("Distance2: %.1f cm" % distance2)
	print ("------------------" )
	time.sleep(1)
