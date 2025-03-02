import numpy as np
import time
import os

def sort_and_save(input_file, output_file):
    with open(input_file, "r") as filein:
        n = int(filein.readline().strip())  # Đọc số lượng phần tử
        data = np.array(list(map(float, filein.read().split())))
    
    # Đo thời gian chỉ cho quá trình sắp xếp
    start_time = time.time()
    data.sort()  # Sắp xếp mảng tại chỗ
    end_time = time.time()
    
    execution_time = (end_time - start_time) * 1000  # Đổi sang milliseconds
    
    # Ghi dữ liệu đã sắp xếp vào file output
    with open(output_file, "w") as fileout:
        fileout.write(f"{n}\n")
        fileout.write(f"{execution_time:.2f} ms\n")
        fileout.write(" ".join(f"{num:.6f}" for num in data))
    
    return execution_time

# Danh sách các tệp dữ liệu
num_files = 10
execution_times = {}

for i in range(1, num_files + 1):
    input_filename = f"Test{i}.inp"
    output_filename = f"Test{i}.out"

    if os.path.exists(input_filename):
        exec_time = sort_and_save(input_filename, output_filename)
        execution_times[i] = exec_time
        print(f"Test {i}: {exec_time:.2f} ms")
    else:
        print(f"File {input_filename} not found!")

# Ghi lại thời gian thực thi vào file log
with open("execution_times.log", "w") as log_file:
    for test_num, time_taken in execution_times.items():
        log_file.write(f"Test {test_num}: {time_taken:.2f} ms\n")

print("Execution times recorded in execution_times.log")
