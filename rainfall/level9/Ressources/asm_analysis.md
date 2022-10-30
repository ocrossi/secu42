##ASM analysis

### function main

`
Dump of assembler code for function main:
   0x080485f4 <+0>:	push   ebp
   0x080485f5 <+1>:	mov    ebp,esp
   0x080485f7 <+3>:	push   ebx
   0x080485f8 <+4>:	and    esp,0xfffffff0
   0x080485fb <+7>:	sub    esp,0x20
   `
   	32 bytes allocated for main stackframe and ebx pushed on stack
   `
   0x080485fe <+10>:	cmp    DWORD PTR [ebp+0x8],0x1
   0x08048602 <+14>:	jg     0x8048610 <main+28>
   `
   compare what is at ebp+0x8 with 1, jump if greater than 1 at main+28
   `
   0x08048604 <+16>:	mov    DWORD PTR [esp],0x1
   0x0804860b <+23>:	call   0x80484f0 <_exit@plt>
   `
   exit(1)
   `
   0x08048610 <+28>:	mov    DWORD PTR [esp],0x6c
   0x08048617 <+35>:	call   0x8048530 <_Znwj@plt>
   0x0804861c <+40>:	mov    ebx,eax
   `
   	stores int 108 at stack address pointed by content of esp
	new elem of class n with param 108
   `
   0x0804861e <+42>:	mov    DWORD PTR [esp+0x4],0x5
   0x08048626 <+50>:	mov    DWORD PTR [esp],ebx
   0x08048629 <+53>:	call   0x80486f6 <_ZN1NC2Ei>
   0x0804862e <+58>:	mov    DWORD PTR [esp+0x1c],ebx
   `
  	class call N::N(int) with ebx and 5, ebx for now unitialized pointer
	we put ebx content on stack at  esp+0x1c
   `
   0x08048632 <+62>:	mov    DWORD PTR [esp],0x6c
   0x08048639 <+69>:	call   0x8048530 <_Znwj@plt>
   0x0804863e <+74>:	mov    ebx,eax
   `
   	 we put 108 again on top of stack, new elem same param 108
   	and storing result of class call in ebx
   `
   0x08048640 <+76>:	mov    DWORD PTR [esp+0x4],0x6
   0x08048648 <+84>:	mov    DWORD PTR [esp],ebx
   0x0804864b <+87>:	call   0x80486f6 <_ZN1NC2Ei>
   0x08048650 <+92>:	mov    DWORD PTR [esp+0x18],ebx
   `
   same op with 2nd elem new, this time with 6 as param and storing at esp+0x18
   `
   0x08048654 <+96>:	mov    eax,DWORD PTR [esp+0x1c]
   0x08048658 <+100>:	mov    DWORD PTR [esp+0x14],eax
   `
   	get res of 1st N::Nint(p, 5) store in eax, then stores it on stack at esp+0x14
   `
   0x0804865c <+104>:	mov    eax,DWORD PTR [esp+0x18]
   0x08048660 <+108>:	mov    DWORD PTR [esp+0x10],eax
   `
   	get res of 2nd N::Nint(p, 6) store in eax, then stores it on stack at esp+0x10
   `
   0x08048664 <+112>:	mov    eax,DWORD PTR [ebp+0xc]
   0x08048667 <+115>:	add    eax,0x4
   0x0804866a <+118>:	mov    eax,DWORD PTR [eax]
   0x0804866c <+120>:	mov    DWORD PTR [esp+0x4],eax
   `
   get av[1] as a pointer ans stores in on stack an esp+0x4
   `
   0x08048670 <+124>:	mov    eax,DWORD PTR [esp+0x14]
   0x08048674 <+128>:	mov    DWORD PTR [esp],eax
   `
   get 1st res and stores in on top of stack
   `
   0x08048677 <+131>:	call   0x804870e <_ZN1N13setAnnotationEPc>
   `
   call to N::NsetAnnotation(av[1], 1stres)
   `
   0x0804867c <+136>:	mov    eax,DWORD PTR [esp+0x10]
   `
   stores res on stack at esp+0x10
   `
   0x08048680 <+140>:	mov    eax,DWORD PTR [eax]
   0x08048682 <+142>:	mov    edx,DWORD PTR [eax]
   `
   eax and edx == pointer on res of set annotation
   `
   0x08048684 <+144>:	mov    eax,DWORD PTR [esp+0x14]
   0x08048688 <+148>:	mov    DWORD PTR [esp+0x4],eax
   0x0804868c <+152>:	mov    eax,DWORD PTR [esp+0x10]
   0x08048690 <+156>:	mov    DWORD PTR [esp],eax
   0x08048693 <+159>:	call   edx
   `
   eax set to res of 1st N::N(int)
   then we store in at esp+0x4, overrideing the save value of av[1]
	store res of set annotation at esp+0x10
	and then on top of stack
	call pointer on res of setAnnotation
   `
   0x08048695 <+161>:	mov    ebx,DWORD PTR [ebp-0x4]
   `
   ??
   `
   0x08048698 <+164>:	leave
   0x08048699 <+165>:	ret
End of assembler dump.
`


### function N::NsetAnnotation(void *p, char *s)
`
Dump of assembler code for function _ZN1N13setAnnotationEPc:
   0x0804870e <+0>:	push   ebp
   0x0804870f <+1>:	mov    ebp,esp
   0x08048711 <+3>:	sub    esp,0x18
   `
   classis stack setup with 24 bytes for stackframe
   `
   0x08048714 <+6>:	mov    eax,DWORD PTR [ebp+0xc]
   0x08048717 <+9>:	mov    DWORD PTR [esp],eax
   0x0804871a <+12>:	call   0x8048520 <strlen@plt>
   `
   call to strlen with 2nd arg
   `
   0x0804871f <+17>:	mov    edx,DWORD PTR [ebp+0x8]
   0x08048722 <+20>:	add    edx,0x4
   `
   	add 4 to 1st arg (we displace pointer of 1 group of 4 bytes, so to next possible address)
   `
   0x08048725 <+23>:	mov    DWORD PTR [esp+0x8],eax
   `
   store res of strlen on stack at esp+0x8
   `
   0x08048729 <+27>:	mov    eax,DWORD PTR [ebp+0xc]
   0x0804872c <+30>:	mov    DWORD PTR [esp+0x4],eax
   0x08048730 <+34>:	mov    DWORD PTR [esp],edx
   0x08048733 <+37>:	call   0x8048510 <memcpy@plt>
   `
   	store 2nd arg in eax, then on stack at esp+0x4 , store on top of stack p+4
	then call to memcpy
   `
   0x08048738 <+42>:	leave
   0x08048739 <+43>:	ret
End of assembler dump.
`
classic clear of stackframe


### function N::N(int)
`
Dump of assembler code for function _ZN1NC2Ei:
   0x080486f6 <+0>:	push   ebp
   0x080486f7 <+1>:	mov    ebp,esp
   `
   setup stackframe
   `
   0x080486f9 <+3>:	mov    eax,DWORD PTR [ebp+0x8]
   `
   1st arg of function in eax
   `
   0x080486fc <+6>:	mov    DWORD PTR [eax],0x8048848
   `
   	??
   `
   0x08048702 <+12>:	mov    eax,DWORD PTR [ebp+0x8]
   0x08048705 <+15>:	mov    edx,DWORD PTR [ebp+0xc]
   0x08048708 <+18>:	mov    DWORD PTR [eax+0x68],edx
   0x0804870b <+21>:	pop    ebp
   0x0804870c <+22>:	ret
End of assembler dump.
`


### function N::Noperator+(int)
### function N::Noperator-(int)

