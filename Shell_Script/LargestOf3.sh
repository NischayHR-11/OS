#!/bin/bash

echo "ENTER THREE NUMBERS :"
read a b c

if [ $a -gt $b ] && [ $a -gt $c ]; then

echo "A is Largest "

elif [ $b -gt $a ] && [ $b -gt $c ];then

echo "B is Largest "

else

echo "C is Largest "

fi