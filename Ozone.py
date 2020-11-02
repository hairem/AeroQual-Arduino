#!/usr/bin/env python
# Log data from serial port


import argparse
import serial
import datetime
import time
import os


parser = argparse.ArgumentParser(formatter_class=argparse.ArgumentDefaultsHelpFormatter)
parser.add_argument("-d", "--device", help="device to read from", default="/dev/ttyUSB0")
parser.add_argument("-s", "--speed", help="speed in bps", default=9600, type=int)
args = parser.parse_args()

outputFilePath = os.path.join(os.path.dirname(__file__),
                 datetime.datetime.now().strftime("%Y-%m-%d") + ".csv")

with serial.Serial(args.device, args.speed) as ser, open(outputFilePath,'a+') as outputFile:
    print("Logging started. Ctrl-C to stop.") 
    try:
        while True:
            x = (ser.read(ser.inWaiting())) 
            data = x.decode('UTF-8')
            if data !="":
                outputFile.write(time.strftime("%Y/%m/%d %H:%M ") + " " + data  )
                outputFile.flush()
                time.sleep(1)
                 
    except KeyboardInterrupt:
        print("Logging stopped")
