"""
Design a Python function that reads a dataset containing log files with various entries such as error messages, warnings, and timestamps.␍Use regular expressions to extract:
- Number of "ERROR" entries
- Timestamps of all "CRITICAL" entries
- Count of each type of log entry.
Ensure the program handles file exceptions and prints insights that can help an admin make informed decisions.
"""

import re

def analyze_log_file(filename):
    rexp_types = r"[A-Z]{4,8}" 
    rexp_time = r"(\d{4}-\d{1,2}-\d{1,2} \d{1,2}:\d{1,2}:\d{1,2})"
    
    ce = 0
    cc = 0
    ci = 0
    cw = 0
    cd = 0
    critical_timestamps = []
    
    try:
        with open(filename, "r") as file:
            for line in file:
                line = line.strip()
                
                # Check log type
                type_match = re.search(rexp_types, line)
                if type_match:
                    log_type = type_match.group(0)
                    if log_type == "ERROR":
                        ce += 1
                    elif log_type == "CRITICAL":
                        cc += 1
                        # Also get timestamp for CRITICAL entries
                        time_match = re.search(rexp_time, line)
                        if time_match:
                            critical_timestamps.append(time_match.group(0))
                    elif log_type == "INFO":
                        ci += 1
                    elif log_type == "WARNING":
                        cw += 1
                    elif log_type == "DEBUG":
                        cd += 1
        
        log_count = {
            "ERROR Count": ce,
            "CRITICAL Count": cc,
            "INFO Count": ci,
            "DEBUG Count": cd,
            "WARNING Count": cw,
        }
        
        return log_count, critical_timestamps
    
    except FileNotFoundError:
        print(f"Error: File '{filename}' not found.")
        return None, None
    except Exception as e:
        print(f"An error occurred: {str(e)}")
        return None, None

def main():
    try:
        log_counts, critical_times = analyze_log_file("log_dataset.csv")
        
        if log_counts and critical_times is not None:
            print("Log Entry Counts:")
            for log_type, count in log_counts.items():
                print(f"- {log_type}: {count}")
            
            print("\nCRITICAL Timestamps:")
            if critical_times:
                for timestamp in critical_times:
                    print(f"- {timestamp}")
            else:
                print("No CRITICAL events found.")
                
            if log_counts["ERROR Count"] > 0 or log_counts["CRITICAL Count"] > 0:
                print("\nALERT: System has errors or critical events that require attention!")
            
    except Exception as e:
        print(f"Error in main function: {str(e)}")

if __name__ == "__main__":
    main()
