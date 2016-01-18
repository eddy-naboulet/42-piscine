ldapsearch -LLL -Q "uid=z*" | grep "^cn" | sort -f -r | cut -d ' ' -f 2,3
