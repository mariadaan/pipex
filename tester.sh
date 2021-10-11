#!/bin/bash

make

RES_REAL="files_out/res_real"
DIFF_FILE="files_out/diff.txt"

rm -f $4
rm -f $RES_REAL
rm -f $DIFF_FILE

ARG2=$2
echo ""
echo "my command:   "./pipex $1 \"$2\" \"$3\" $4
echo "real command: <" $1 $2 "|" $3 ">" $RES_REAL
echo ""
./pipex $1 "$2" "$3" $4
echo -n "my exit code:   "
echo $?
< $1 $2 | $3 > $RES_REAL
echo -n "real exit code: "
echo $?
echo ""
diff $4 $RES_REAL > $DIFF_FILE
wc -l $DIFF_FILE
