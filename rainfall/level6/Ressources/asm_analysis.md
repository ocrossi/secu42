##ASM analysis

### function main
`
Dump of assembler code for function main:
   0x0804847c <+0>:	push   ebp
   0x0804847d <+1>:	mov    ebp,esp
   0x0804847f <+3>:	and    esp,0xfffffff0
   0x08048482 <+6>:	sub    esp,0x20
   0x08048485 <+9>:	mov    DWORD PTR [esp],0x40
   0x0804848c <+16>:	call   0x8048350 <malloc@plt>
   0x08048491 <+21>:	mov    DWORD PTR [esp+0x1c],eax
   0x08048495 <+25>:	mov    DWORD PTR [esp],0x4
   0x0804849c <+32>:	call   0x8048350 <malloc@plt>
   0x080484a1 <+37>:	mov    DWORD PTR [esp+0x18],eax
   0x080484a5 <+41>:	mov    edx,0x8048468
   0x080484aa <+46>:	mov    eax,DWORD PTR [esp+0x18]
   0x080484ae <+50>:	mov    DWORD PTR [eax],edx
   0x080484b0 <+52>:	mov    eax,DWORD PTR [ebp+0xc]
   0x080484b3 <+55>:	add    eax,0x4
   0x080484b6 <+58>:	mov    eax,DWORD PTR [eax]
   0x080484b8 <+60>:	mov    edx,eax
   0x080484ba <+62>:	mov    eax,DWORD PTR [esp+0x1c]
   0x080484be <+66>:	mov    DWORD PTR [esp+0x4],edx
   0x080484c2 <+70>:	mov    DWORD PTR [esp],eax
   0x080484c5 <+73>:	call   0x8048340 <strcpy@plt>
   0x080484ca <+78>:	mov    eax,DWORD PTR [esp+0x18]
   0x080484ce <+82>:	mov    eax,DWORD PTR [eax]
   0x080484d0 <+84>:	call   eax
   0x080484d2 <+86>:	leave
   0x080484d3 <+87>:	ret
End of assembler dump.
`

<0-1>			prep main stackframe
<3>			binary alignment (no simd dont care)
<6>			preps 32 bytes for main stack frame
<9>			preps only argument for malloc call
<16>			call to malloc, size is 64
<21>			stores malloc return in variable on stack at positon esp+15
<25>			preps argument for 2nd call to malloc, size is 4
<32>			2nd call to malloc
<37>			stocking malloc return to esp+24 bytes
<41>			stocks m address into edx
<46>			stores return address of 2nd malloc into eax
<50>			stores m function address to 1st place of 2nd malloc
<52-58>			retrieves 1st argc
<60-70>			preps strcpy args with 1st arg (src) as argv[1] and dst as 1st malloc
<73>			call to strcpy
<78>			stores return of strcpy;
<82>			turns eax into a pointer
<84>			call pointer stored in 1st position of taqb created bty 2nd malloc
<86-87>			clears stackframe and leave


### function n
`
Dump of assembler code for function n:
   0x08048454 <+0>:	push   ebp
   0x08048455 <+1>:	mov    ebp,esp
   0x08048457 <+3>:	sub    esp,0x18
   0x0804845a <+6>:	mov    DWORD PTR [esp],0x80485b0
   0x08048461 <+13>:	call   0x8048370 <system@plt>
   0x08048466 <+18>:	leave
   0x08048467 <+19>:	ret
End of assembler dump.
`
call to system and cat the wanted password, the function we want
to redirect to


### function m
`
Dump of assembler code for function m:
   0x08048468 <+0>:	push   ebp
   0x08048469 <+1>:	mov    ebp,esp
   0x0804846b <+3>:	sub    esp,0x18
   0x0804846e <+6>:	mov    DWORD PTR [esp],0x80485d1
   0x08048475 <+13>:	call   0x8048360 <puts@plt>
   0x0804847a <+18>:	leave
   0x0804847b <+19>:	ret
End of assembler dump.	
`
the function the program without exploit points to,
just prints Nope on screen
