expression = input('Expression: ')
x, y, z = expression.split(" ")
x, z = float(x), float(z)
if y == '+':
    print(x + z)
elif y == '-':
    print(x - z)
elif y == '*':
    print(x * z)
else:
    print(x / z)
