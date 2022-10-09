#!/bin/bash

RED='\033[0;31m';
GREEN='\033[0;32m';
NC='\033[0m';

make re > /dev/null 2>&1;

if [[ $(uname) == 'Linux' ]]
then
    do_valgrind='valgrind --leak-check=full --error-exitcode=1'
else
    do_valgrind=''
fi


for ((i=0; i <= 6; i++))
do
    if $do_valgrind ./webserv "config/error_server_${i}.yml" > /dev/null 2>&1
    then
        echo -e "${RED} ${i}) KO";
        exit 1;
    else
        echo -e "${GREEN} ${i}) OK";
    fi
done

echo -e "${GREEN}test on the server keyword OK${NC}"