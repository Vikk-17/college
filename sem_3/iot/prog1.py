def print_name():
    name = input("Enter your name: ")
    print(f"Hello, {name}")


def arithmatic():
    a = int(input("Enter the first number: "))
    b = int(input("Enter the second number: "))
    
    print(f"Addition: {a+b}\nDifference: {a-b}\nProduct: {a*b}\nDivision: {a/b}")


def char_word_count():
    string = input("Enter a sentence: ")
    # print(f"Total characters: {len(string)}")
    count = 0
    words_list = string.split(" ")
    print(f"Total words: {len(words_list)}")
    for c in string.strip():
        if(c != " "):
            count += 1
    print(f"Total number of characters: {count}")


def area():
    print("1. Rectangle\n2. Triangle\n3. Circle\n")
    try:
        while(True):
            choice = int(input("Enter your choice: "))
            match choice:
                case 1:
                    height = int(input("Enter height: "))
                    width = int(input("Enter width: "))
                    print(f"Area of Rectangle: {height * width}")
                    continue
                case 2:
                    base = int(input("Enter base: "))
                    height = int(input("Enter height: "))
                    print(f"Area of Triangle: {0.5 * base * height}")
                    continue
                case 3:
                    radius = int(input("Enter radius: "))
                    print(f"Area of Circle: {3.14 * radius * radius}")
                    continue
    except (KeyboardInterrupt, EOFError):
        print("Has been cancelled by the user")

def main():
    area()

if __name__ == "__main__":
    main()
