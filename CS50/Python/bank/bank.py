str = input('Greeting: ').lower()
if str.find('hello') != -1:
    print('$0')
elif str.find('h') == 0:
    print('$20')
else:
    print('$100')
