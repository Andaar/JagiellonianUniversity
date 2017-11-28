#!/bin/bash
if [ ! -f "$1" ]
then
  echo "$1 nie jest plikiem"
  break
fi

while [ -d "$2" ]
do
  cp $1 $2
  shift
done
