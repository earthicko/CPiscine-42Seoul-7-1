output=$(ifconfig | grep "ether " | tr -d ' ' | tr -d '\t' | cut -c 6-)
echo "${output}"
