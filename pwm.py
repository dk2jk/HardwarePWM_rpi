#!/usr/bin/env python
#-*- coding: utf-8 -*-

import pigpio
import sys
import time

pin0 = 18
pin1 = 19

pi = pigpio.pi()
pi.set_mode(pin0,pigpio.OUTPUT)
pi.set_mode(pin1,pigpio.OUTPUT)

print "Hardware PWM for Raspberry Pi"
print "Please set the frequency of GPIO18.[0-125000000]"
pin0freq = input('>> ')

print "Please set the duty of GPIO18.[0-1000000]"
pin0duty = input('>> ')

print "Please set the frequency of GPIO19.[0-125000000]"
pin1freq = input('>> ')

print "Please set the duty of GPIO19.[0-1000000]"
pin1duty = input('>> ')

print 'GPIO18:','freq:'+str(pin0freq)+'Hz','duty:'+str(pin0duty)+':'+str((float(pin0duty)/1000000)*100)+'%'
print 'GPIO19:','freq:'+str(pin1freq)+'Hz','duty:'+str(pin1duty)+':'+str((float(pin1duty)/1000000)*100)+'%'

print "--Outputting--"
pi.hardware_PWM(pin0,pin0freq,pin0duty)
pi.hardware_PWM(pin1,pin1freq,pin1duty)

time.sleep(10)

print "--END--"
pi.set_mode(pin0,pigpio.INPUT)
pi.set_mode(pin1,pigpio.INPUT)
pi.stop()
