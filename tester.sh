#!/bin/bash
<<com
USAGE

run command in following format:
bash tester.sh file_in cmd1 cmd2 file_out

example:
bash tester.sh files_in/file_in "cat -e" "grep gewoon" files_out/res_mine
com

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
