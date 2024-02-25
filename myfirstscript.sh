#!/bin/bash
rm -r Lab1 
mkdir Lab1 
cp words.txt numbers.txt ./Lab1/
paste words.txt numbers.txt > ./Lab1/MergedContent.txt
head -3 ./Lab1/MergedContent.txt 
sort ./Lab1/MergedContent.txt > ./Lab1/SortedMergedContent.txt”
The sorted file is :
cat ./Lab1/SortedMergedContent.txt” 
chmod ugo-r ./Lab1/SortedMergedContent.txt” # can done by chmod -r 
sort ./Lab1/MergedContent.txt | uniq 
tr '[a-z]' '[A-Z]'< ./Lab1/SortedMergedContent.txt” > ./Lab1/CapitalSortedMergedContent 
echo "in line 10 we prevent the user from reading so we can't use redirection (<)"
chmod u+r ./Lab1/SortedMergedContent.txt” && tr '[a-z]' '[A-Z]'< ./Lab1/SortedMergedContent.txt” > ./Lab1/CapitalSortedMergedContent 
cat ./Lab1/MergedContent.txt | grep "^w.*[0-9]$"
tr i o < ./Lab1/MergedContent.txt” > ./Lab1/NewMergedContent.txt
paste ./Lab1/MergedContent.txt ./Lab1/NewMergedContent.txt 
