output=$(id -Gn $FT_USER)
output=$(echo ${output} | tr ' ' ',')
echo $output

