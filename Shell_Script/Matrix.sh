#!/bin/bash

echo "ENTER THE NO OF ROWS : "
read r

echo "ENTER THE NO OF COLUMNS : "
read c


echo "ENTER THE ELEMENTS OF MATRIX 'A': "

for((i=0;i<r;i++));do

for((j=0;j<c;j++));do

read A[$i$j]

done 

done


echo "ENTER THE ELEMENTS OF MATRIX 'B' : "

for((i=0;i<r;i++));do

for((j=0;j<c;j++));do

read B[$i$j]

done 

done

echo "MATRIX A :"

for((i=0;i<r;i++));do

for((j=0;j<c;j++));do

echo -n "${A[$i$j]} "

done 

echo " "
done


echo "MATRIX B :"

for((i=0;i<r;i++));do

for((j=0;j<c;j++));do

echo -n "${B[$i$j]} "

done 

echo " "
done

echo "MATRIX A+B :"

for((i=0;i<r;i++));do

for((j=0;j<c;j++));do

C[$i$j]=$((${A[$i$j]} + ${B[$i$j]}))
echo -n "${C[$i$j]} "

done 

echo " "

done