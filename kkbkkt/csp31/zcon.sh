#!/bin/bash
CD=`pwd`

cd c:/codus/TCL

FILE="KKBKKT"
STAT="KKBKKT PCCS31 (${FILE})"
VIRT="192.168.56.11"
REAL="10.10.10.3"
PORT="123"

while [ 1 ]
do
    IP=""
    PR=""
    PF=""
    echo ""
    echo "This is CONSOLE access for KKBKKT PCCS31 (${FILE})"
    echo ""
    echo " 0) EXIT"
    echo ""
    echo " 1) VIRT"
    echo " 2) REAL"
    echo ""
    echo -n " Choice number place and press ENTER: "; read k;
    if [ "$k" = "0" ] ; then break; fi
    if [ "$k" = "1" ] ; then IP="$VIRT"; PR="6363"; fi
    if [ "$k" = "2" ] ; then IP="$REAL"; PR="$PORT";fi
    if [ "$IP" = "" ] ; then continue; fi
    start TinyClient.cmd ${IP} ${PR}
done
exit
