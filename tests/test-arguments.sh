#!/bin/bash

RED='\033[0;31m';
NC='\033[0m';
GREEN='\033[0;32m';

make re > /dev/null 2>&1;

if [[ $(uname) == 'Linux' ]]
then
    do_valgrind='valgrind --leak-check=full --error-exitcode=1'
else
    do_valgrind=''
fi

if $do_valgrind ./webserv arg1 arg2 > /dev/null 2>&1;
then
    echo -e "${RED} error on too much arguments${NC}"
    exit 1;
fi

if $do_valgrind ./webserv "arg1" "arg2" > /dev/null 2>&1;
then
    echo -e "${RED} error on too much arguments${NC}"
    exit 1;
fi

if $do_valgrind ./webserv config/error_emptyfile.yml > /dev/null 2>&1;
then
    echo -e "${RED} error on empty file${NC}"
    exit 1;
fi

if $do_valgrind ./webserv config/nofilewiththisname.yml > /dev/null 2>&1;
then
    echo -e "${RED} error on unexistant file${NC}"
    exit 1;
fi

if ! $do_valgrind ./webserv config/default.yml > /dev/null 2>&1;
then
    echo -e "${RED} error on default config${NC}"
    exit 1;
fi

if ! $do_valgrind ./webserv "config/default.yml" > /dev/null 2>&1;
then
    echo -e "${RED} error on default config 1${NC}"
    exit 1;
fi

if ! $do_valgrind ./webserv > /dev/null 2>&1;
then
    echo -e "${RED} error on default config with 0 arguments${NC}"
    exit 1;
fi

echo -e "${GREEN}test on arguments OK${NC}"