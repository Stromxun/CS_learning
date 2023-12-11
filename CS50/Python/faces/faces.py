def convert(str):
    str = str.replace(':(', '🙁')
    str = str.replace(':)', '🙂')
    return str
str = convert(input())
print(str)
