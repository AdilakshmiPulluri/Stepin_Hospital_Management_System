void newrecord(int l)
{
	char q;
	p.sn=l;
	displaydepartment();
	
	cprintf("Record of patient no:");
	printf(" %d",l);
	
	cprintf("Name:");

	
	cprintf("Address:");

	
	cprintf("Age: ");

	
	cprintf("Sex(m/f): ");

	
	cprintf("Disease Descrp:");
	
	cprintf("(In Short)");

	
	cprintf("Reff. Specialist no:");
	fflush(stdin);
	scanf("%[^\n]",p.name);
	p.name[0]=toupper(p.name[0]);

	fflush(stdin);
	scanf("%[^\n]",p.address);

	fflush(stdin);
	scanf("%d",&p.age);
	
	fflush(stdin);
	scanf("%c",&p.ch);
	fflush(stdin);
	scanf("%[^\n]",p.disease);
}
char* exitt(void)
{
	/*system("cls");
	printf("EXITING THE PROGRAM ");*/
	char* message="EXITING THE PROGRAM";
    return message;
	 
}
