#!/bin/sh
PUSH_SWAP=push_swap
CHECKER=checker
CSVFILE=stats.csv

if [ ! -e ${PUSH_SWAP} ]; then
	echo -e "${PUSH_SWAP} not found";
	exit 1;
elif [ ! -e ${CHECKER} ]; then
 	echo -e "${CHECKER} not found";
	exit 1;
fi

for i in `seq 1 $1`; do
	for j in `seq 1 10`; do
		ARG=`ruby -e "puts (0..$i).to_a.shuffle.join(' ')"`; ./$PUSH_SWAP $ARG | ./$CHECKER --csv $ARG >> $CSVFILE;
	done
done
