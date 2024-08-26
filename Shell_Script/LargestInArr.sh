
#!/bin/bash 

echo "ENTER THE ELEMENTS :"
read -a arr

length=${#arr[@]}

largest=${arr[0]}

for(( i=0;i<$length;i++ ));do

if [ ${arr[i]} -gt $largest ]; then

largest=${arr[i]}

fi

done

echo "LARGEST ELEMENT IS : $largest"