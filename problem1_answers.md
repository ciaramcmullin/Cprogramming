Ciara McMullin
CSO Spring 18
A file that contains the output and structure storages from @problem1.c


RUN 1: first three letters of your first name, first three letters of your last name
	./problem1 Cia McM
	
	- output:
		First:     Cia                 
		Last:      McM                 
		Initial:   L                   
		Age:       21                  
		Salary:    70000 

	- terminated normally
	
	- output of the program as expected

	Breakpoint 43:
		memory address 		m 	m+1 	m+2 	m+3 	m+4 	m+5 	m+6 	m+7
		hex representation 	0x30	0x8	0x40	0x0	0x0	0x0	0x0	0x0			
		char representation 	0	\b	@	NUL	NUL	NUL	NUL	NUL				
						
		memory address 		m+8 	m+9 	m+10 	m+11 	m+12 	m+13 	m+14 	m+15
		hex representation 	0x40	0x5	0x40	padding padding padding padding padding
		char representation 	@	\005	@				
							
		memory address 		m+16 	m+17 	m+18 	m+19 	m+20 	m+21 	m+22 	m+23
		hex representation 	0x7f	0xff	0xff	0xff	0xe0	0x60	0x0	0x0	
		char representation 					à	`	NUL	NUL

	Breakpoint 53:
		memory address 		m 	m+1 	m+2 	m+3 	m+4 	m+5 	m+6 	m+7
		hex representation 	0x30	0x8	0x40	0x0	0x0	0x0	0x0	0x0			
		char representation 	0	\b	@	NUL	NUL	NUL	NUL	NUL				
						
		memory address 		m+8 	m+9 	m+10 	m+11 	m+12 	m+13 	m+14 	m+15
		hex representation 	0x40	0x5	0x4c	padding padding padding padding padding
		char representation 	@	\005	L	 				
							
		memory address 		m+16 	m+17 	m+18 	m+19 	m+20 	m+21 	m+22 	m+23
		hex representation 	0x60	0x20	0x10	0x0	0x0	0x0	0x0	0x0
		char representation 	`			NUL	NUL	NUL	NUL	NUL

	Breakpoint 65:
		memory address 		m 	m+1 	m+2 	m+3 	m+4 	m+5 	m+6 	m+7
		hex representation 	0x43	0x69	0x61	0x0	0x0	0x4d	0x63	0x4d			
		char representation 	C	i	a	NUL	NUL	M	c	M		
						
		memory address 		m+8 	m+9 	m+10 	m+11 	m+12 	m+13 	m+14 	m+15
		hex representation 	0x0	0x5	0x4c	padding padding padding padding padding
		char representation 	NUL		L			
							
		memory address 		m+16 	m+17 	m+18 	m+19 	m+20 	m+21 	m+22 	m+23
		hex representation 	0x60	0x20	0x10	0x0	0x0	0x0	0x0	0x0		
		char representation 	`			NUL	NUL	NUL	NUL	NUL																										
	



RUN 2: first five letters of your first name, first three letters of your last name
	./problem1 Ciara McM
	
	- output:
		First:     CiaraMcM                
		Last:      McM                
		Initial:   L                   
		Age:       21                  
		Salary:  70000 

	- terminated normally
	
	-  the output is not as expected; the input into argv[1] is in fact the first five letters of my name, 'Ciara', which
	is 5 bytes for the 5 letters. However, in this strcpy function, it is continuing to loop until '\0' is reached. When
	first is more than 4 chars, there is no byte of '\0' between first and last that tells the function to terminate. So, 
	it continues to loop until it reaches the end of the arguements. Since m+8 contains '\0' the function stops copying the
	chars to the string. 
	
	Breakpoint 43:
		memory address 		m 	m+1 	m+2 	m+3 	m+4 	m+5 	m+6 	m+7
		hex representation 	0x30	0x8	0x40	0x0	0x0	0x0	0x0	0x0
		char representation 	0	\b	@	NUL	NUL	NUL	NUL	NUL				
						
		memory address 		m+8 	m+9 	m+10 	m+11 	m+12 	m+13 	m+14 	m+15
		hex representation 	0x40	0x5	0x40	padding padding padding padding padding
		char representation 	@	\005	@				
							
		memory address 		m+16 	m+17 	m+18 	m+19 	m+20 	m+21 	m+22 	m+23
		hex representation 	0x7f	0xff	0xff	0xff	0xe0	0x50	0x0	0x0	
		char representation 					à	P	NUL	NUL


	Breakpoint 53:
		memory address 		m 	m+1 	m+2 	m+3 	m+4 	m+5 	m+6 	m+7
		hex representation 	0x30	0x8	0x40	0x0	0x0	0x0	0x0	0x0			
		char representation 	0	\b	@	NUL	NUL	NUL	NUL	NUL				
						
		memory address 		m+8 	m+9 	m+10 	m+11 	m+12 	m+13 	m+14 	m+15
		hex representation 	0x40	0x5	0x4c	padding padding padding padding padding
		char representation 	@	\005	L	 				
							
		memory address 		m+16 	m+17 	m+18 	m+19 	m+20 	m+21 	m+22 	m+23
		hex representation 	0x60	0x20	0x10	0x0	0x0	0x0	0x0	0x0	
		char representation				NUL	NUL	NUL	NUL	NUL
		
	
	Breakpoint 65:
		memory address 		m 	m+1 	m+2 	m+3 	m+4 	m+5 	m+6 	m+7
		hex representation 	0x43	0x69	0x61	0x72	0x61	0x4d	0x63	0x4d	
		char representation 	C	i	a	r	a	M	c	M		
						
		memory address 		m+8 	m+9 	m+10 	m+11 	m+12 	m+13 	m+14 	m+15
		hex representation 	0x0	0x5	0x4c	padding padding padding padding padding		
		char representation 	NUL	\005	L			
							
		memory address 		m+16 	m+17 	m+18 	m+19 	m+20 	m+21 	m+22 	m+23
		hex representation 	0x60	0x20	0x10	0x0	0x0	0x0	0x0	0x0			
		char representation	`			NUL	NUL	NUL	NUL	NUL 



