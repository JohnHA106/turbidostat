this project is intended for use to build a low cost arduino controlled turbidostat for biotech work

It uses:
Arduino Uno R3 (mine is made by Elegoo)
DF Robot turbidity meter
4 channel relay (but only one is in use so you could use a 1 channel if you wanted)
LED
220 ohm resistor
12 V DC motor

You must also have PLX-DAQ installed and connected to the arduino if you want to record and store data in excel
Do not open the serial monitor or plotter if you are doing this

Code for PLX-DAQ integration is modified from https://www.instructables.com/id/Sending-data-from-Arduino-to-Excel-and-plotting-it/
Code for sensor readings comes from DF Robot https://wiki.dfrobot.com/Turbidity_sensor_SKU__SEN0189