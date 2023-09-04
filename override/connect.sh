#!/bin/bash

pn=4242
ip=192.168.1.28
echo "enter level number, ranging from 0 to 9"
read input

#re='^[0-9]'

while ! [ $input -lt 9 -o $input -gt 0 ]
do
	echo "wrong input"
	echo " gimme input $input"
	read input
done

level="level0${input}"

num=$((input + 1))
pass=`sed "${num}q;d" ./pass`

# echo "pass $pass"
# echo "level $level"
# echo "num $num"
sshpass -p $pass ssh $level@$ip -p $pn "chmod 777 ."
sshpass -p $pass scp -P $pn ./gdbinit  $level@$ip:/home/user/$level/.gdbinit
sshpass -p $pass ssh $level@$ip -p $pn
