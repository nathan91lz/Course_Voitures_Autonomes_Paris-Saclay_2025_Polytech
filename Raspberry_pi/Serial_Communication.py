import serial

def setup_serial(port="/dev/ttyUSB0", baud_rate=115200):
    return serial.Serial(port, baud_rate, timeout=1)

def send_command(ser, command):
    ser.write((command + "\n").encode())
    print("Sent:", command)

if __name__ == "__main__":
    ser = setup_serial()
    send_command(ser, "M=+100")