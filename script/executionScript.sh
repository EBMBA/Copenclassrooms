#!/usr/bin/bash
#Example result gcc affiche.o somme.o moyenne.o copie.o maximumTableau.o ordonnerTableau.o main.c -o main

# Find all executable files 
FILES=`ls Sources/*.o` 
# Check them 
echo $FILES

# init final command 
CMD="gcc"

# Add all executable files in final command 
for FILE in $FILES
do
    CMD+=" $FILE"
done

# Add main file
CMD+=" main.c -o main"

# Show the command 
echo $CMD 

exit 0