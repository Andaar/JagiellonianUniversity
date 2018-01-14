#!/bin/sh

#  UserNames.sh
#  Wyświetlanie najkrótszej i najdłużej nazwy użytkownika
#
#  Created by Andaar on 06.12.2017.
#  

$siezka = /etc/passwd
if [ ! -f $sciezka ]
then
    echo "$sciezka nie jest plikiem"
    break
fi

while [ -f $sciezka ]
do
    cut -d: -f1 $sciezka
    shift
done
