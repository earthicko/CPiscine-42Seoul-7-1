compile_exec_rm() {
    echo "Compling rush0$1 -> test0$1..."
    gcc -Wall -Wextra -Werror ./testcase.c ./ex00/rush0$1.c ./ex00/ft_putchar.c -o test0$1
    echo "Executing test0$1 >> test0$1.result..."
    ./test0$1 >test0$1.result
    echo "Testing done. Deleting binary..."
    rm ./test0$1
}

compile_exec_rm 0
compile_exec_rm 1
compile_exec_rm 2
compile_exec_rm 3
compile_exec_rm 4