import serial
import time
import os
import sys
import threading

# Set the encoding to UTF-8
os.environ['PYTHONIOENCODING'] = 'utf-8'
sys.stdout.reconfigure(encoding='utf-8')

PORT = "COM25" # 25
BAUD_RATE = 38400  # Default for DST TECH RABA

# Establish serial connection
def connect_serial(port, baud_rate):
    try:
        ser = serial.Serial(port, baud_rate, timeout=1)
        print(f"Connected to {port} at {baud_rate} baud.")
        time.sleep(2)  # Allow time for connection to establish
        return ser
    except Exception as e:
        print("Error opening serial port:", e)
        return None

# Function to listen for incoming data from Arduino
def listen_serial(ser):
    print("Listening for sensor data...\n")
    while True:
        try:
            data = ser.readline().decode('ascii', errors='ignore').strip()
            if data:
                print(f"[Arduino] {data}") 
        except Exception as e:
            print("Error reading serial data:", e)

# Function to send commands to Arduino
def send_commands(ser):
    print("\nSend commands, q=quit")
    while True:
        try:
            cmd = input("Command: ").strip().lower()
            if cmd == "q":
                print("Exiting command mode...")
                break
            elif cmd:
                # Ensure the command ends with \r\n for Arduino
                ser.write((cmd + '\r\n').encode())
                print(f"Sent: {cmd}")
        except KeyboardInterrupt:
            print("\nKeyboard interrupt detected. Exiting command mode.")
            break
        except Exception as e:
            print(f"Error sending command: {e}")
        

# Main function
def main():
    ser = connect_serial(PORT, BAUD_RATE)
    if not ser:
        print("Failed to connect to serial port. Exiting...")
        return

    # Start listening for data in a separate thread
    listener_thread = threading.Thread(target=listen_serial, args=(ser,), daemon=True)
    listener_thread.start()

    # Start sending commands
    send_commands(ser)

    ser.close()
    print("Serial connection closed.")

if __name__ == "__main__":
    main()
