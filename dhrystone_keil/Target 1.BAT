SET PATH=C:\Keil\ARM\BIN40;C:\windows\system32;C:\windows;C:\windows\system32\wbem
SET ARMCC41INC=C:\Keil\ARM\RV31\Inc
SET ARMCC41LIB=C:\Keil\ARM\RV31\Lib
SET CPU_TYPE=LPC2138
SET CPU_VENDOR=NXP (founded by Philips)
SET UV2_TARGET=Target 1
SET CPU_CLOCK=0x00B71B00
"C:\Keil\ARM\BIN40\ArmAsm" --Via "startup._ia"
"C:\Keil\ARM\BIN40\ArmCC" --Via "main.__i"
"C:\Keil\ARM\BIN40\ArmCC" --Via "timer.__i"
"C:\Keil\ARM\BIN40\ArmCC" --Via "uart.__i"
"C:\Keil\ARM\BIN40\ArmCC" --Via "lcd.__i"
"C:\Keil\ARM\BIN40\ArmCC" --Via "benchmark.__i"
"C:\Keil\ARM\BIN40\ArmLink" --Via "Dhrystone.lnp"
C:\Keil\ARM\BIN40\fromelf.exe "Dhrystone.axf" --i32combined --output "Dhrystone.hex"
