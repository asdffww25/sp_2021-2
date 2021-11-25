#! /bin/bash
echo -n "input number:"
read num
x=1
y=1
ans=0
for (( i=1; i<=$num; i+=1 ))
do
	if [ $i -lt 3 ]
       	then
		echo "1"
	else
		ans=$(expr "$x" + "$y")
		echo $ans
		
		y=$x
		x=$ans
	fi
done
