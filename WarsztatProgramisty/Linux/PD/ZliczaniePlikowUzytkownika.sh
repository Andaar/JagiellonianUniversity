#!/bin/bash
iloscPlikow=`ls -l ~/* | grep "^--" | grep -c ''`
echo "Ilosc plikow uzytkownika bez praw odczytu: $iloscPlikow"
