import csv
import os

def load_lidar_data(csv_file):
    with open(csv_file, newline='') as csvfile:
        reader = csv.reader(csvfile)
        next(reader)
        return [(float(row[0]), float(row[1])) for row in reader]


if __name__ == "__main__":
    CSV_FILE = os.path.join("Data", "lidar_data_dynamic.csv")
    lidar_data = load_lidar_data(CSV_FILE)
    print(lidar_data)
