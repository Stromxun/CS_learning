#!/usr/bin/env python

import sys
import os

PHONEBOOK_ENTRIES = "python_phonebook_entries"


def main():
    if len(sys.argv) < 2:
        exit(1)

    elif sys.argv[1] == "new":
        # YOUR CODE HERE #
        with open(PHONEBOOK_ENTRIES, 'a', encoding='utf-8') as f:
            f.write(sys.argv[2] + ' ' + sys.argv[3] + '\n')

    elif sys.argv[1] == "list":
        if not os.path.isfile(PHONEBOOK_ENTRIES) or os.path.getsize(
                PHONEBOOK_ENTRIES) == 0:
            print("phonebook is empty")
        else:
            # YOUR CODE HERE #
            with open(PHONEBOOK_ENTRIES, 'r', encoding='utf-8') as f:
                for s in f:
                    print(s, end="")

    elif sys.argv[1] == "lookup":
        # YOUR CODE HERE #
        with open(PHONEBOOK_ENTRIES, 'r', encoding='utf-8') as f:
            for s in f:
                if sys.argv[2] in s:
                    print(s.replace(sys.argv[2] + ' ', ''), end="")

    elif sys.argv[1] == "remove":
        name = " ".join(sys.argv[2:])
        # YOUR CODE HERE #
        with open(PHONEBOOK_ENTRIES, 'r', encoding='utf-8') as f:
            list_file = list(f)
            
        with open(PHONEBOOK_ENTRIES, 'w', encoding='utf-8') as f:
            for s in list_file:
                if sys.argv[2] not in s:
                    f.write(s)
            
    elif sys.argv[1] == "clear":
        # YOUR CODE HERE #
        with open(PHONEBOOK_ENTRIES, 'w', encoding='utf-8'):
            pass
    else:
        name = " ".join(sys.argv[1:])
        with open(PHONEBOOK_ENTRIES, 'r') as f:
            lookup = "".join(filter(lambda line: name in line, f.readlines()))
            # YOUR CODE HERE #
            print(lookup, end="")

if __name__ == "__main__":
    main()
