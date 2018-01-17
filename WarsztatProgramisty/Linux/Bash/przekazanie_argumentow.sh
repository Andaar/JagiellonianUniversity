#!/bin/bash

fresh() 
{
	t=$1;
	echo "fresh(): \$0 is $0";
	echo "fresh(): \$1 is $1";
	echo "frech(): \$t is $t";
	echo "fresh(): total args passed to me $#";
	echo "fresh(): all args (\$@) passed to me -\"$@\"";
	echo "fresh(): all args (\$*) passed to me -\"$*\"";
}

echo "calling fresh 1st time"
fresh Tomato;

echo "calling fresh second time"
fresh Tomato Potato Onion;
