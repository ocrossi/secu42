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
   `
   stores int 108 at stack address pointed by content of esp
   `
   0x08048617 <+35>:	call   0x8048530 <_Znwj@plt>
   0x0804861c <+40>:	mov    ebx,eax
   `
   sth unknow in procedure linkage table
   `
   0x0804861e <+42>:	mov    DWORD PTR [esp+0x4],0x5
   0x08048626 <+50>:	mov    DWORD PTR [esp],ebx
   0x08048629 <+53>:	call   0x80486f6 <_ZN1NC2Ei>
   `
   same thing
   `
   0x0804862e <+58>:	mov    DWORD PTR [esp+0x1c],ebx
   0x08048632 <+62>:	mov    DWORD PTR [esp],0x6c
   0x08048639 <+69>:	call   0x8048530 <_Znwj@plt>
   `
   ?
   `
   0x0804863e <+74>:	mov    ebx,eax
   0x08048640 <+76>:	mov    DWORD PTR [esp+0x4],0x6
   0x08048648 <+84>:	mov    DWORD PTR [esp],ebx
   0x0804864b <+87>:	call   0x80486f6 <_ZN1NC2Ei>
   0x08048650 <+92>:	mov    DWORD PTR [esp+0x18],ebx
   0x08048654 <+96>:	mov    eax,DWORD PTR [esp+0x1c]
   0x08048658 <+100>:	mov    DWORD PTR [esp+0x14],eax
   0x0804865c <+104>:	mov    eax,DWORD PTR [esp+0x18]
   0x08048660 <+108>:	mov    DWORD PTR [esp+0x10],eax
   0x08048664 <+112>:	mov    eax,DWORD PTR [ebp+0xc]
   0x08048667 <+115>:	add    eax,0x4
   0x0804866a <+118>:	mov    eax,DWORD PTR [eax]
   0x0804866c <+120>:	mov    DWORD PTR [esp+0x4],eax
   0x08048670 <+124>:	mov    eax,DWORD PTR [esp+0x14]
   0x08048674 <+128>:	mov    DWORD PTR [esp],eax
   0x08048677 <+131>:	call   0x804870e <_ZN1N13setAnnotationEPc>
   0x0804867c <+136>:	mov    eax,DWORD PTR [esp+0x10]
   0x08048680 <+140>:	mov    eax,DWORD PTR [eax]
   0x08048682 <+142>:	mov    edx,DWORD PTR [eax]
   0x08048684 <+144>:	mov    eax,DWORD PTR [esp+0x14]
   0x08048688 <+148>:	mov    DWORD PTR [esp+0x4],eax
   0x0804868c <+152>:	mov    eax,DWORD PTR [esp+0x10]
   0x08048690 <+156>:	mov    DWORD PTR [esp],eax
   0x08048693 <+159>:	call   edx
   0x08048695 <+161>:	mov    ebx,DWORD PTR [ebp-0x4]
   0x08048698 <+164>:	leave
   0x08048699 <+165>:	ret
End of assembler dump.
`
