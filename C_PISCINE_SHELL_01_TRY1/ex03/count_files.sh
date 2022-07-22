find . \( -type f -or -type d \) | wc -l | tr -d ' ' | tr -d '\t'
