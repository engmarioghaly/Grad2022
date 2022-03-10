import serial
import webbrowser

ser = serial.Serial("COM5", 9600)
while True:
        data = ser.read()
        if data == b'1':
            webbrowser.open("www.google.com")