function compile_and_run(){
    local main_c=$1
    local ft_dir=$2
    local binary=$3
    echo "Compile ${main_c} to ${ft_dir} ..."
    gcc -Werror -Wall -Wextra ${main_c} ./${ft_dir}/*.c -o ${binary}
    echo "Run ${binary}..."
    ./${binary}
    echo "Delete binary..."
    rm -f ${binary}
}

# for ((i=0;i<6;i++));do compile_and_run "main0$i.c" "ex0$i" "test0$i";done
compile_and_run "main04.c" "ex04" "test04"