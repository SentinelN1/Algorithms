import math

input_string = input()

left_bracket = input_string[0]
right_bracket = input_string[-1]

left_string, right_string = input_string[1:-1].split(", ")

left_numbers = left_string.split("/")
right_numbers = right_string.split("/")

if (len(left_numbers) == 1):
    left_num = left_numbers[0]
    left_den = 1
else:
    left_num = left_numbers[0]
    left_den = left_numbers[1]

if (len(right_numbers) == 1):
    right_num = right_numbers[0]
    right_den = 1
else:
    right_num = right_numbers[0]
    right_den = right_numbers[1]

left_number = int(left_num) / int(left_den)
right_number = int(right_num) / int(right_den)


l_int = math.ceil(left_number)
r_int = math.floor(right_number)

res = r_int - l_int + 1

if (l_int == left_number and left_bracket == '('):
    res -= 1

if (r_int == right_number and right_bracket == ')'):
    res -= 1

print(max(0, res))
