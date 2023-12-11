s = input('camelCase: ')
for c in s:
    if c.isupper():
        print('_', end = '')
    print(c.lower(), end = "")
