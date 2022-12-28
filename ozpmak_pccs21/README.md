<p>
PCCS - PC controller station (PC PLC)
</p><br>

<table>
<tr><td> pccs21.img </td>
<td> - DOS boot disk image for PC compatible controllers (PC PLC)
       such as PC104, MicroPC, SBC, EBX and others. </td></tr>

<tr><td> pccs21_0*  </td><td> - Screenshots. Virt-Manager (QEMU/KVM) window on the left side, remote access client window on the right side. </td></tr>
</table>

This image is based on MSDOS 6.22 (any other is possible). Disk size 4 Mb.  <br>
For network exchange, the FTP Software PC/TCP network stack is used.        <br>
You can connect to the controller remotely via TCP/IP from any computer (and OS) with Java installed. <br>
Downloading programs to the controller during operation is carried out via FTP. <br>
Image preparation, as well as debugging of the program can be done through a virtual machine (I used VirtualBox 5 and QEMU/KVM). <br>
