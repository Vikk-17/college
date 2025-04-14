# Flash on LED at a given on time and off time cycle where the two times are taken from a file

import time
import RPi.GPIO as gpio

gpio.setwarnings(False)
gpio.setmode(gpio.BOARD)

led1 = 15
gpio.setup(led1, gpio.OUT, initial=0)

fhandler = open("led_intervals.txt", "r")
lines = fhandler.readlines()
ON_TIME = int(lines[0].split("=")[1])
OFF_TIME = int(lines[1].split("=")[1])

try:
    while(True):
        gpio.output(led1, True)
        time.sleep(ON_TIME)
        gpio.output(led1, False)
        time.sleep(OFF_TIME)

except KeyboardInterrupt:
    gpio.cleanup()
