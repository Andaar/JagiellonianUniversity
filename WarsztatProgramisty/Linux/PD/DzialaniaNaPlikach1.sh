#!/bin/bash

FILE='plik.rozszerzenie'
ls -l ~/ | sort > $FILE
length=`grep -c '' $FILE`
length=$(($length-1))
cat $FILE | head -n $length  > $FILE
length=$(cat $FILE | cut -c 1 | uniq -c | head -n 1 | tr -d ' ' | tr -d '-')
cat $FILE | head -n $length  > $FILE
cat $FILE | cut -c 2- | sort -r > $FILE
length=$(cat $FILE | cut -c 1 | uniq -c | head -n 1 | tr -d ' ' | tr -d 'r')
cat $FILE | head -n $length  > $FILE
cut -d: -f2 $FILE | cut -c 4- > $FILE
length=`grep -c '' $FILE`

i=1
for line in $(cat $FILE); do
  printf "\nWybierz operacje, ktora zamierzasz wykonac na pliku $line.\n"
  echo "Jesli chcesz wyswietlic plik wpisz: wypisz."
  echo "Jesli chcesz wyslac plik mailem wpisz: mail."
  echo "Jesli plik ma zostac pominiety wcisnij ENTER."
  printf "Co chcesz zrobić: "
  read odpowiedz
  if [[ $odpowiedz == 'wypisz' || $odpowiedz == 'Wypisz' ]]
  then
    cat ~/$line

  else if [[ $odpowiedz == 'mail' || $odpowiedz == 'Mail' ]]
    then
      uuencode ~/$line | mail -s "test" example@mail.com
      #żaden ze skryptów na wysyłanie maila nie zadziałał mi poprawnie
      #(mail nie doszedł)
    fi
  fi
done

rm $FILE
