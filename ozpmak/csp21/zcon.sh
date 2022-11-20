#!/bin/sh

FILE="OZPMAK21"
STAT="AEROC PCCS21 (${FILE})"
HOME="192.168.65.21"
WORK="192.168.55.21"
OZPI="192.168.77.23"
PORT="817"

PR=""
PF=""
CD=`pwd`
while [ 1 ]
do
    IP=""
    cls.cmd
    echo ""
    echo "This is CONSOLE access for $STAT"
    echo ""
    echo " 0) EXIT"
    echo ""
    echo " 1) HOME"
    echo " 2) WORK"
    echo " 3) OZPI"
    echo ""
    echo -n " Choice number place and press ENTER: "; read k;
    if [ "$k" = "0" ] ; then break; fi
    if [ "$k" = "1" ] ; then IP="$HOME"; PR="6363"; fi
    if [ "$k" = "2" ] ; then IP="$WORK"; PR="6363"; fi
    if [ "$k" = "3" ] ; then IP="$OZPI"; PR="$PORT";fi
    if [ "$IP" = "" ] ; then continue; fi
    cd c:/etc/tcl
    TinyClient.cmd ${PR} ${IP}
    cd $CD
done
exit
