output=$(ls | grep ".sh")
output=$(echo $output | tr ' ' '\n')
output=$(echo "$output" | cut -f 1 -d '.')
echo "$output"

