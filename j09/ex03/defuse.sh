touch -A -000001 -a bomb.txt | stat -s bomb.txt | cut -d ' ' -f9 | cut -d '=' -f2
