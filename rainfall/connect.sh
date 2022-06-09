#!/bin/bash

pn=8888

echo "enter level number, ranging from 0 to 13 - 10 to 13 = bonus0 to bonus3"
read input

re='^[0-9]+$'

while ! [[ $yournumber =~ $re ]] && [ $input -gt 13 -o $input -lt 0 ]
do
	echo "wrong input"
	read input
done

num=$((input + 1))

if [ $input -gt 9 ]
then
	((input=input-10))
	level="bonus$input"
else
	level="level$input"
fi	


pass=`sed "${num}q;d" ./pass`

sshpass -p $pass ssh $level@localhost -p $pn "chmod 777 ."
sshpass -p $pass scp -P $pn ./gdbinit  $level@localhost:/home/user/$level/.gdbinit
sshpass -p $pass ssh $level@localhost -p $pn
