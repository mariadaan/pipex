#!/bin/bash

bold=$(tput bold)
normal=$(tput sgr0)

GREEN="\033[38;2;57;181;74m"
RED="\033[38;2;222;56;43m"
BLUE="\033[38;2;34;183;235m"
YELLOW="\033[38;2;255;176;0m"
PURPLE="\033[38;2;255;105;180m"
RESET="\033[0m"

# valid arguments
printf "$PURPLE"
echo "${bold}TEST 1"
echo "valid arguments${normal}"
printf "$RESET"
bash tester.sh files_in/file_in "cat -e" "grep gewoon" files_out/res_mine

# valid arguments
printf "$PURPLE"
echo "${bold}TEST 2"
echo "valid arguments${normal}"
printf "$RESET"
bash tester.sh files_in/file_in "cat -t" "grep FANTASTISCH" files_out/res_mine

# valid arguments
printf "$PURPLE"
echo "${bold}TEST 3"
echo "valid arguments${normal}"
printf "$RESET"
bash tester.sh files_in/file_in "ls -a" "grep pipex" files_out/res_mine

# valid arguments
printf "$PURPLE"
echo "${bold}TEST 4"
echo "valid arguments${normal}"
printf "$RESET"
bash tester.sh files_in/file_in "ls -l" "wc -l" files_out/res_mine

# valid arguments
printf "$PURPLE"
echo "${bold}TEST 4"
echo "valid arguments${normal}"
printf "$RESET"
bash tester.sh files_in/file_in "ls -l" "wc" files_out/res_mine

# input file does not exist
printf "$PURPLE"
echo "${bold}TEST 6"
echo "input file does not exist${normal}"
printf "$RESET"
bash tester.sh fiwefcen/fileewe_in "cat -e" "grep gewoon" files_out/res_mine

# first command does not exist, second command doesnt need input
printf "$PURPLE"
echo "${bold}TEST 7"
echo "first command does not exist, second command doesnt need input${normal}"
printf "$RESET"
bash tester.sh files_in/file_in "cwadfve" "ls" files_out/res_mine

# both commands do not exist
printf "$PURPLE"
echo "${bold}TEST 8"
echo "both commands do not exist${normal}"
printf "$RESET"
bash tester.sh files_in/file_in "cwadfve" "lweaqgs" files_out/res_mine

# first command does not need input, second command does not exist
printf "$PURPLE"
echo "${bold}TEST 9"
echo "first command does not need input, second command does not exist${normal}"
printf "$RESET"
bash tester.sh files_in/file_in "ls" "iopjwep" files_out/res_mine

# incorrect number of arguments ( 1 arg )
printf "$PURPLE"
echo "${bold}TEST 10"
echo "incorrect number of arguments ( 1 arg )
(output files have to be different since output file is not given as an argument)${normal}"
printf "$RESET"
touch files_out/res_mine
bash tester.sh files_in/file_in "ls" "iopjwep"

# incorrect number of arguments ( 2 args )
printf "$PURPLE"
echo "${bold}TEST 11"
echo "incorrect number of arguments ( 2 args )
(output files have to be different since output file is not made)${normal}"
printf "$RESET"
touch files_out/res_mine
bash tester.sh oejpieo

# incorrect number of arguments ( 3 args )
printf "$PURPLE"
echo "${bold}TEST 11"
echo "incorrect number of arguments ( 3 args )
(output files have to be different since output file is not made)${normal}"
printf "$RESET"
touch files_out/res_mine
bash tester.sh file_in "cat" "grep gewoon"

# non-existing flag command 1
printf "$PURPLE"
echo "${bold}TEST 11"
echo "incorrect number of arguments ( 2 args )
(output files have to be different since output file is not made)${normal}"
printf "$RESET"
touch files_out/res_mine
bash tester.sh files_in/file_in "cat -bestaatniet" "grep FANTASTISCH" files_out/res_mine

# non-existing flag command 1
printf "$PURPLE"
echo "${bold}TEST 11"
echo "incorrect number of arguments ( 2 args )
(output files have to be different since output file is not made)${normal}"
printf "$RESET"
touch files_out/res_mine
bash tester.sh files_in/file_in "cat -t" "cat -bestaatniet FANTASTISCH" files_out/res_mine

# non-existing flag command 1
printf "$PURPLE"
echo "${bold}TEST 11"
echo "incorrect number of arguments ( 2 args )
(output files have to be different since output file is not made)${normal}"
printf "$RESET"
touch files_out/res_mine
bash tester.sh files_in/file_in "cat -t" "grep -bestaatniet FANTASTISCH" files_out/res_mine