#!/bin/bash
while [ -f "$1" ]
do
	sort $1 > "posortowany_$1"
	shift
done
