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
5、Two lines above the only URL in the file is a secret solution. What is that solution?
Hints: What makes up a URL (https…)? What is Context Line Control? 
```sh
$: cat big_data.txt | grep -B2 https
=================== THE SOLUTION IS MORE COFFEE ===============================
hl)V:}mntUS4;iC':uH|G(;y6Ir;4uNLLRC?GDfRP%o+g]s$NCL9zM'SK[IV.e<i&_3&7L7NBL41N#f
;=:P0viNjebvs<+^Ae.SZYG'F}\> https://xkcd.com/705 e[a3]vF;Ny,*rpyC?3OA$Nm<.iH8M
```

6、Which one does a_script need? Change the file permissions so that you can run the script. How did you do it?
```sh
$: chmod +x a.script
```
7、Finally, there’s an empty file called `hello_world` in the directory. Write your name in it! How did you do it?
```sh
$: vim hello_world
```
