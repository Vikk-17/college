# Get input from two switches and switch on corresponding leds.

import time
import RPi.GPIO as gpio

gpio.setwarnings(False)
gpio.setmode(gpio.BOARD)

led1 = 15
led2 = 13

swith1 = 37
swith2 = 35

gpio.setup(led1, gpio.OUT, initial=0)
gpio.setup(led2, gpio.OUT, initial=0)

gpio.setup(swith1, gpio.IN)
gpio.setup(swith2, gpio.IN)


def glow_led(event):
    if event == swith1:
        gpio.output(led1, True)
        time.sleep(3)
        gpio.output(led1, False)
    elif event == swith2:
        gpio.output(led2, True)
        time.sleep(3)
        gpio.output(led2, False)

gpio.add_event_detect(swith1, gpio.RISING, callback=glow_led, bouncetime=1)
gpio.add_event_detect(swith2, gpio.RISING, callback=glow_led, bouncetime=1)

try:
    while(True):
        time.sleep(1)
except KeyboardInterrupt:
    gpio.cleanup()
