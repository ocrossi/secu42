#!/bin/bash

pn=4242
ip="192.168.243.130"

echo "enter level number, ranging from 0 to 9"
read input

re='^[0-9]+$'

while ! [[ $yournumber =~ $re ]] && [ $input -gt 9 -o $input -lt 0 ]
do
	echo "wrong input"
	read input
done

level="level$input"
num=$((input + 1))


pass=`sed "${num}q;d" ./pass`

sshpass -p $pass ssh $level@$ip -p $pn "chmod 777 ."
sshpass -p $pass scp -P $pn ./gdbinit  $level@$ip:/home/user/$level/.gdbinit
sshpass -p $pass ssh $level@$ip -p $pn
