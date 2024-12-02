def dual_to_decimal_potenzmethode(dual_str):
    decimal_value = 0
    power = 0
    
    # Gehe durch die Binärzahl von rechts nach links
    for digit in reversed(dual_str):
        if digit == '1':
            decimal_value += 2 ** power  # Addiere die Potenz von 2, wenn die Ziffer 1 ist
        power += 1

    return decimal_value

print(dual_to_decimal_potenzmethode("1010111"))

def dual_to_decimal_horner(dual_str):
    decimal_value = 0

    # Gehe durch die Binärzahl von links nach rechts
    for digit in dual_str:
        decimal_value = decimal_value * 2 + int(digit)  # Horner-Schema

    return decimal_value

print(dual_to_decimal_horner("1010111"))