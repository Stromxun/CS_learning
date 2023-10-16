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

##### Part 02
1、What differentiates Linux/OSX from operating systems like Windows?

2、What are some differences between the command line and normal (graphical) usage of an OS?

3、What is the root directory in Linux filesystems? Answer conceptually, as in depth as you would like,

4、`ls` has a lot of cool arguments. Try using them to get extra information such as file permissions, owner name, owner group, file size, and late date edited. In addition, I want to be able to see the size and have the files ordered by last date edited, with the oldest files on top. How would I do this?

(ls)[https://www.runoob.com/linux/linux-comm-ls.html]

```sh

```

5、Instead of showing the first 10 lines of the file `big_data.txt`, I want to use the `head` command to show the first 4. How would I do that?

```sh
$:head -n10 big_data.txt
l2uuV7T@uws7:;eAf9A7A>nUB]r0:fhE80*fa5WCIJ<bd>xG>LBOy@FS#>?-RE1\_)pmIv9^%Qr>&jc
->~QSqAoxUU|pC{\y~Jxs~u_IgQ>y!aogH{E}+yJ;PE>Z*bVk{JF0y1^cT~#D~Q)[wk^UozkG|,!XK7
TIr^%H7[[AS>Q<~=?~FpLM6C7LAXuolh0~:EX4^X6Pb(YS(]7'M+mPJ<HlMgT\eg`ygJ}<bqW-BBNku
.KW8NCq]/D"ABLTnL&fo-e,YaXt~,[.MiQ<>68kj*QHC\{7a':Jtvkb%i}f5J,lm]nXz`Qf;n)y~.KG
H;etpe:szdaPN,fjLR5LI&<XMuf"z[@4d:6qe[4"`\Ise9"t{k{:cfalp7W1:hW80^h!Y=4~hpDhUch
suv@6~9X#I1w]?6YX4pm)YUwm|>48D=#K<S.1&VvB|;,=r7f_98s*bPD2zyNSHj/h+~sHK`M5Mo<M{K
4f;5^lKeN[dGM>$;%T<`Uh(i_o^if"jbE'g&Vi9b5Ko%2atz&y%~8d]-Um7}z0mOM;0U;,x#fa:'plN
(xCL>Eib5gd}<WW\G*2g`gE]CYBy'%}QmteXKOq-L<KP>*?=FRK?sk5*}:3IA@ib'q".[*ebyyaUm\:
l+wLk=KO?9'Tp}giomes6&!m)TP/Ya(ma+~<m`ii;PKQQ_!o+$RYwb=E`Yfn|~T=#{pj(\!ks=e<)4.
.,Nrc7g8/VU^hyhkE!`VzrwvqCEkS(J!uS\x7K=TQEL-h"hf0D=P0="f1?ffcWIj|)dYwwH8A<pDvld
```

6、What’s the difference between `cat foo > out.txt` and `cat foo >> out.txt`?

```
cat foo > out.txt # copy the content of foo to out.txt,the out.txt will be covered if it has content
cat foo >> out.txt # add the content of foo to out.txt's ending
```

7、Briefly, what is the difference between permissive and copyleft licenses?

```txt
Permissive
A permissive license typically lets anyone do anything with the code but cannot sue the author if there are bugs.
Some also require anyone who distributes the code to mention where they got it from.

Copyleft
A copyleft license forces any "derivative" work to also be open source and copyleft.
You cannot use copyleft code in a permiasive licensed project or a closed source project.
You cannot distribute copyleft binaries under any other license. For example Apple's App
Store has a single license that all binaries are distributed under and it is not copyleft.
Also there are others but these are the ones most people care about.
The restrictions of a copyleft license do not apply to the cppyright holder, but if they
acced third party contributions to the code then the restrictions will apply.
```

8、Give an example of a permissive license.

<b>GPL</b>

9、Give an example of (a) open-source software and (b) free, but closed-source software that you use.

<b>firefox Vim</b>
