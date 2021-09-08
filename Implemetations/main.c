int main()
{
   int a,i,n,y;
	char c,d;
	char date1[15],date2[15],string1[20];
	unsigned int tsz;

	clrscr();
	mainscreen();
	label3:
	printf("*******Welcome To ********);
	printf("*****8ABC hospital***");
	printf("Enter today's Date(yyyy/mm/dd)");
	fflush(stdin);
	scanf("%[^\n]",date2);
	if((date2[4]!='/')||(date2[7]!='/')||(date2[5]>'3')||(date2[8]>'3'))
	{
		clrscr();
		mainscreen();
		
		cprintf("Wrong Entry");
		goto label3;
	}
	clrscr();
	mainscreen();
	label1:


	lowvideo();
	cprintf("Enter the corresponding no");
	cprintf("1.Add new patient record");
	cprintf("2.Search  or edit record");
	cprintf("3.Know the records of patients");
	cprintf("4.Delete the records");
	cprintf("5.Exit from the program");
	fflush(stdin);
	scanf("%c",&d);
	switch(d)
	{
		case '1':
		      {

			{
				if((fp=fopen(fn1,"rb"))==NULL)
				s=1;
				else
				{
				while(fread(&p,sizeof(ABC),1,fp))
				s=1+p.sn;
				}
				fclose(fp);
			}
			clrscr();
			mainscreen();
			label:
		
			cprintf("Enter `o' for O.P.D. & `e'for Emergency");
			
			fflush(stdin);
			scanf("%c",&c);
			if(c=='o')
			{
				clrscr();
				mainscreen();
				
				cprintf("ADDING NEW O.P.D.PATIENT RECORD");
				
				cprintf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
				newrecord(s);
				newrecord1();

				if((fp=fopen(fn1,"ab+"))==NULL)
				{
					printf("Cannot open the file f1");
					getch();
					exit(1);
				}
				for(a=0;a<15;a++)
				p.testfee[a]=0;
				strcpy(&p.test[1][0],"0");
				p.totalfee=0;p.balance=0;
				strcpy(&p.test[0][0],"O.P.D. charge");
				p.testfee[0]=200;

				p.totalfee=200;
				strcpy(p.category,"O.P.D.Patient");
				p.balance=200;
				strcpy(p.recommendation,"Admitted to O.P.D.");
				strcpy(p.date,date2);
				fwrite(&p,sizeof(p),1,fp);
				fclose(fp);
				if((fp=fopen(fn2,"ab+"))==NULL)
				{
						printf("Cannot open the file f1");
						getch();
						exit(1);
				}
				fwrite(&p,sizeof(p),1,fp);
				fclose(fp);


			}
			else if(c=='e')
			       {
				 clrscr();
				 mainscreen();
				
				 cprintf("ADDING NEW EMERGENCY PATIENT RECORD");
				 
				 cprintf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
				 newrecord(s);
				 newrecord1();
				 if((fp=fopen(fn1,"ab+"))==NULL)
					{
						printf("Cannot open the file f1");
						getch();
						exit(1);
					}
					for(a=0;a<15;a++)
					p.testfee[a]=0;
					strcpy(&p.test[1][0],"0");
					p.totalfee=0;p.balance=0;

			       p.totalfee=250;
			       strcpy(p.date,date2);
			       strcpy(&p.test[0][0],"Emergency Charge");
			       strcpy(p.category,"Emergency Patient");
			       strcpy(p.recommendation,"Admitted to Emergency");
			       p.testfee[0]=250;
			       p.balance=250;
			       fwrite(&p,sizeof(p),1,fp);
			       fclose(fp);
			      if((fp=fopen(fn2,"ab+"))==NULL)
				{
						printf("Cannot open the file f1");
						getch();
						exit(1);
				}
				fwrite(&p,sizeof(p),1,fp);
				fclose(fp);

			       }
			else
			{
				clrscr();
				mainscreen();
			
				cprintf("Wrong choice");
				
				goto label;
			}
			break;
		      }
		case '2':
		      {
		       clrscr();
		       mainscreen();
		       editrecord();
		       break;
		      }
		case '5':
		      {
			clrscr();
			mainscreen();
			
			cprintf("THANK U");gotoxy(30,26);
		       	cprintf("SAVING UR SETTINGS"); 
			cprintf("BYE...........");
			getch();
			exit(1);
			break;
			}
		case '4':
			{
				if((fp=fopen(fn1,"rb"))==NULL)
				{
					printf("cannot open the file");
					getch();
					exit(1);
				}

				if((f1=fopen("delete","wb"))==NULL)
				{
					printf("cannot open the file");
					getch();
					exit(1);
				}

				clrscr();
				mainscreen();
				 cprintf("patient no");
				
			       fflush(stdin);
				scanf("%d",&y);
				while(fread(&p,sizeof(ABC),1,fp))
					if(p.sn!=y)
					fwrite(&p,sizeof(ABC),1,f1);
				clrscr();
				mainscreen();
				fseek(fp,(y-1)*sizeof(ABC),SEEK_SET);
				fread(&p,sizeof(ABC),1,fp);
				print();
				edit1();
				//gotoxy(25,46);
				cprintf("Press `ENTER' to delete this record");
				getch();
				fclose(fp);
				fclose(f1);
				remove(fn1);
				rename("delete",fn1);

				if((fp=fopen(fn2,"rb"))==NULL)
				{
					printf("cannot open the file");
					getch();
					exit(1);
				}

				if((f1=fopen("delete","wb"))==NULL)
				{
					printf("cannot open the file");
					getch();
					exit(1);
				}
				while(fread(&p,sizeof(ABC),1,fp))
					if(p.sn!=y)
					fwrite(&p,sizeof(ABC),1,f1);



				fclose(fp);
				fclose(f1);
				remove(fn2);
				rename("delete",fn2);
				clrscr();
				mainscreen();
			
				cprintf("Record succesfully Deleted");
				getch();
			
				break;
			}


		case '3':
			{       label6:
				clrscr();
				mainscreen();
				
				cprintf("Enter the corresponding no");
				cprintf("1.Records of patients in alphabatecal order");
				cprintf	("2.Records of Emergency //patients");
				cprintf("3.Records of  patients");

				cprintf("4.Recordsin paricular date");
				cprintf("5.Return to main menu");

				fflush(stdin);
				scanf("%c",&d);
				switch(d)
				{
				case '1':
					{
					 if((fp=fopen(fn2,"rb+"))==NULL)
					      {
						printf("Cannot open the file");
						getch();
						exit(1);
					      }
					 fseek(fp,0,SEEK_END);
					 tsz=ftell(fp);
					 n=(int)(tsz/sizeof(ABC));
					 for(i=0;i<(n-1);i++)
					 {
						for(a=i+1;a<n;a++)
						{
						fseek(fp,i*sizeof(ABC),SEEK_SET);
						fread(&p,sizeof(ABC),1,fp);
						fseek(fp,a*sizeof(ABC),SEEK_SET);
						fread(&q,sizeof(ABC),1,fp);
						if(strcmp(p.name,q.name)>0)
							{
							fseek(fp,i*sizeof(ABC),SEEK_SET);
							fwrite(&q,sizeof(ABC),1,fp);
							fseek(fp,a*sizeof(ABC),SEEK_SET); fflush(stdin);
							fwrite(&p,sizeof(ABC),1,fp);
							}
						}
					}
					rewind(fp);
					clrscr();
					mainscreen();
					
					cprintf("Ready to Display the patient records according to alphabatecal order of names");
					
					cprintf("Press");
					cprintf(" `Enter' ");  
					cprintf("to continue");
					getch();
					while(fread(&p,sizeof(ABC),1,fp))
					{
					clrscr();
					mainscreen();
					print();
				
					cprintf("DISPLAYING-RECORD-ACCORDING-TO-PATIENTS-NAMES");
					
					cprintf("---------------------------------------------");
					edit1();

					
					cprintf("Press");
					cprintf(" `Enter'"); 
					cprintf(" for next and `r' to quit: ");
					scanf("%c",&c);

					if(c=='r')
					{
					goto label6;

					}
				
					getch();

				}
				clrscr();
				mainscreen();
			
				cprintf("::No Further Records::");
				getch();
				fclose(fp);
				break;
				}
			case '5':
				{
				clrscr();
				mainscreen();
				 goto label1;
				 }
			case '2':
				{
				clrscr();
				mainscreen();
				if((fp=fopen(fn1,"rb"))==NULL)
					      {
						printf("Cannot open the file");
						getch();
						exit(1);
					      }
				
			
				cprintf("Ready to Display records of Emergency Patients");
				
				cprintf("Press");
				cprintf(" `Enter' ");
				cprintf("to continue");
				getch();
				while(fread(&p,sizeof(ABC),1,fp))
				{
					if(strcmp(p.category,"Emergency Patient")==NULL)
					{
					clrscr();
					mainscreen();
					print();
					
					cprintf("::DISPLAYING-RECORDS-OF-EMERGENCY-PATIENTS::");
					
					cprintf("---------------------------------------------");
					edit1();

					cprintf("Press");
					cprintf(" `Enter'");
					cprintf(" for next and `r' to quit: ");
					scanf("%c",&c);

					if(c=='r')
					{
					goto label6;
					}
					
					getch();
					}
				}
				clrscr();
				mainscreen();
				
				cprintf("::No Further Records::"); 
				getch();
				fclose(fp);
				break;
				}
			case '3':
				{
				clrscr();
				mainscreen();
				if((fp=fopen(fn1,"rb"))==NULL)
					      {
						printf("Cannot open the file");
						getch();
						exit(1);
					      }
				
				cprintf("Ready to Display records of O.P.D Patients");
				
				cprintf("Press");
				cprintf(" `Enter' "); 
				cprintf("to continue");
				getch();
				while(fread(&p,sizeof(ABC),1,fp))
				{
					if(strcmp(p.category,"O.P.D.Patient")==NULL)
					{
					clrscr();
					mainscreen();
					print();
				
					cprintf("::DISPLAYING-RECORDS-OF-OPD-PATIENTS::");
					
					cprintf("---------------------------------------------");
					edit1();
					
					cprintf("Press");
					cprintf(" `Enter'");
					cprintf(" for next and `r' to quit: ");
					scanf("%c",&c);

					if(c=='r')
					{
					goto label6;
					}
					
					getch();
					}
				}
				clrscr();
				mainscreen();
				
				cprintf("::No Further Records::");
				fclose(fp);
				break;
				}
		case '4':
				{
				clrscr();
				mainscreen();
				if((fp=fopen(fn1,"rb"))==NULL)
					      {
						printf("Cannot open the file");
						getch();
						exit(1);
					      }
				label8:
			
				cprintf("Enter the `Date' of a paricular day(yyyy/mm/dd)");
				
fflush(stdin);
				scanf("%s",string);
				if((string[4]!='/')||(string[7]!='/')||(string[5]>'3')||(string[8]>'3'))
				{
				clrscr();
				mainscreen();
				cprintf("Wrong Entry");
				goto label8;
				}
			       //	getch();
				while(fread(&p,sizeof(ABC),1,fp))
				{
					if(strcmp(string,p.date)==NULL)
					{
					clrscr();
					mainscreen();
					print();
					
					cprintf("::DISPLAYING-RECORDS-OF-");
					cprintf("DATE >%s",p.date);
				
					cprintf("---------------------------------------------");
					edit1();

					
					cprintf("Press");
					cprintf(" `Enter'");
					cprintf(" for next and `r' to quit: ");
					scanf("%c",&c);

					if(c=='r')
					{
					goto label6;
					}
					
					getch();
					}
				}
				clrscr();
				mainscreen();
				
				cprintf("::No Further Records::");  
				getch();
				fclose(fp);
				break;
				}

			default:
				{
				clrscr();
				mainscreen();
			
				cprintf("Wrong choice");
				 cprintf("Retypng choice");

				goto label6;
				}
			}
		}break;





		default:
		       {
			clrscr();
			mainscreen();
		
			cprintf("Wrong choice");

			 cprintf("Retype choice");
			goto label1;
			}

	}
	clrscr();
	mainscreen();
	goto label1;

    return 0;
}
