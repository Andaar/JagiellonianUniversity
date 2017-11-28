#!/bin/bash
while [ -f "$1" ]
do
  echo "Najczesciej powtarzane slowa w pliku: "
  cat $1 | sort | uniq -c | sort -r | head -n 3
  shift
done
