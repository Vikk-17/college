import time
import RPi.GPIO as gpio

gpio.setwarnings(False)
gpio.setmode(gpio.BOARD)
relay = 38
gpio.setup(relay, gpio.OUT, initial=0)

try:
    gpio.output(relay, True)
    print("Relay is switched on, Please press ctrl +c to exit")
    time.sleep(15)
    print("Relay is switched off")
    gpio.output(relay, False)

except KeyboardInterrupt:
    gpio.cleanup()
    print("Program exited")