RUN 3: first three letters of your first name, first ten letters of your last name

	./problem1 Cia McMullinMc
	
	- output:
		First:     Cia               
		Last:      McMullinMc               
		Initial:   l                  
		Age:       21                  
		Salary:  70000 

	- terminated normally
	
	-  the output is not as expected; the middle intial should be 'L' because that is what is default value if no
	input is given for it. However, because the input of the last name was over 5 bytes, being that 5 bytes were only
	allocated for last, the other 5 bytes are stored in the next sequential bytes. Initial is then overriden with the 'l'
	from my last name input because that is the character at the 11th byte in the person structure.

	Breakpoint 43:
		memory address 		m 	m+1 	m+2 	m+3 	m+4 	m+5 	m+6 	m+7
		hex representation 	0x30	0x8	0x40	0x0	0x0	0x0	0x0	0x0			
		char representation 	0	\b	@	NUL	NUL	NUL	NUL	NUL				
						
		memory address 		m+8 	m+9 	m+10 	m+11 	m+12 	m+13 	m+14 	m+15
		hex representation 	0x40	0x5	0x40	padding padding padding padding padding
		char representation 	@	\005	@				
							
		memory address 		m+16 	m+17 	m+18 	m+19 	m+20 	m+21 	m+22 	m+23
		hex representation 	0x7f	0xff	0xff	0xff	0xe0	0x50	0x0	0x0	
		char representation 					à	P	NUL	NUL

	Breakpoint 53:
		memory address 		m 	m+1 	m+2 	m+3 	m+4 	m+5 	m+6 	m+7
		hex representation 	0x30	0x8	0x40	0x0	0x0	0x0	0x0	0x0			
		char representation 	0	\b	@	NUL	NUL	NUL	NUL	NUL				
						
		memory address 		m+8 	m+9 	m+10 	m+11 	m+12 	m+13 	m+14 	m+15
		hex representation 	0x40	0x5	0x4c	padding padding padding padding padding
		char representation 	@	\005	L	 				
							
		memory address 		m+16 	m+17 	m+18 	m+19 	m+20 	m+21 	m+22 	m+23
		hex representation 	0x60	0x20	0x10	0x0	0x0	0x0	0x0	0x0			
		char representation	`			NUL	NUL	NUL	NUL	NUL
	
	Breakpoint 65:
		memory address 		m 	m+1 	m+2 	m+3 	m+4 	m+5 	m+6 	m+7
		hex representation 	0x43	0x69	0x61	0x0	0x0	0x4d	0x63	0x4d			
		char representation 	C	i	a	NUL	NUL	M	c	M		
						
		memory address 		m+8 	m+9 	m+10 	m+11 	m+12 	m+13 	m+14 	m+15
		hex representation 	0x75	0x6c	0x6c	0x69	0x6E	padding padding padding
		char representation 	u	l	l	i	n
							
		memory address 		m+16 	m+17 	m+18 	m+19 	m+20 	m+21 	m+22 	m+23
		hex representation 	0x60	0x20	0x10	0x0	0x0	0x0	0x0	0x0			
		char representation	`			NUL	NUL	NUL	NUL	NUL 



