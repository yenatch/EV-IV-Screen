#EV-IV-Screen  
  
##How to use  
1. Make sure that you have Devkitarm and GNU make/cygwin installed.   
2. Download this repo and create a new folder called "build".   
3. Assign the free space you want to use in linker.lsc.   
4. Open your cmd prompt and type in make. Then press enter.   
5. Now main.bin should be generated. Paste it to the offset specified in step3.   
6. Write a script to test (You should callasm to the offset of insertion + 0x79.   
   
Example:   
lock   
faceplayer   
callasm 0x8800079  //I inserted the code at 0x8800000
msgbox 0x8FD0013 0x2 //"It's nice, huh?"   
releaseall   
end   