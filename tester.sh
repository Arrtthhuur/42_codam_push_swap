#!/bin/bash

# Simple tester for push_swap.

# Colours
RED="\033[0;31m"
GREEN="\033[0;32m"
BLUE="\033[0;36m"
DEF="\033[0m"

# Program input
if [[ "$1" == "m" ]]; then
	tests="0"
elif [[ "$1" == "t" ]]; then
    tests="2"
elif [[ "$1" == "c" ]]; then
	tests="3"
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


# Check for checker executable
if [[ -f checker_bonus/checker ]]; then
	checker="./checker"
else
	echo -e "${RED}ERROR${DEF}: No checker executable found."
	exit 1
fi


# Run push_swap
run()
{
    echo "* Testing ARG=\"$ARG\""
    "$push_swap" $ARG
}

# Run checker bonus
run_c()
{
    echo "* Testing with ARG=\"$ARG\""
    "$checker" $ARG
    echo ""
}

# Run push_swap against checker
vs_checker()
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
    vs_checker $ARG
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
    echo -e "${BLUE}Identity Test"
    echo -e "-------------${DEF}"

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
    echo -e "${BLUE}Simple Version"
    echo -e "--------------${DEF}"

    ## Test 1 - 2 1 0
    ARG="2 1 0"
    ps $ARG


    #====================================
    # Another Simple Version
    echo -e "${BLUE}Another Simple Version"
    echo -e "----------------------${DEF}"

    ## Test 1 - 1 5 2 4 3
    ARG="1 5 2 4 3"
    ps $ARG


    ## Test 2 - 5 random values
    generate_random 5
    ARG="$rand_nb"
    ps $ARG


    # #====================================
    # # Middle Version
    echo -e "${BLUE}Middle Version - 100 random values"
    echo -e "----------------------------------${DEF}"

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
    echo -e "${BLUE}My Tests"
    echo -e "-------------${DEF}"

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


#====================================
# Checker bonus
if [[ $tests == "3" ]]; then
    cd checker_bonus/
    echo ""
    echo -e "${BLUE}Checker Program - Error Management"
    echo -e "--------------------------------${DEF}"

    ## Test 1 - Non numeric => KO
    ARG="hallo un deux"
    run_c $ARG

    ## Test 2 - Duplicates => KO
    ARG="1 3 1"
    run_c $ARG

    ## Test 3 - Greater than MAX_INT => KO
    ARG="1 9999999999999999999 1"
    run_c $ARG

    ## Test 4 - Greater than MAX_INT => nothing + give prompt back
    ARG=""
    run_c $ARG

    ## Test 5 - Valid parameters + incorrect operation => KO
    ARG="1 3 2"
    run_c $ARG

    ## Test 6 - Valid parameters + operation w/ one or several spaces before/after the instruction phase => KO
    ARG="1 4 2"
    run_c $ARG

    echo ""
    echo -e "${BLUE}Checker Program - False Tests"
    echo -e "-----------------------------${DEF}"

    ## Test 1 - Given valid list of operations => KO
    ARG="0 9 1 8 2 7 3 6 4 5"
    run_c $ARG

    ## Test 2 - Choose valid parameters + valid instruction list that does NOT order => KO
    ARG="0 9 1 8 2 7 3 6 4 5"
    run_c $ARG

    echo ""
    echo -e "${BLUE}Checker Program - Right Tests"
    echo -e "-----------------------------${DEF}"

    ## Test 1 - Without any instruction => OK
    ARG="0 1 2"
    run_c $ARG

    ## Test 2 - Given valid action list => OK
    ARG="0 9 1 8 2"
    run_c $ARG

    ## Test 3 - Choose valid parameters + valid instructions that order => OK
    ARG="0 3 2"
    run_c $ARG

fi