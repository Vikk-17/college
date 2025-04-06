from sys import stdin
# Read input from standard input (stdin)
print("Enter your name")
name = stdin.readline().strip()
print("Enter the number")
n = int(stdin.readline())

# for loop
for i in range(0, n):
    print(f"{i+1}: {name}")

# while loop
i = 0
while(i<n):
    print(f"{i+1}: {name}")
    i += 1

