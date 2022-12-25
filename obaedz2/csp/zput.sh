#!/bin/bash

FILE="obaedz2"
STAT="AEROC PCCS2 (${FILE})"
HOME="pccs@192.168.60.2"
WORK="pccs@192.168.55.2"
OZPI="pccs@169.254.13.125"

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
    echo " 1) HOME"
    echo " 2) WORK"
    echo " 3) OZPI REMOTE"
    echo " 4) OZPI PLANT"
    echo ""
    echo -n " Choice number place and press ENTER: "; read k;
    if [ "$k" = "0" ] ; then exit; fi
    if [ "$k" = "1" ] ; then IP="$HOME"; PF="--proxy=off"; fi
    if [ "$k" = "2" ] ; then IP="$WORK"; PF="--proxy=off"; fi
    if [ "$k" = "3" ] ; then IP="$OZPI"; PR="192.168.77.23:1080"; PF="--proxy=socks"; fi
    if [ "$k" = "4" ] ; then IP="$OZPI"; PF="--proxy=off"; fi
    if [ "$IP" = "" ] ; then continue; fi
    export ftp_proxy=$PR
    cmd="wputm ${FL} ${PF} ${FILE}.EXE ftp://${IP}"; echo $cmd; $cmd;
#   cmd="wputm ${FL} ${PF} ${FILE}.INI ftp://${IP}"; echo $cmd; $cmd;
    echo -n "Press Enter to continue..."; read k;
done
exit
