from simple_pid import PID

def setup_pid():
    motor_pid = PID(1.0, 0.1, 0.05, setpoint=1000) 
    steering_pid = PID(1.0, 0.1, 0.05, setpoint=90)
    return motor_pid, steering_pid

def process_lidar_data(angle, distance, motor_pid, steering_pid):
    motor_speed = int(motor_pid(distance))
    steer_angle = int(steering_pid(angle))
    return motor_speed, steer_angle

if __name__ == "__main__":
    motor_pid, steering_pid = setup_pid()
    print(process_lidar_data(45, 1200, motor_pid, steering_pid))