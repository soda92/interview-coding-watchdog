import subprocess
import time

process_names = ["processA", "processB"]

while True:
    for process_name in process_names:
        out = ""
        try:
            out = subprocess.check_output(f"ps -fC {process_name}|grep {process_name}", shell=True).decode()
        except subprocess.CalledProcessError:
            out = ""
        if process_name in out:
            print(f"{process_name} is running")
        else:
            print(f"{process_name} stopped")

    time.sleep(1)
