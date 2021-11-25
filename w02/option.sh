#! /bin/bash
echo "1. Create a file"
echo "2. Create a directory"
echo "3. Remove a file"
echo "4. Remove a directory"
echo "Enter:"
read num
if [ $num -eq 1 ]
then
	echo "Enter filename"
	read filename
	touch $filename
fi
if [ $num -eq 2 ]
then
	echo "Enter directory name"
	read directory
	mkdir $directory
fi
if [ $num -eq 3 ]
then
	echo "Enter filename"
	read filename
	rm $filename
fi
if [ $num -eq 4 ]
then
	echo "Enter directory name"
	read directory
	rmdir $directory
fi

