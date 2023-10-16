### Lab 1 - Unix, the Shell, OSS

##### Part 01


```sh
$: tar xvzf b01.tgz
```

1、 What does pwd give you (conceptually)?

``` The Absolute path of this folder```

2、 What is the secret?
```sh
$: ls -a
.  ..  .secret  a_script  big_data.txt  hello_world  nonsense
```

So, the secret file is `.secret`

3、A malicious user made its way into my computer and created a message split across all the files in `nonsense/.` What does it say? How did you find the message? 
(Hint: `ls` and/or `xargs` will be helpful here. If you want a challenge, try to do this in a single short command- but it’s ok to find it by any means available.)

```sh
$: ls | xargs cat
s
t
a
n
f
o
r
d

>

b
e
r
k
e
l
e
y
```
4、Go ahead and delete everything in `nonsense/` with one command. How did you do it?
```sh
$: rm -rf nonsense
$: ls -a
.secret  a_script  big_data.txt  hello_world
```

