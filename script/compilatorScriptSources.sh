#!/usr/bin/bash

cd Sources
FILES=`ls *.c` 

echo $FILES
for FILE in $FILES
do
    gcc $FILE -c
done
exit 0