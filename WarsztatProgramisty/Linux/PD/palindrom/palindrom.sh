#!/bin/bash

echo "Wpisz liczbę do sprawdzenia:"

read tekst

czyPrawda=true

length=${#tekst}
len=$((length/2))

lewaStrona=1

for((i=1;i<length;i++))
do
    lewaStrona=$((lewaStrona*10))
done

prawaStrona=10
prawa=0

for((i=1;i<=len;i++))
do
    lewa=$(((tekst-tekst%$lewaStrona)/lewaStrona))
    prawa=$(( prawa*10+(tekst%prawaStrona-tekst%(prawaStrona/10))/(prawaStrona/10) ))

    if(( $lewa == $prawa ))
    then
        prawaStrona=$((prawaStrona*10))
        lewaStrona=$((lewaStrona/10))
    else
        czyPrawda=false
        break
    fi
done

echo

if $czyPrawda
then
    echo "Liczba $tekst jest palindromem."
else
    echo "Liczba $tekst nie jest palindromem."
fi
