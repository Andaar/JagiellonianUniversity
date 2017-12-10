#!/bin/sh

cd /etc
if [ ! -f passwd ]
then
	echo "passwd nie jest plikiem"
else
	echo "Najkrotsza nazwa usera: "
	cut -d: -f1 passwd | awk '{print length, $0}' | sort -n| cut -c 3- | head -n 1
	echo "\n\nNajdluzsza nazwa usera: "
	cut -d: -f1 passwd|awk '{print length,$0}' |sort -n -r|cut -c 3- | head -n 1
fi
