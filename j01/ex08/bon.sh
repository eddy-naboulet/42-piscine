ldapsearch -LLL -Q "sn=*bon*" 2> /dev/null | grep "sn" | wc -l | sed 's/ //g'
