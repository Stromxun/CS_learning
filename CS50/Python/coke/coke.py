amount = 50
while amount > 0:
    print('Amount Due: ' + str(amount))
    money = int(input('Insert Coin: '))
    if money not in [5, 10, 25]:
        continue
    amount -= money
print('Change Owed: ' + str(abs(amount)))
