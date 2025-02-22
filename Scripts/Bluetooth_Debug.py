import serial
import time
import os
import sys

# Set the encoding to UTF-8
os.environ['PYTHONIOENCODING'] = 'utf-8'
sys.stdout.reconfigure(encoding='utf-8')

PORT = "COM25" #25
BAUD_RATE = 38400 # default for DST TECH RABA

""" Establish serial connection. """
def connect_serial(port, baud_rate):
    try:
        ser = serial.Serial(port, baud_rate, timeout=1)
        print(f"Connected to {port} at {baud_rate} baud.")
        time.sleep(2)  # Allow time for connection to establish
        return ser
    except Exception as e:
        print("Error opening serial port:", e)
        return None

""" Main function to initiate serial communication and read data. """
def main():
    ser = connect_serial(PORT, BAUD_RATE)
    
    if not ser:
        print("Failed to connect to serial port. Exiting...")
        return  # Exit if no serial connection
    
    print("Waiting for data...\n")

    try:
        while True:
            data = ser.readline().decode('utf-8', errors='replace').strip()
            if data:
                print("Data:", data)
    except KeyboardInterrupt:
        print("\nExiting...")
    finally:
        ser.close()
        print("Serial connection closed.")

if __name__ == "__main__":
    main()