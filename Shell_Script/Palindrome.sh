#!/bin/bash

echo "ENTER THE STRING OR NUMBER : "
read str1

length=${#str1}

for((i=$length-1;i>=0;i--));do

str2="${str2}${str1:i:1}"
done

if [ "${str1}"=="${str2}" ]; then

echo "Given String Is Palindrome"

else

echo "Given String Is Not A Palindrome"

fi


