output=$(find . | grep -v '/\.' | wc -l | tr -d ' ')
echo "${output}"

