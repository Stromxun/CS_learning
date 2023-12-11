### Lab 2 - Core Shell & Shell Scripting
Part 01 - vim
Try playing around with lab2.md while looking up some new commands. Use wget to download it!
Questions:
* How would you delete the previous 10 lines?
  ```vim
  gg # go to top of lab02.md
  10dd # delete the previous 10 lines
  ```
* How would you jump back to the shell without exiting `vim`?
  ```vim
  :! <command> # can call the shell command but not exit vim
  ```
* How would you edit a new file alongside another file?
  ```vim
  :open <new_file_name>
  :sp <last_file_name>
  ```
* How would you indent a block of text?
  ```vim
  shift + > + >
  ```
* Tell us about one other cool vim feature you found out about that isn’t mentioned in this lab!
  ```
  vim can self-design style of text editor
  ```

##### Scripting Lab Assignment
You'll be completing a classic first shell scripting assignment: make a 
phonebook.

Write a shell script `phonebook` which has the following behavior:

- `./phonebook new <name> <number>` adds an entry to the phonebook. Don't worry about duplicates (always add a new entry, even if the name is the same).

- `./phonebook list` displays every entry in the phonebook (in no particular 
order). If the phonebook has no entries, display `phonebook is empty`

- `./phonebook remove <name>` deletes all entries associated with that name. Do nothing if that name is not in the phonebook.

- `./phonebook clear` deletes the entire phonebook.

- `./phonebook lookup <name>` displays all phone number(s) associated with that name. You can assume all phone numbers are in the form `ddd-ddd-dddd` where `d` is a digit from 0-9. 
  - **NOTE:** You can print the name as well as the number for each line. For an additional challenge, try printing all phone numbers _without_ their names. (See the example below for more details)

For example,

```bash
$ ./phonebook new "Linus Torvalds" 101-110-0111
$ ./phonebook list
Linus Torvalds 101-110-1010
$ ./phonebook new "Tux Penguin" 555-666-7777
$ ./phonebook new "Linus Torvalds" 222-222-2222
$ ./phonebook list
Linus Torvalds 101-110-1010
Tux Penguin 555-666-7777
Linus Torvalds 222-222-2222
# OPTIONAL BEHAVIOR
$ ./phonebook lookup "Linus Torvalds" 
101-110-1010
222-222-2222
# ALTERNATIVE BEHAVIOR
$ ./phonebook lookup "Linus Torvalds"
Linus Torvalds 101-110-1010
Linus Torvalds 222-222-2222
$ ./phonebook remove "Linus Torvalds"
$ ./phonebook list
Tux Penguin 555-666-7777
$ ./phonebook clear
$ ./phonebook list
phonebook is empty
```

Personal solution:

Python：
```py
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

```
Shell:
```shell
#!/bin/bash

PHONEBOOK_ENTRIES="bash_phonebook_entries"


if [ "$#" -lt 1 ]; then
    exit 1

elif [ "$1" = "new" ]; then
    # YOUR CODE HERE #
    echo "$2 $3" >> $PHONEBOOK_ENTRIES

elif [ "$1" = "list" ]; then
    if [ ! -e $PHONEBOOK_ENTRIES ] || [ ! -s $PHONEBOOK_ENTRIES ]; then
        echo "phonebook is empty"
    else
        # YOUR CODE HERE #
        while read -r line;do
        echo $line
        done < $PHONEBOOK_ENTRIES 
    fi
elif [ "$1" = "lookup" ]; then
    # YOUR CODE HERE #
    grep "$2" $PHONEBOOK_ENTRIES

elif [ "$1" = "remove" ]; then
    # YOUR CODE HERE # 
    grep -v "$2" $PHONEBOOK_ENTRIES > temp
    cat temp > $PHONEBOOK_ENTRIES
    rm -f temp

elif [ "$1" = "clear" ]; then
    # YOUR CODE HERE #
    echo -n '' > $PHONEBOOK_ENTRIES

else
     # YOUR CODE HERE #
    echo -n '' > $PHONEBOOK_ENTRIES
fi

```
