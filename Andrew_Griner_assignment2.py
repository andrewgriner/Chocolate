def calculate_chocolate_bars(dollars):
    # Initialize variables
    chocolate_bars = dollars
    coupons = chocolate_bars

    # Calculate the number of chocolate bars and leftover coupons
    while coupons >= 7:
        # Calculate additional chocolate bars that can be obtained with the coupons
        new_chocolate_bars = coupons // 7
        # Update the total chocolate bars count
        chocolate_bars += new_chocolate_bars
        # Calculate the leftover coupons after purchasing additional chocolate bars
        leftover_coupons = coupons % 7 + new_chocolate_bars
        # Update the coupon count with the leftover coupons
        coupons = leftover_coupons

    return chocolate_bars, leftover_coupons


def main():
    repeat = True

    while repeat:
        try:
            # Prompt the user for the amount they want to spend on chocolates
            dollars = float(input("How much would you like to spend on chocolates? "))
            # Validate the input
            if dollars < 0:
                print("Error: Please enter a non-negative number.")
                continue
            elif dollars != int(dollars):
                print("Error: Please input a whole number.")
                continue
        except ValueError:
            print("Error: Please enter a valid number.")
            continue

        # Calculate the number of chocolate bars and leftover coupons based on the user's input
        bars, coupons = calculate_chocolate_bars(int(dollars))

        # Display the result to the user
        print("You can buy", bars, "chocolates")
        print("You will have", coupons, "leftover coupons")

        while True:
            # Ask the user if they want to repeat the program
            choice = input("Would you like to use this program again? (y/n) ")
            if choice.lower() == 'y':
                break
            elif choice.lower() == 'n':
                print("Thank you! Have a great day!")
                repeat = False
                break
            else:
                print("Error: Invalid input. Please enter 'y' or 'n'.")


if __name__ == '__main__':
    main()
