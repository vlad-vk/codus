#!/bin/bash

PATH=c:/prog/cygwin;${PATH}

FILE="kkbkkt"
STAT="KKBKKT PCCSKT (${FILE})"
VIRT="pccs@192.168.56.11"
REAL="pccs@10.10.10.3"

FL="-B"
while [ 1 ]
do
    IP=""
    PR=""
    PF=""
    echo ""
    echo "This is UPLOAD programm to $STAT"
    echo ""
    echo " 0) EXIT"
    echo ""
    echo " 1) VIRTUAL"
    echo " 2) REAL"
    echo ""
    echo -n " Choice number place and press ENTER: "; read k;
    if [ "$k" = "0" ] ; then exit; fi
    if [ "$k" = "1" ] ; then IP="$VIRT"; PF="--proxy=off"; fi
    if [ "$k" = "2" ] ; then IP="$REAL"; PF="--proxy=off"; fi
    if [ "$IP" = "" ] ; then continue; fi
    export ftp_proxy=$PR
    cmd="c:/prog/cygwin/wputm.exe ${FL} ${PF} ${FILE}.exe ftp://${IP}"; echo $cmd; $cmd;
#   cmd="wput ${FL} ${PF} ${FILE}.ini ftp://${IP}"; echo $cmd; $cmd;
    echo -n "Press Enter to continue..."; read k;
done
exit
