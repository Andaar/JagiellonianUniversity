#!/bin/bash

FILE='plik.rozszerzenie'
ls -l ~ | grep "^-r" > $FILE
cut -d: -f2 $FILE | cut -c 4- > $FILE

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
