import time
from Lidar_Simulation import *
from PID_Control import *
from Serial_Communication import *

def main():
    CSV_FILE = os.path.join("Data", "lidar_data_dynamic.csv")
    lidar_data = load_lidar_data(CSV_FILE)
    #print(lidar_data)
    motor_pid, steering_pid = setup_pid()
    ser = setup_serial()
    
    while True:
        angle, distance = lidar_data
        motor_speed, steer_angle = process_lidar_data(angle, distance, motor_pid, steering_pid)
        
        send_command(ser, f"M=+{motor_speed}")
        send_command(ser, f"P=+{steer_angle}")
        
        time.sleep(0.1)

if __name__ == "__main__":
    try:
        main()
    except KeyboardInterrupt:
        print("Stopping...")