#!/bin/bash

if [ $# -ne 1 ]
  then
    echo "Provide one *.cpp file name as argument."
    exit
fi

cppfile="$1"
execfile="${cppfile%????}.out"

echo "Compiling $cppfile as $execfile and running..."
echo ""

s++ $cppfile -o $execfile &&  ./"$execfile"
