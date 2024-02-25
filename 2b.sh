checkPal(){
str=$(echo $1 | tr '[A-Z]' '[a-z]')
i=0
j=$((${#str}-1))
while [ $i -ne $j ]
do 
	if [ ${str:i:1} != ${str:j:1} ]
	then 
		echo 0
		exit 0
	else
		((i++;j--))
	fi
done
echo 1
}
