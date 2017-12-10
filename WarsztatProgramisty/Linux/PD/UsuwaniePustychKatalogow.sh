#!/bin/bash

pustyKatalog=`find . -type d -empty | head -n 1`
while [ -n "$pustyKatalog" ];
do
  rmdir $pustyKatalog
  echo "Usunięto katalog: $pustyKatalog"
  pustyKatalog=`find . -type d -empty | head -n 1`
done
