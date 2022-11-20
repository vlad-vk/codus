#!/bin/bash
CD=`pwd`

FILE="OBAEDZ2"
STAT="AEROC PCCS2 (${FILE})"
HOME="192.168.65.202"
WORK="192.168.55.2"
OZPI="192.168.77.23"
OZPZ="169.254.13.125"
PORT="84D"

while [ 1 ]
do
    IP=""
    PR=""
    PF=""
    echo ""
    echo "This is CONSOLE access for AEROC PCCS2 (${FILE})"
    echo ""
    echo " 0) EXIT"
    echo ""
    echo " 1) HOME"
    echo " 2) WORK"
    echo " 3) OZPI REMOTE"
    echo " 4) OZPI PLANT"
    echo ""
    echo -n " Choice number place and press ENTER: "; read k;
    if [ "$k" = "0" ] ; then break; fi
    if [ "$k" = "1" ] ; then IP="$HOME"; PR="6363"; fi
    if [ "$k" = "2" ] ; then IP="$WORK"; PR="6363"; fi
    if [ "$k" = "3" ] ; then IP="$OZPI"; PR="$PORT";fi
    if [ "$k" = "4" ] ; then IP="$OZPZ"; PR="6363"; fi
    if [ "$IP" = "" ] ; then continue; fi
    tinycl ${PR} ${IP}
done
exit
