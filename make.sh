#!/bin/bash

# arg1: contest site name
# arg2: contest name
# arg3: number of problems

ALPHA="ABCDEFGHIJKLMNOPQRSTUVWXYZ"

if [ $# -ne 3 ]; then
  echo "invalid argument count" 1>&2
  exit 1
fi

contest_site=$1
contest_name=$2
num=`expr $3 - 1`

path="./${contest_site}/${contest_name}"

command="mkdir ${path}"
${command}
command="cd ${path}"
${command}

command="touch in.txt"
${command}

for i in `seq 0 $num`
do
  command="cp ../../template.cpp ${ALPHA:i:1}.cpp"
  ${command}
done