RUN 4: first three letters of your first name, first eleven letters of your last name
	./problem1 Cia McMullinMcM
	
	- output:
		First:     Cia               
		Last:      McMullinMcM               
		Initial:   l                  
		Age:       0                  
		Salary:  33 

	- terminated normally
	
	-  the output is not as expected; because 'last' has an input of 11 characters, aka 11 bytes, both the person and
	record structures are affected. The intial is still 'l' for same reasons for run #3. The record structure now does not
	produce the correct age and salary because the 8 bytes allocated for personal_record are changed from last using more
	than 5 bytes. It changes the memory address of personal_record and therefore alters the structure.

	Breakpoint 43:
		memory address 		m 	m+1 	m+2 	m+3 	m+4 	m+5 	m+6 	m+7
		hex representation 	0x30	0x8	0x40	0x0	0x0	0x0	0x0	0x0			
		char representation 	0	\b	@	NUL	NUL	NUL	NUL	NUL				
						
		memory address 		m+8 	m+9 	m+10 	m+11 	m+12 	m+13 	m+14 	m+15
		hex representation 	0x40	0x5	0x40	padding padding padding padding padding
		char representation 	@	\005	@				
							
		memory address 		m+16 	m+17 	m+18 	m+19 	m+20 	m+21 	m+22 	m+23
		hex representation 	0x7f	0xff	0xff	0xff	0xe0	0x50	0x0	0x0		
		char representation 					à	P	NUL	NUL

	Breakpoint 53:
		memory address 		m 	m+1 	m+2 	m+3 	m+4 	m+5 	m+6 	m+7
		hex representation 	0x30	0x8	0x40	0x0	0x0	0x0	0x0	0x0			
		char representation 	0	\b	@	NUL	NUL	NUL	NUL	NUL				
						
		memory address 		m+8 	m+9 	m+10 	m+11 	m+12 	m+13 	m+14 	m+15
		hex representation 	0x40	0x5	0x4c	padding padding padding padding padding
		char representation 	@	\005	L	 				
		
		memory address 		m+16 	m+17 	m+18 	m+19 	m+20 	m+21 	m+22 	m+23
		hex representation 	0x60	0x20	0x10	0x0	0x0	0x0	0x0	0x0			
		char representation	`			NUL	NUL	NUL	NUL	NUL
	
	Breakpoint 65:
		memory address 		m 	m+1 	m+2 	m+3 	m+4 	m+5 	m+6 	m+7
		hex representation 	0x43	0x69	0x61	0x0	0x0	0x4d	0x63	0x4d			
		char representation 	C	i	a	NUL	NUL	M	c	M		
							
		memory address 		m+8 	m+9 	m+10 	m+11 	m+12 	m+13 	m+14 	m+15
		hex representation 	0x75	0x6c	0x6c	0x69	0x6E	0x4d	0x63	0x4d			
		char representation 	u	l	l	i	n	M	c	M
							
		memory address 		m+16 	m+17 	m+18 	m+19 	m+20 	m+21 	m+22 	m+23
		hex representation 	0x60	0x20	0x10	0x0	0x0	0x0	0x0	0x0			
		char representation	`			NUL	NUL	NUL	NUL	NUL



