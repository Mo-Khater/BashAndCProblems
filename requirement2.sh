#! /bin/bash

convert(){
if [ $# -eq 1 ] 
then 	
	str=$1
	sum=0
	j=0
	for(( i=$((${#str}-1));i>=0;i--))
	do
		((sum+=${str:i:1}*(2**j)))
		((j++))
		
	done
	echo $sum
else 
	if [ $1 -eq 1 ]
	then 
		str=$2
		sum=0
		j=0
		for(( i=$((${#str}-1));i>=0;i--))
		do
			((sum+=${str:i:1}*(2**j)))
			((j++))
		done
		echo $sum
	else
		num=$2
		reminder=0
		unset result
		while [ $num -ne 0 ]
		do 
			reminder=$(($num%2))
			num=$(($num/2))
			if [ -z result ]
			then 
				result=$reminder
			else
				result=$reminder$result
			fi
		done
		echo $result
	fi
		
fi
}

