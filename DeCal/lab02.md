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
  :wq # save the file and quit vim
  :q  # quit vim (when the file not alter)
  :q! # force quit vim
  ```
* How would you edit a new file alongside another file?
