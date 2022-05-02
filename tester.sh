#!/bin/bash

# Simple tester for push_swap.

# Colours
RED="\033[0;31m"
GREEN="\033[0;32m"
DEF="\033[0m"

# Program input
if [[ "$1" == "m" ]]; then
	tests="0"
elif [[ "$1" == "t" ]]; then
    tests="2"
else
	tests="1"
fi

# Check for push_swap executable
if [[ -f push_swap ]]; then
	push_swap="./push_swap"
else
	echo -e "${RED}ERROR${DEF}: No push_swap executable found."
	exit 1
fi

# Run push_swap
run()
{
    echo "* Testing ARG=\"$ARG\""
    "$push_swap" $ARG
}

# Run push_swap against checker
checker()
{
    ./push_swap $ARG | ./checker_Mac $ARG > out_tmp

    # Check message from checker
    exit_msg=$(cat out_tmp)
    if [[ "$exit_msg" == "OK" ]]; then
        echo -e "${GREEN}$exit_msg${DEF}"
    else
        echo -e "${RED}Error${DEF}"
    fi

    # Delete created tmp files
    if [[ -f out_tmp ]]; then
        rm -f out_tmp
    fi
}

# Run error cases
check_error()
{
    echo "* Testing ARG=\"$ARG\""
    unset var
    var=$(./push_swap $ARG | wc -l)
    if [[ "$var" == "0" ]]; then
        echo -e "${GREEN}OK${DEF}"
    else
        echo -e "${RED}Error${DEF}"
    fi
    echo ""
}

# Generate n number of random numbers
generate_random()
{
    max=2147483648
    min=-2147483648
    unset rand_nb
    until_last=$(($1-1));
    for n in `seq "$until_last"`
    do
        # rand_nb+=$(jot -w  %i -r 1 $min $max)
        rand_nb+=$(($RANDOM % $max + $min))
        rand_nb+=" "
    done
    rand_nb+=$(($RANDOM % $max + $min))
    # rand_nb+=$(jot -w  %i -r 1 $min $max)
    unset var
    var=$(echo "$rand_nb" | wc -w)
    echo "$var random values generated"
}

# Compute number of operations
nb_op()
{
    unset var
    var=$(./push_swap $ARG | wc -l)
    echo "$var operations"
    echo ""
}

# Run, checker and nb operations
ps()
{
    run $ARG
    checker $ARG
    nb_op $ARG
}

#====================================
# Testing
if [[ $tests == "2" ]]; then
    echo "Add tests"
fi


#====================================
# Eval Sheet Tests
if [[ $tests == "1" ]]; then
    #====================================
    # Identity Test
    echo ""
    echo "Identity Test"
    echo "-------------"

    ## Test 1 - 42
    ARG="42"
    # run $ARG
    # check $ARG
    ps $ARG


    ## Test 2 - 0 1 2 3
    ARG="0 1 2 3"
    ps $ARG


    ## Test 3 -  0 1 2 3 4 5 6 7 8 9
    ARG="0 1 2 3 4 5 6 7 8 9"
    ps $ARG


    #====================================
    # Simple Version
    echo "Simple Version"
    echo "--------------"

    ## Test 1 - 2 1 0
    ARG="2 1 0"
    ps $ARG


    #====================================
    # Another Simple Version
    echo "Another Simple Version"
    echo "----------------------"

    ## Test 1 - 1 5 2 4 3
    ARG="1 5 2 4 3"
    ps $ARG


    ## Test 2 - 5 random values
    generate_random 5
    ARG="$rand_nb"
    ps $ARG


    # #====================================
    # # Middle Version
    echo "Middle Version - 100 random values"
    echo "----------------------------------"

    # Test 1 - 100 random values
    generate_random 100
    ARG="$rand_nb"
    ps $ARG


    # #====================================
    # # Advanced Version
    # echo "Advanced Version"
    # echo "----------------"

    # ## Test 1 - 500 random values
    # generate_random 500
    # ARG="$randomNumber"
    # run $ARG
    # check $ARG

fi


#====================================
# My Tests
if [[ $tests == "0" ]]; then
    echo ""
    echo "My Tests"
    echo "-------------"

    ## Test 1 - 42
    ARG="42"
    ps $ARG

    ## Test 2 - 1 0 [1/2]
    ARG="1 0"
    ps $ARG

    ## Test 3 -  0 1 [2/2]
    ARG="0 1"
    ps $ARG

    ## Test 4 -  0 1 2 [1/6]
    ARG="0 1 2"
    ps $ARG

    ## Test 5 -  0 2 1 [2/6]
    ARG="0 2 1"
    ps $ARG

    ## Test 6 -  1 0 2 [3/6]
    ARG="1 0 2"
    ps $ARG
    ## Test 7 -  1 2 0 [4/6]
    ARG="1 2 0"
    ps $ARG

    ## Test 8 -  2 0 1 [5/6]
    ARG="2 0 1"
    ps $ARG

    ## Test 9 -  2 1 0 [6/6]
    ARG="2 1 0"
    ps $ARG

    ## Test 10 - Not int
    ARG="1 hallo 2"
    check_error $ARG

    ## Test 11 - Bigger than int
    ARG="1 999999999999999999 2"
    check_error $ARG

    ## Test 12 - Smaller than int
    ARG="1 -999999999999999999 2"
    check_error $ARG

    ## Test 13 - Duplicates
    ARG="1 2 2"
    check_error $ARG

    ## Test 14 - No input
    ARG="     "
    check_error $ARG

    ## Test 14 - No input
    ARG="-+10 --7 +-5"
    check_error $ARG

    ## Test  -  3 2 1 0
    ARG="3 2 1 0"
    ps $ARG

    ## Test
    generate_random 5
    ARG="$rand_nb"
    ps $ARG
fi