RUN 5: first three letters of your first name, first thirteen letters of your last name
	./problem1 Cia McMullinMcMul
	
	- output:
		First:     Cia               
		Last:      McMullinMcMul               
		Initial:   l                  
		

	- segmentation fault; did NOT terminate normally:
		Program received signal SIGSEGV, Segmentation fault.
		0x000000000040069c in print_person (p=0x7fffffffdf50) at problem1.c:25
		25	    printf("%-10s %-20d\n", "Age:", p->personal_record->age);
	
	-  the output caused a segmentation fault because the last input was 13 bytes and the record structure was then 
	affected resulting in an invalid memory address for the personal_record structure. Therefore, when trying to access
	and print age and salary, the program cashed.

	Breakpoint 43:
		memory address 		m 	m+1 	m+2 	m+3 	m+4 	m+5 	m+6 	m+7
		hex representation 	0x30	0x8	0x40	0x0	0x0	0x0	0x0	0x0			
		char representation 	0	\b	@	NUL	NUL	NUL	NUL	NUL				
						
		memory address 		m+8 	m+9 	m+10 	m+11 	m+12 	m+13 	m+14 	m+15
		hex representation 	0x40	0x5	0x40	padding padding padding padding padding
		char representation 	@	\005	@				
							
		memory address 		m+16 	m+17 	m+18 	m+19 	m+20 	m+21 	m+22 	m+23
		hex representation 	0x7f	0xff	0xff	0xff	0xe0	0x50	0x0	0x0	
		char representation 					à	P	NUL	NUL

	Breakpoint 53:
		memory address 		m 	m+1 	m+2 	m+3 	m+4 	m+5 	m+6 	m+7
		hex representation 	0x30	0x8	0x40	0x0	0x0	0x0	0x0	0x0			
		char representation 	0	\b	@	NUL	NUL	NUL	NUL	NUL				
						
		memory address 		m+8 	m+9 	m+10 	m+11 	m+12 	m+13 	m+14 	m+15
		hex representation 	0x40	0x5	0x4c	padding padding padding padding padding
		char representation 	@	\005	L	 				
							
		memory address 		m+16 	m+17 	m+18 	m+19 	m+20 	m+21 	m+22 	m+23
		hex representation 	0x60	0x20	0x10	0x0	0x0	0x0	0x0	0x0			
		char representation	`			NUL	NUL	NUL	NUL	NUL
		
	Breakpoint 65:
		memory address 		m 	m+1 	m+2 	m+3 	m+4 	m+5 	m+6 	m+7
		hex representation 	0x43	0x69	0x61	0x0	0x0	0x4d	0x63	0x4d			
		char representation 	C	i	a	NUL	NUL	M	c	M		
						
		memory address 		m+8 	m+9 	m+10 	m+11 	m+12 	m+13 	m+14 	m+15
		hex representation 	0x75	0x6c	0x6c	0x69	0x6E	0x4d	0x63	0x4d	
		char representation 	u	l	l	i	n	M	c	M
							
		memory address 		m+16 	m+17 	m+18 	m+19 	m+20 	m+21 	m+22 	m+23
		hex representation 	0x75	0x6c	0x0	0x0	0x0	0x0	0x0	0x0			
		char representation 	u	l	NUL	NUL	NUL	NUL	NUL	NUL

