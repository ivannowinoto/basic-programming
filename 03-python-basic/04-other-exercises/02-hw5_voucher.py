# Week 5 Homework
# 黃偉智 B11107035

while True:

    num = list(input("Enter 10-digit mobile phone number: "))   # User input

    if len(num) != 10:      # Checking length of number from user input
        print("Invalid input, please enter a 10-digit number.")
        continue

    else:
        num[4:7] = ["*", "*", "*"]      # Changing the 4-6th digit of number to *
        print("Your phone number is:", "".join(num))    # Printing censored phone number

        if num[0:2] == ["0", "9"]:      # Checking whether number starts with '09'
            lastDigit = "".join(num[7:10])
            print("The last 3 digits of your phone number:", lastDigit) # Printing last 3 digits of number

            list(lastDigit)
            if set(lastDigit) & set(["2", "8"]):    # Checking whether last 3 digits contain 2 or 8
                print("Congratulations! You got the 20% discount.")
            else:
                print("Sorry, you are not eligible for the 20% discount coupon.")

        else:
            print("Sorry, you are not eligible for the 20% discount coupon.")

    cont = input("Do you want to check another phone number? (Y/N): ")  # Continuing the program if the user wants
    if cont.upper() == "N":
        break