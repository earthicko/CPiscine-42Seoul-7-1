compile_exec_rm() {
    echo "Compling rush0$1 -> test0$1..."
    gcc -Wall -Wextra -Werror ./ex00/main.c ./ex00/rush0$1.c ./ex00/ft_putchar.c -o test0$1
    echo "Executing test0$1 for -5 -> 5..."
    for ((i=-5;i<=5;i++))
    do
        for ((j=-5;j<=5;j++))
        do
            echo "Testing ($i, $j):"
            ./test0$1 $i $j
        done
    done
    echo "Testing done. Deleting binary..."
    rm ./test0$1
    read -p "Press return to continue..."
}

compile_exec_rm 0
compile_exec_rm 1
compile_exec_rm 2
compile_exec_rm 3
compile_exec_rm 4