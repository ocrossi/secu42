##ASM analysis

### function main
`
Dump of assembler code for function main:
   0x08048521 <+0>:	push   ebp
   0x08048522 <+1>:	mov    ebp,esp
   0x08048524 <+3>:	and    esp,0xfffffff0
   0x08048527 <+6>:	sub    esp,0x20
`
classic stuff, preps main stackframe,
alignment but no simd, preparing main stackfame 32 bytes long
`
   0x0804852a <+9>:	mov    DWORD PTR [esp],0x8
   0x08048531 <+16>:	call   0x80483f0 <malloc@plt>
   0x08048536 <+21>:	mov    DWORD PTR [esp+0x1c],eax
`
call to 1st malloc with size 8 + storing return at address esp+01c
`
   0x0804853a <+25>:	mov    eax,DWORD PTR [esp+0x1c]
   0x0804853e <+29>:	mov    DWORD PTR [eax],0x1
   0x08048544 <+35>:	mov    DWORD PTR [esp],0x8
   0x0804854b <+42>:	call   0x80483f0 <malloc@plt>
   0x08048550 <+47>:	mov    edx,eax
`
then stores return of precedent malloc in eax, sets 1st chunk of 4 bytes to 1
for the rest 2nd malloc of size 8
storing result in reg edx
`
   0x08048552 <+49>:	mov    eax,DWORD PTR [esp+0x1c]
   0x08048556 <+53>:	mov    DWORD PTR [eax+0x4],edx
   0x08048559 <+56>:	mov    DWORD PTR [esp],0x8
   0x08048560 <+63>:	call   0x80483f0 <malloc@plt>
   0x08048565 <+68>:	mov    DWORD PTR [esp+0x18],eax
`
sets eax to result of 1st malloc, puts result of 2nd malloc in result of 1st 
malloc + 1 4 bytes long bloc
3rd malloc size 8, stores result at esp+0x18
`
   0x08048569 <+72>:	mov    eax,DWORD PTR [esp+0x18]
   0x0804856d <+76>:	mov    DWORD PTR [eax],0x2
   0x08048573 <+82>:	mov    DWORD PTR [esp],0x8
   0x0804857a <+89>:	call   0x80483f0 <malloc@plt>
   0x0804857f <+94>:	mov    edx,eax
`
sets eax to point at result of 3rd malloc, stores there value of 2
then puts 8 on what is pointed by esp
4th malloc size of 8, stores result in edx
`
   0x08048581 <+96>:	mov    eax,DWORD PTR [esp+0x18]
   0x08048585 <+100>:	mov    DWORD PTR [eax+0x4],edx
`
sets eax to 3rd malloc address, puts at 3rd malloc + 4 bytes chunk the result of 4th malloc
`
   0x08048588 <+103>:	mov    eax,DWORD PTR [ebp+0xc]
   0x0804858b <+106>:	add    eax,0x4
   0x0804858e <+109>:	mov    eax,DWORD PTR [eax]
   0x08048590 <+111>:	mov    edx,eax
`
retrieving argv[1] for src of strcpy, storing in edx
`
   0x08048592 <+113>:	mov    eax,DWORD PTR [esp+0x1c]
   0x08048596 <+117>:	mov    eax,DWORD PTR [eax+0x4]
   0x08048599 <+120>:	mov    DWORD PTR [esp+0x4],edx
   0x0804859d <+124>:	mov    DWORD PTR [esp],eax
`
retrieving dest for strcpy, which is 1  of the 2 tabs malloced in the beginning
`
   0x080485a0 <+127>:	call   0x80483e0 <strcpy@plt>
`
call to strcpy
`
   0x080485a5 <+132>:	mov    eax,DWORD PTR [ebp+0xc]
   0x080485a8 <+135>:	add    eax,0x8
   0x080485ab <+138>:	mov    eax,DWORD PTR [eax]
   `
   retrieves av[2]
   `
   0x080485ad <+140>:	mov    edx,eax
   0x080485af <+142>:	mov    eax,DWORD PTR [esp+0x18]
   0x080485b3 <+146>:	mov    eax,DWORD PTR [eax+0x4]
   0x080485b6 <+149>:	mov    DWORD PTR [esp+0x4],edx
   0x080485ba <+153>:	mov    DWORD PTR [esp],eax
`
and prep 2nd chunk of 3rd malloc 
`
   0x080485bd <+156>:	call   0x80483e0 <strcpy@plt>
`
the 2nd call to strcpy
`
   0x080485c2 <+161>:	mov    edx,0x80486e9
   `
   move "r" in edx
   `
   0x080485c7 <+166>:	mov    eax,0x80486eb
   `
   move string "/home/user/level8/.pass" in eax
   `
   0x080485cc <+171>:	mov    DWORD PTR [esp+0x4],edx
	`
	stores "r" in esp+0x4
	`
   0x080485d0 <+175>:	mov    DWORD PTR [esp],eax
   0x080485d3 <+178>:	call   0x8048430 <fopen@plt>
   `
   fopen /home/user/level8/.pass with r, should be readonly flag
   `
   0x080485d8 <+183>:	mov    DWORD PTR [esp+0x8],eax
   0x080485dc <+187>:	mov    DWORD PTR [esp+0x4],0x44
   0x080485e4 <+195>:	mov    DWORD PTR [esp],0x8049960
   0x080485eb <+202>:	call   0x80483c0 <fgets@plt>
`
prepare fgets argument with global c (202), 68 bytes to read, and res of fopen?
`
   0x080485f0 <+207>:	mov    DWORD PTR [esp],0x8048703
   0x080485f7 <+214>:	call   0x8048400 <puts@plt>
`
print ~~ with puts
`
   0x080485fc <+219>:	mov    eax,0x0
   0x08048601 <+224>:	leave
   0x08048602 <+225>:	ret
End of assembler dump.
`
return 0 and clear stackframe

## m function
`
Dump of assembler code for function m:
   0x080484f4 <+0>:	push   ebp
   0x080484f5 <+1>:	mov    ebp,esp
   0x080484f7 <+3>:	sub    esp,0x18
   `
   classic beginning 24 bytes for m stackframe
   `
   0x080484fa <+6>:	mov    DWORD PTR [esp],0x0
   0x08048501 <+13>:	call   0x80483d0 <time@plt>
   `
   time with what is pointed at top of stack ?? or time of pointer 0x0 which is NULL 
   `
   0x08048506 <+18>:	mov    edx,0x80486e0
   `
   "%s - %d\n" in edx
   `
   0x0804850b <+23>:	mov    DWORD PTR [esp+0x8],eax
   0x0804850f <+27>:	mov    DWORD PTR [esp+0x4],0x8049960
   0x08048517 <+35>:	mov    DWORD PTR [esp],edx
   0x0804851a <+38>:	call   0x80483b0 <printf@plt>
   `
   call to printf with "%s - %d\n" and s is what is in c and d is res of time ? 
   `
   0x0804851f <+43>:	leave
   0x08048520 <+44>:	ret
   `
   clear n stackframe
   `
End of assembler dump.
`
