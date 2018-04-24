/*
 Ciara McMullin
 April 19, 2018
 CSO Spring 2018
 A program written from the assembly code generated from @p2_given.o
*/

#include "p2.h"

// function bar 1
long bar1(struct foo* x, int sz){
	/*	test   %rdi,%rdi
   		sete   %dl
		test   %esi,%esi
		sete   %al
		or     %al,%dl
		jne    3b <bar1+0x3b>
	*/
	if (!(x|| sz)) {
		/*
			mov    $0x0,%eax
			retq 
		*/
		return 0;
	}

	/*
	for loop that increments by 1 each loop and compares i to sz, the size integer 
  		mov    %rcx,%rax
  		add    $0x1,%edx
  		cmp    %esi,%edx
 		jl     1a <bar1+0x1a>
  		repz retq 

	*/
	long max = 0;
	int i;
	for (i = 0; i < sz; i++){
		/*
		gets the second element of the foo structure, b, and compares it to the max and continues through loop if satisfied
			mov    0x8(%rdi),%rax
			mov    $0x1,%edx
  			jmp    35 <bar1+0x35>
  			movslq %edx,%rcx
  			lea    (%rcx,%rcx,2),%rcx
			shl    $0x3,%rcx
  			mov    0x8(%rdi,%rcx,1),%rcx
  			cmp    %rax,%rcx
  			jle    32 <bar1+0x32>
		*/
		if (x[i].b > max){
			max = x[i].b;
		}
	}
	// returns max
	return max;
}

// function bar2
int bar2(struct foo*x, int sz){

	/*	test   %rdi,%rdi
   		sete   %dl
		test   %esi,%esi
		sete   %al
		or     %al,%dl
		jne    76 <bar2+0x35>
	*/
	if (!(x|| sz)) {
		/*
			mov    $0x0,%eax
			retq 
		*/
		return 0;
	}

	/*
	for loop that increments by 1 each loop and compares i to sz, the size integer 
  		mov    %ecx,%eax
  		add    $0x1,%eax
  		cmp    %esi,%edx
 		jl     59 <bar2+0x18>
  		repz retq 

	*/
	int max = 0;
	int i;
	for(i=0; i < sz; i++){
		/*
		gets the first element of the foo structure, a, and compares it to the max and continues through loop if satisfied
			mov    (%rdi),%eax
			mov    $0x1,%edx
  			jmp    70 <bar2+0x2f>
  			movslq %edx,%rcx
  			lea    (%rcx,%rcx,2),%rcx
			shl    $0x3,%rcx
  			mov    (%rdi,%rcx,1),%ecx
  			cmp    %eax,%ecx
  			jle    6d <bar2+0x2c>
		*/
		if(x[i].a > max){
			max = x[i].a;
		}
	}

	// return max
	return max;
}

// function bar3
int bar3(struct foo*x, int sz){
	/*	test   %rdi,%rdi
   		sete   %dl
		test   %esi,%esi
		sete   %al
		or     %al,%dl
		jne    b5 <bar3+0x39>
	*/
	if (!(x|| sz)) {
		/*
			mov    $0x0,%eax
			retq 
		*/
		return 0;
	}
	/*
	for loop that increments by 1 each loop and compares i to sz, the size integer 
  		mov    %ecx,%eax
  		add    $0x1,%eax
  		cmp    %esi,%edx
 		jl     96 <bar3+0x1a>
  		repz retq 

	*/
	int max = 0;
	int i;
	for(i=0; i < sz; i++){
		if(x[i].c > max){
		/*
		gets the third element of the foo structure, c, and compares it to the max and continues through loop if satisfied
			movsbl 0x10(%rdi),%eax
			mov    $0x1,%edx
  			jmp    af <bar3+0x33>
  			movslq %edx,%rcx
  			lea    (%rcx,%rcx,2),%rcx
			shl    $0x3,%rcx
  			movsbl 0x10(%rdi,%rcx,1),%ecx
  			cmp    %eax,%ecx
  			jle    ac <bar3+0x30>
		*/
			max = x[i].c;
		}
	}

	// return max
	return max;
}


