#!/bin/sh

FILE="OZPMAK21"
STAT="AEROC PCCS21 (${FILE})"
HOME="pccs@192.168.65.21"
WORK="pccs@192.168.55.21"
OZPI="pccs@169.254.13.71"

PR=""
PF=""
FL="-B"
while [ 1 ]
do
    IP=""
    cls.cmd
    echo ""
    echo "This is UPLOAD programm to $STAT"
    echo ""
    echo " 0) EXIT"
    echo ""
    echo " 1) HOME"
    echo " 2) WORK"
    echo " 3) OZPI"
    echo ""
    echo -n " Choice number place and press ENTER: "; read k;
    if [ "$k" = "0" ] ; then exit; fi
    if [ "$k" = "1" ] ; then IP="$HOME"; PF="--proxy=off"; fi
    if [ "$k" = "2" ] ; then IP="$WORK"; PF="--proxy=off"; fi
    if [ "$k" = "3" ] ; then IP="$OZPI"; PR="192.168.77.23:1080"; PF="--proxy=socks"; fi
    if [ "$IP" = "" ] ; then continue; fi
    export ftp_proxy=$PR
    cmd="wputm ${FL} ${PF} ${FILE}.EXE ftp://${IP}"; echo $cmd; $cmd;
    cmd="wputm ${FL} ${PF} ${FILE}.INI ftp://${IP}"; echo $cmd; $cmd;
    echo -n "Press Enter to continue..."; read k;
done
exit
