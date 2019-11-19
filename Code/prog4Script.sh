#!/bin/bash

echo Script name: $0
echo $# arguments

#check for proper inputs
if [ $# -ne 2 ]
	then echo "please enter valid number of arguments"
fi

if ! [ -d "$1" ]
then
	echo "Error. Please enter directory for first argument."
	exit 1
fi
#create list and append every .tga file within the $1 dir
list=()

for entry in "$1"/*
do
	if [[ $entry == *.tga ]];
	then list+=($entry)
fi
done
#compile tile

#gcc ../Image_IO/RasterImage.c tile.c ../Image_IO/imageIO_TGA.c -lm -o tile

gcc ./ImageIO/RasterImage.c tile.c ./ImageIO/imageIO_TGA.c -lm -o tile

#run tile with all .tga files in list
./tile ${list[@]} "$2"
