#!/bin/bash
#dynbox.sh
dialog --title "Delete file" \
--backtitle "Linux Shell" \
--yesno "Czy na pewno chcesz usunąć plik
\"/tmp/foo.txt\"?" 7 60

response=$?
case $response in
	0) echo "File deleted.";;
	1) echo "File not deleted.";;
	255) echo "[ESC] key pressed.";;
esac
