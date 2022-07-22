output=$(cat /etc/passwd | sed "/^#/d" | sed -n "n; p" | cut -d ':' -f1 | rev | sort -r | awk 'ENVIRON["FT_LINE1"] <= NR && NR <= ENVIRON["FT_LINE2"]' | tr '\n' ',' | sed "s/,/, /g" | sed "s/, $/./")
echo "$output"
