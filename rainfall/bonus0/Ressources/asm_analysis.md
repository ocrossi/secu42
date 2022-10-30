##ASM analysis

### function main
`
Dump of assembler code for function main:
   0x080485a4 <+0>:	push   ebp
   0x080485a5 <+1>:	mov    ebp,esp
   0x080485a7 <+3>:	and    esp,0xfffffff0
   0x080485aa <+6>:	sub    esp,0x40
   `
   set main stackframe for 64 bytes
   `
   0x080485ad <+9>:	lea    eax,[esp+0x16]
   0x080485b1 <+13>:	mov    DWORD PTR [esp],eax
   0x080485b4 <+16>:	call   0x804851e <pp>
   `
   preps call to pp with arg as a pointer to esp+22 bytes,
   that would be a 42 length tab?
   `
   0x080485b9 <+21>:	lea    eax,[esp+0x16]
   0x080485bd <+25>:	mov    DWORD PTR [esp],eax
   0x080485c0 <+28>:	call   0x80483b0 <puts@plt>
   `
   prints the result of pp
   `
   0x080485c5 <+33>:	mov    eax,0x0
   0x080485ca <+38>:	leave
   0x080485cb <+39>:	ret
   `
	return 0
   `
End of assembler dump.
`

### function pp

`
Dump of assembler code for function pp:
   0x0804851e <+0>:	push   ebp
   0x0804851f <+1>:	mov    ebp,esp
   0x08048521 <+3>:	push   edi
   0x08048522 <+4>:	push   ebx
   0x08048523 <+5>:	sub    esp,0x50
   `
   classic start 80 bytes for current stackframe, expect
   lots of variables since compiler needs more registers than
   usual
   `
   0x08048526 <+8>:	mov    DWORD PTR [esp+0x4],0x80486a0
   0x0804852e <+16>:	lea    eax,[ebp-0x30]
   0x08048531 <+19>:	mov    DWORD PTR [esp],eax
   0x08048534 <+22>:	call   0x80484b4 <p>
   `
   preps call to p with '-' and ebp-0x30
   and call to p
   `
   0x08048539 <+27>:	mov    DWORD PTR [esp+0x4],0x80486a0
   0x08048541 <+35>:	lea    eax,[ebp-0x1c]
   0x08048544 <+38>:	mov    DWORD PTR [esp],eax
   0x08048547 <+41>:	call   0x80484b4 <p>
   `
   same call to p but with arg1 other variable on stack
   `
   0x0804854c <+46>:	lea    eax,[ebp-0x30]
   0x0804854f <+49>:	mov    DWORD PTR [esp+0x4],eax
   0x08048553 <+53>:	mov    eax,DWORD PTR [ebp+0x8]
   0x08048556 <+56>:	mov    DWORD PTR [esp],eax
   0x08048559 <+59>:	call   0x80483a0 <strcpy@plt>
   `
   get 1st arg of pp call and var used for 1st call to pp and call strcpy
   `
   0x0804855e <+64>:	mov    ebx,0x80486a4
   0x08048563 <+69>:	mov    eax,DWORD PTR [ebp+0x8]
   `
   preps the doom space
   then preps arg of pp
   `
   0x08048566 <+72>:	mov    DWORD PTR [ebp-0x3c],0xffffffff
   0x0804856d <+79>:	mov    edx,eax
   0x0804856f <+81>:	mov    eax,0x0
   `
   some random var on stack gets set to 0xffffffff
   we store arg of pp call in edx
   then set eax to 0
   `
   0x08048574 <+86>:	mov    ecx,DWORD PTR [ebp-0x3c]
   0x08048577 <+89>:	mov    edi,edx
   `
   store the 0xffffffff in ecx
   edi set to arg of pp
   `
   0x08048579 <+91>:	repnz scas al,BYTE PTR es:[edi]
   0x0804857b <+93>:	mov    eax,ecx
   0x0804857d <+95>:	not    eax
   0x0804857f <+97>:	sub    eax,0x1
   `
   repeat while not zero, compares al (the left? most byte of the 32bit register eax, the weakest byte) with byte at es:[edi] then sets status flag
   well in the end this is a strlen
   `
   0x08048582 <+100>:	add    eax,DWORD PTR [ebp+0x8]
   0x08048585 <+103>:	movzx  edx,WORD PTR [ebx]
   `
	"Cette instruction permet de copier un registre de taille inférieur dans un registre de plus grande taille en remplissant les bits supplémentaires par des 0"
   ??
   `
   0x08048588 <+106>:	mov    WORD PTR [eax],dx
   0x0804858b <+109>:	lea    eax,[ebp-0x1c]
   0x0804858e <+112>:	mov    DWORD PTR [esp+0x4],eax
   0x08048592 <+116>:	mov    eax,DWORD PTR [ebp+0x8]
   0x08048595 <+119>:	mov    DWORD PTR [esp],eax
   0x08048598 <+122>:	call   0x8048390 <strcat@plt>
   `
   call to strcat with pp arg and var used in 2nd call to p
   `
   0x0804859d <+127>:	add    esp,0x50
   0x080485a0 <+130>:	pop    ebx
   0x080485a1 <+131>:	pop    edi
   0x080485a2 <+132>:	pop    ebp
   0x080485a3 <+133>:	ret
End of assembler dump.
`
clear pp stackframe and returns


