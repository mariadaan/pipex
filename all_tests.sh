#!/bin/bash

bold=$(tput bold)
normal=$(tput sgr0)

PURPLE="\033[38;2;255;105;180m"
RESET="\033[0m"

# valid arguments
printf "$PURPLE"
echo "${bold}TEST 1"
echo "valid arguments${normal}"
printf "$RESET"
bash single_test.sh files_in/file_in "cat -e" "grep gewoon" files_out/res_mine

# valid arguments
printf "$PURPLE"
echo "${bold}TEST 2"
echo "valid arguments${normal}"
printf "$RESET"
bash single_test.sh files_in/file_in "cat -t" "grep FANTASTISCH" files_out/res_mine

# valid arguments
printf "$PURPLE"
echo "${bold}TEST 3"
echo "valid arguments${normal}"
printf "$RESET"
bash single_test.sh files_in/file_in "ls -a" "grep pipex" files_out/res_mine

# valid arguments
printf "$PURPLE"
echo "${bold}TEST 4"
echo "valid arguments${normal}"
printf "$RESET"
bash single_test.sh files_in/file_in "ls -l" "wc -l" files_out/res_mine

# valid arguments
printf "$PURPLE"
echo "${bold}TEST 4"
echo "valid arguments${normal}"
printf "$RESET"
bash single_test.sh files_in/file_in "ls -l" "wc" files_out/res_mine

# input file does not exist
printf "$PURPLE"
echo "${bold}TEST 6"
echo "input file does not exist${normal}"
printf "$RESET"
bash single_test.sh fiwefcen/fileewe_in "cat -e" "grep gewoon" files_out/res_mine

# first command does not exist, second command doesnt need input
printf "$PURPLE"
echo "${bold}TEST 7"
echo "first command does not exist, second command doesnt need input${normal}"
printf "$RESET"
bash single_test.sh files_in/file_in "whateverrr" "ls" files_out/res_mine

# both commands do not exist
printf "$PURPLE"
echo "${bold}TEST 8"
echo "both commands do not exist${normal}"
printf "$RESET"
bash single_test.sh files_in/file_in "whateverrr" "nothing" files_out/res_mine

# first command does not need input, second command does not exist
printf "$PURPLE"
echo "${bold}TEST 9"
echo "first command does not need input, second command does not exist${normal}"
printf "$RESET"
bash single_test.sh files_in/file_in "ls" "nopeee" files_out/res_mine

# incorrect number of arguments ( 1 arg )
printf "$PURPLE"
echo "${bold}TEST 10"
echo "incorrect number of arguments ( 1 arg, input file only )${normal}"
printf "$RESET"
touch files_out/res_mine
bash single_test.sh files_in/file_in

# incorrect number of arguments ( 2 args, input file and first command only )
printf "$PURPLE"
echo "${bold}TEST 11"
echo "incorrect number of arguments ( 2 args, input file and first command only )${normal}"
printf "$RESET"
touch files_out/res_mine
bash single_test.sh files_in/file_in cat

# incorrect number of arguments ( 3 args, input file and two commands )
printf "$PURPLE"
echo "${bold}TEST 12"
echo "incorrect number of arguments ( 3 args, input file and two commands )${normal}"
printf "$RESET"
touch files_out/res_mine
bash single_test.sh files_in/file_in "cat" "grep gewoon"

# non-existing flag command 1
printf "$PURPLE"
echo "${bold}TEST 13"
echo "non-existing flag command 1${normal}"
printf "$RESET"
touch files_out/res_mine
bash single_test.sh files_in/file_in "cat -bestaatniet" "grep FANTASTISCH" files_out/res_mine

# non-existing flag command 2
printf "$PURPLE"
echo "${bold}TEST 14"
echo "non-existing flag command 2${normal}"
printf "$RESET"
touch files_out/res_mine
bash single_test.sh files_in/file_in "cat -t" "cat -bestaatniet FANTASTISCH" files_out/res_mine

# non-existing flag command 2
printf "$PURPLE"
echo "${bold}TEST 15"
echo "non-existing flag command 2${normal}"
printf "$RESET"
touch files_out/res_mine
bash single_test.sh files_in/file_in "cat -t" "grep -bestaatniet FANTASTISCH" files_out/res_mine

rm -f files_out/res_real
rm -f files_out/res_mine