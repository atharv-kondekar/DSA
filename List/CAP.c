// Cap Round

#include<stdio.h>
void kolhapur(caste)
{
	printf("\n ......... Avaible Collges in Kolhapur ........ ");
	printf("\n 1. KIT");
	printf("\n 2. DKTE");
	printf("\n 3. DYP(Bawda)");
	printf("\n 4. SIT");
	printf("\n 5. SGU");
	printf("\n 6. AMG");
	
	int choice;
	printf("\n Enter the Collge index for whcich you want to see cutoff : ");
	scanf("%d",&choice);
	
	if( caste =='OPEN' || caste=='open' || caste == 'Open'){
	switch(choice)
	{
		case 1: 
			printf("\n\t << Kolhapur Institue of Technology >>");
			printf("\n Avaible Branches : 1) CSE \n2)AIML & DS \n3)ETC \n4)Elc \n5)Mech  \n6)Civil");
			char branch;//[10];
			printf("\n Enter the branch index for which you can see cutoff of branch : ");
			scanf("%d",&branch);
			
			switch(branch){
				case 1:
					//if( branch == 'cse' || branch == 'CSE')
						printf("\n Cut off of Computer Sciece & Engg . = 93.369");
						break; 
				case 2:
					//if( branch== 'AI' || branch == 'ai')
						printf("\n Cut off of Artificial Intelligence = 90.147 ");
						break; 
				case 3:
					//if( branch == 'ETC' || branch == 'etc')
						printf("\n Cut off of Electronucs & Teli-Communication = 88.258");
						break; 
				case 4:
					//if( branch == 'ELC' || branch == 'Elc' || branch ==' elc')
						printf("\n Cut off of Electrical Eng = 82.258");
						break; 
				case 5:
					//if( branch == 'MECH' || branch == 'mech' || branch == 'MECH')
						printf("\n Cut off of Mechanical Eng. = 75.258");
						break; 
				case 6:
					//if( branch == 'Civil' || branch == 'Civil')
						printf("\n Cut off of Civil Engg. = 65.258");
					break;
				default :
					printf("\n Invalid Branch");
			}
			break ;
		
		case 2: 
			printf("\n\t << Dattagirao Kadam Textile & Eng. Institute  >>");
			printf("\n Avaible Branches : \n1) CSE \n2)AIML & DS \n3)ETC \n4)Elc \n5)Mech  \n6)Civil 7) Txt");
			int branch;//[10];
			printf("\n Enter the branch for which you can see cutoff of branch : ");
			scanf("%d",&branch);
			
			switch(branch){
				case 1:
				//	if( branch == 'cse' || branch == 'CSE')
						printf("\n Cut off of Computer Sciece & Engg . = 93.369");
						break; 
				case 2:
				//	if( branch== 'AI' || branch == 'ai')
						printf("\n Cut off of Artificial Intelligence = 90.147 ");
						break; 
				case 3:
				//	if( branch == 'ETC' || branch == 'etc')
						printf("\n Cut off of Electronucs & Teli-Communication = 88.258");
						break; 
				case 4:
				//	if( branch == 'ELC' || branch == 'Elc' || branch ==' elc')
						printf("\n Cut off of Electrical Eng = 82.258");
						break; 
				case 5:
				//	if( branch == 'MECH' || branch == 'mech' || branch == 'MECH')
						printf("\n Cut off of Mechanical Eng. = 75.258");
						break; 
				case 6:
				//	if( branch == 'Civil' || branch == 'Civil')
						printf("\n Cut off of Civil Engg. = 65.258");
						break; 
				case 7:
				//	if(branch == 'Txt' || branch == 'TXT' || branch =='txt')
					printf("\n Avaible Branches in textile : \n1) TT \n2)FT & DS \n3)TC \n4)MMTT \n5)TP");
					
						int branch1;
						printf("\n Enter the branch for which you can see cutoff of branch : ");
						scanf("%d",&branch1);
			
						switch(branch){
							case 1:
						//		if( branch == 'tt' || branch == 'TT')
									printf("\n Cut off of Textile technology . = 73.369");
									break; 
							case 2:
						//		if( branch== 'FT' || branch == 'ft')
									printf("\n Cut off of Fashion technology .= 70.147 ");
									break; 
							case 3:
						//		if( branch == 'TC' || branch == 'tc')
									printf("\n Cut off of Textile chemistry .= 66.36");
									break; 
							case 4:
						//		if( branch == 'mmtt' || branch =='MMTT')
									printf("\n Cut off of Man Made Textile technology .= 40.369");
									break; 
							case 5:
						//		if( branch == 'tp' || branch == 'TP' ||)
									printf("\n Cut off of Mechanical Eng. = 10.258");
									break; 
					
							default :
								printf("\n Invalid Branch");
						}			
				}
				
				default:
					printf('\n Inavlid chouice');
				break ;
				
			
		case 3: 
			printf("\n\t << DY PATIL KASBA BAWDA >>");
			printf("\n Avaible Branches : 1) CSE \n2)AIML & DS \n3)ETC \n4)Elc \n5)Mech  \n6)Civil");
			int branch;//[10];
			printf("\n Enter the branch for which you can see cutoff of branch : ");
			scanf("%d",&branch);
			
			switch(branch){
				case 1:
			//		if( branch == 'cse' || branch == 'CSE')
						printf("\n Cut off of Computer Sciece & Engg . = 92.369");
						break; 
				case 2:
			//		if( branch== 'AI' || branch == 'ai')
						printf("\n Cut off of Artificial Intelligence = 89.147 ");
						break; 
				case 3:
			//		if( branch == 'ETC' || branch == 'etc')
						printf("\n Cut off of Electronucs & Teli-Communication = 88.258");
						break; 
				case 4:
			//		if( branch == 'ELC' || branch == 'Elc' || branch ==' elc')
						printf("\n Cut off of Electrical Eng = 82.258");
						break; 
				case 5:
			//		if( branch == 'MECH' || branch == 'mech' || branch == 'MECH')
						printf("\n Cut off of Mechanical Eng. = 75.258");
						break; 
				case 6:
			//		if( branch == 'Civil' || branch == 'Civil')
						printf("\n Cut off of Civil Engg. = 65.258");
					break;
				default :
					printf("\n Invalid Branch");
			}
			break ;
		
		case 4: 
			printf("\n\t << Sharad Institute of technology >>");
			printf("\n Avaible Branches : 1) CSE \n2)AIML & DS \n3)ETC \n4)Elc \n5)Mech  \n6)Civil");
			int branch;//[10];
			printf("\n Enter the branch for which you can see cutoff of branch : ");
			scanf("%d",&branch);
			
			switch(branch){
				case 1:
			//		if( branch == 'cse' || branch == 'CSE')
						printf("\n Cut off of Computer Sciece & Engg . = 88.369");
						break; 
				case 2:
			//		if( branch== 'AI' || branch == 'ai')
						printf("\n Cut off of Artificial Intelligence = 80.147 ");
						break; 
				case 3:
			//		if( branch == 'ETC' || branch == 'etc')
						printf("\n Cut off of Electronucs & Teli-Communication = 75.258");
						break; 
				case 4:
			//		if( branch == 'ELC' || branch == 'Elc' || branch ==' elc')
						printf("\n Cut off of Electrical Eng = 70.258");
						break; 
				case 5:
			//		if( branch == 'MECH' || branch == 'mech' || branch == 'MECH')
						printf("\n Cut off of Mechanical Eng. = 65.258");
						break; 
				case 6:
			//		if( branch == 'Civil' || branch == 'Civil')
						printf("\n Cut off of Civil Engg. = 20.258");
						break; 
				
				default :
					printf("\n Invalid Branch");
			}
			break ;
		
		case 5: 
			printf("\n\t << Sanjay Ghodawat University >>");
			printf("\n Avaible Branches : 1) CSE \n2)AIML & DS \n3)ETC \n4)Elc \n5)Mech  \n6)Civil");
			int branch;
			printf("\n Enter the branch for which you can see cutoff of branch : ");
			scanf("%d",&branch);
			
			switch(branch){
				case 1:
			//		if( branch == 'cse' || branch == 'CSE')
						printf("\n Cut off of Computer Sciece & Engg . = 77.369");
						break; 
				case 2:
			//		if( branch== 'AI' || branch == 'ai')
						printf("\n Cut off of Artificial Intelligence = 65.147 ");
						break; 
				case 3:
			//		if( branch == 'ETC' || branch == 'etc')
						printf("\n Cut off of Electronucs & Teli-Communication = 60.258");
						break; 
				case 4:
			//		if( branch == 'ELC' || branch == 'Elc' || branch ==' elc')
						printf("\n Cut off of Electrical Eng = 50.258");
						break; 
				case 5:
			//		if( branch == 'MECH' || branch == 'mech' || branch == 'MECH')
						printf("\n Cut off of Mechanical Eng. = 45.258");
						break; 
				case 6:
			//		if( branch == 'Civil' || branch == 'Civil')
						printf("\n Cut off of Civil Engg. = 15.258");
					break;
				default :
					printf("\n Invalid Branch");
			}
			break;
			
			case 6: 
			printf("\n\t << AshokRao Mane Group >>");
			printf("\n Avaible Branches : 1) CSE \n2)AIML & DS \n3)ETC \n4)Elc \n5)Mech  \n6)Civil");
			int branch;
			printf("\n Enter the branch for which you can see cutoff of branch : ");
			scanf("%d",&branch);
			
			switch(branch){
				case 1:
			//		if( branch == 'cse' || branch == 'CSE')
						printf("\n Cut off of Computer Sciece & Engg . = 70.369");
						break; 
			
				case 2:
			//		if( branch== 'AI' || branch == 'ai')
						printf("\n Cut off of Artificial Intelligence = 65.147 ");
						break; 
				case 3:
		//			if( branch == 'ETC' || branch == 'etc')
						printf("\n Cut off of Electronucs & Teli-Communication = 50.258");
						break; 
				case 4:
					//if( branch == 'ELC' || branch == 'Elc' || branch ==' elc')
						printf("\n Cut off of Electrical Eng = 45.258");
						break; 
				case 5:
					//if( branch == 'MECH' || branch == 'mech' || branch == 'MECH')
					break; 
						printf("\n Cut off of Mechanical Eng. = 32.258");
				case 6:
					//if( branch == 'Civil' || branch == 'Civil')
						printf("\n Cut off of Civil Engg. = 6.258");
						break; 
				default :
					printf("\n Invalid Branch");
			}
			break ;
			
			default ;
				printf("\n INvalid Choice");
		}
	}
}
int main()
{
	char pass;
	printf("\n Are you pass 12th board ? (y/n) : ")	;
	fflush(stdin);
	scanf("%c",&pass);
	
	if( pass == 'y' || pass == 'Y')
	{
		int phy,chem,maths;
		printf("\n Enter marks of Physcics , Chemistry & Maths : ");
		scanf("%d%d%d",&phy,&chem,&maths);
		
		int tot= phy + chem + maths;
		float CET,JEE;
		printf("\n Enter the your CET & JEE percentile :  ");
		scanf("%f%f",&CET,&JEE);
		
		char Caste[10];
		printf("\n Enter your Caste : ");
		scanf("%s",caste);
		
		if(( caste == 'open' || caste == 'OPEN') &&  tot >= 135 && ( CET >0.000000 || JEE > 0.000000) )	
			printf("\n You can take Admission for BTECH");
		else 
		if(( caste == 'obc' || caste == 'OBC') &&  tot >= 125 && ( CET >0.000000 || JEE > 0.000000) )	
			printf("\n You can take Admission for BTECH");
			
		else
		if(( caste == 'SBC' || caste == 'sbc') &&  tot >= 110 && ( CET >0.000000 || JEE > 0.000000) )	
			printf("\n You can take Admission for BTECH");
		
		else
		if(( caste == 'NT' || caste == 'nt'|| caste=='VJNT'|| caste =='vjnt') &&  tot >= 100 && ( CET >0.000000 || JEE > 0.000000) )	
			printf("\n You can take Admission for BTECH");
			
		else
		if(( caste == 'SC' || caste == 'sc' || caste == 'ST' || caste=='st') &&  tot >= 70 && ( CET >0.000000 || JEE > 0.000000) )	
			printf("\n You can take Admission for BTECH");
		
		else
			printf("\n You Can't take admission for BTECH");
		
		int choice;
		printf("\n Which District's collges tou want ? ");
		scanf("%d",&choice);
		
		char see;
		
		do
		{
			printf("\n The District of Engneering Colleges are : ");
			printf("\n 1. KOLHAPUR");
			printf("\n 2. PUNE");
			printf("\n 3. MUMBAI");
			printf("\n 4. SANGALI");
			
			switch( choice )
			{
				case 1;
					kohapur(caste);
					break;
				case 2:
					pune();
					break;
				case 3:
					mumbai();
					break;
				case 4:
					sangali();
					break;
					
				default:
					printf("\n Invalid Choice");
			}
		}
		
	}	
	
	return 0;
}