### function p
`
Dump of assembler code for function p:
   0x080484b4 <+0>:	push   ebp
   0x080484b5 <+1>:	mov    ebp,esp
   0x080484b7 <+3>:	sub    esp,0x1018
   `
   stackframe 4120 bytes
   `
   0x080484bd <+9>:	mov    eax,DWORD PTR [ebp+0xc]
   0x080484c0 <+12>:	mov    DWORD PTR [esp],eax
   0x080484c3 <+15>:	call   0x80483b0 <puts@plt>
   `
   call to puts with 2nd p arg which is "-" for both calls
   so just prints "-"
   `
   0x080484c8 <+20>:	mov    DWORD PTR [esp+0x8],0x1000
   0x080484d0 <+28>:	lea    eax,[ebp-0x1008]
   0x080484d6 <+34>:	mov    DWORD PTR [esp+0x4],eax
   0x080484da <+38>:	mov    DWORD PTR [esp],0x0
   0x080484e1 <+45>:	call   0x8048380 <read@plt>
   `
   call read with 4096 bytes, a pointer on stack tp ebp-4014bytes
   and file descriptor param, since its stdin, is 0
   `
   0x080484e6 <+50>:	mov    DWORD PTR [esp+0x4],0xa
   0x080484ee <+58>:	lea    eax,[ebp-0x1008]
   0x080484f4 <+64>:	mov    DWORD PTR [esp],eax
   0x080484f7 <+67>:	call   0x80483d0 <strchr@plt>
   `
   call strchr in search for newline char on all read string (using
   eax as length of chars red before)
   `
   0x080484fc <+72>:	mov    BYTE PTR [eax],0x0
   `
   cuts to 1st newline encountered
   `
   0x080484ff <+75>:	lea    eax,[ebp-0x1008]
   0x08048505 <+81>:	mov    DWORD PTR [esp+0x8],0x14
   0x0804850d <+89>:	mov    DWORD PTR [esp+0x4],eax
   0x08048511 <+93>:	mov    eax,DWORD PTR [ebp+0x8]
   0x08048514 <+96>:	mov    DWORD PTR [esp],eax
   0x08048517 <+99>:	call   0x80483f0 <strncpy@plt>
   `
   strncpy  of read for 20 chars in 1st arg of p
   `
   0x0804851c <+104>:	leave
   0x0804851d <+105>:	ret
End of assembler dump.
`
end of p stackframe
