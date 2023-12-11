def main():
    str = input('What time is it? ')
    time = convert(str)
    if 7.0 <= time <= 8.0:
        print('breakfast time')
    if 12.0 <= time <= 13.0:
        print('lunch time')
    if 18.0 <= time <= 19.0:
        print('dinner time')

def convert(time):
    hours, minutes = time.split(":")
    return int(hours) + int(minutes) / 60


if __name__ == "__main__":
    main()
