#include<stdio.h>
#include<string.h>

typedef struct
{
	int ExpInc;
	int CashCard;
	float category;
	float amount;
	char comment[50];
	int date;
	int month;
	int year;
} user_entry;

typedef struct
{
	float cash, account;
} balance;

typedef struct
{
	float bud_week,bud_month,bud_on_the_go;
	char comments[40];
}goal;


FILE *fp, *fpt, *bud;
//fpos_t pos;

user_entry user, user1;
balance BAL;
goal G;

user_entry readscreen(user_entry user)
{
	int ch1, ch2; float c;

	printf("Enter a number from the menu:\n1.Expense\n2.Income\n");
	scanf("%d", &ch1);
	user.ExpInc=ch1;

	switch(ch1)
	{
		case 1:
		{
			printf("Enter a number from the menu:\n 1.Cash\n2.Card\n");
			scanf("%d", &ch2);
			user.CashCard=ch2;
	
			printf("Enter a number from the menu:\n");
			printf("1.Food\n2.Travel\n3.Bills\n4.Purchases\n5.Other\n");
			scanf("%d", &ch2);
			c=ch2;
			switch(ch2)
			{
				case 1:
				{
					printf("1.Fruits and Vegetables\n2.Groceries\n3.Eating Out\n");
					break;
				}
				case 2:
				{
					printf("1.Transport\n2.Repairs\n");
					break;
				}
				case 3:
				{
					printf("1.Rent\n2.Electricity Bill\n3.Education\n4.Telephone Bill\n5.Household Services\n");
					break;
				}
				case 4:
				{
					printf("1.Entertainment\n2.Clothing\n3.Books/Stationery\n4.Appliances\n5.Electronics\n");
					break;
				}
				case 5:
				{
					printf("1.Loans/insurance\n2.Pets\n3.Charity\n4.Personal\n5.Miscellaneous\n");
					break;
				}
			}
			scanf("%d", &ch2);
			c=c+(ch2/10.0);
			user.category=c;
			break;
		}
		case 2:
		{
			printf("Enter a number from the menu:\n 1.Cash\n2.Card: ");
			scanf("%d", &ch2);
			user.CashCard=ch2;
			break;
		}
	}

	printf("Amount: ");
	scanf("%f", &user.amount);

	printf("Comment (optional): ");
	scanf("%s", user.comment);

	printf("Date (dd): ");
	scanf("%d", &user.date);

	printf("Month (mm): ");
	scanf("%d", &user.month);

	printf("Year (yyyy): ");
	scanf("%d", &user.year);

	return (user);
}

void writefile1(user_entry user)
{
	fprintf(fp, "%d\n", user.ExpInc);
	fprintf(fp, "%d\n", user.CashCard);
	fprintf(fp, "%f\n", user.category);
	fprintf(fp, "%f\n", user.amount);
	fprintf(fp, "%s\n", user.comment);
	fprintf(fp, "%d\n", user.date);
	fprintf(fp, "%d\n", user.month);
	fprintf(fp, "%d\n", user.year);
}

user_entry read_file(FILE *fp)
{
	fscanf(fp,"%d", &user.ExpInc);
	fscanf(fp,"%d", &user.CashCard);
	fscanf(fp,"%f", &user.category);
	fscanf(fp,"%f", &user.amount);
	fscanf(fp,"%s", user.comment);
	fscanf(fp,"%d", &user.date);
	fscanf(fp,"%d", &user.month);
	fscanf(fp,"%d", &user.year);
	return(user);
}

void writefile2(balance BAL)
{
	fprintf(fpt, "%f\n", BAL.cash);
	fprintf(fpt, "%f\n", BAL.account);
}

void entries()
{
	fp=fopen("user_entries.dat", "a+");
	//fgetpos(fp, &pos);

	user.ExpInc=0;
	user.CashCard=0;
	user.category=0;
	user.amount=0;
	strcpy(user.comment,"");
	user.date=0;
	user.month=0;
	user.year=0;
	
	printf("Enter details as follows:\n");

	user=readscreen(user);
	writefile1(user);

	fclose(fp);
}

void balancecal()
{
	fp=fopen("user_entries.dat", "r");
	fpt=fopen("balance.dat", "w");

	BAL.cash=0;
	BAL.account=0;

	int ch, ct=0;
	do
	{
		ct=ct+1;

		user1=read_file(fp);
		/*printf ("ct= %d\n", ct); */

		/*if(ct==2||ct==3)
		{fseek(fp, 0, SEEK_CUR);}*/


		if(user1.ExpInc==1 && user1.CashCard==1)
		{
			BAL.cash=(BAL.cash)-(user1.amount); 
			printf("1, 1: cash: %f\n", BAL.cash);
		}
		else if(user1.ExpInc==1 && user1.CashCard==2)
		{
			BAL.account=(BAL.account)-(user1.amount); 
			printf("1, 2: acco: %f\n", BAL.account); 
		}
		else if(user1.ExpInc==2 && user1.CashCard==1)
		{
			BAL.cash=(BAL.cash)+(user1.amount); 
			printf("2, 1: cash: %f\n", BAL.cash);
		}
		else
		{
			BAL.account=(BAL.account)+(user1.amount); 
			printf("2, 2: acco: %f\n", BAL.account);
		}

		/*if(user1.ExpInc==1)
		{
			if(user1.CashCard==1)
			{	BAL.cash=(BAL.cash)-(user1.amount); 
				printf("1, 1: %f\n", BAL.cash);
			}
			else
			{	BAL.account=(BAL.account)-(user1.amount); 
				printf("1, 2: %f\n", BAL.account); 
			}
		}
		else
		{
			if(user1.CashCard==1)
			{	BAL.cash=(BAL.cash)+(user1.amount); 
				printf("2, 1: %f\n", BAL.cash); 
			}
			else
			{	BAL.account=(BAL.account)+(user1.amount); 
				printf("2, 2: %f\n", BAL.account); 
			}
		}*/
		/*if(user.CashCard==1)
		{
			if(user.ExpInc==2)
			{	BAL.cash=(BAL.cash)+(user.amount); 
				printf("1, 1: %f\n", BAL.cash); 
			}
			else
			{	BAL.cash=(BAL.cash)-(user.amount); 
				printf("1, 2: %f\n", BAL.cash); 
			}
		}
		else
		{
			if(user.ExpInc==2)
			{	BAL.account=(BAL.account)+(user.amount)	; 
				printf("2, 1: %f\n", BAL.account); 
			}
			else
			{	BAL.account=(BAL.account)-(user.amount); 
				printf("2, 2: %f\n", BAL.account); 
			}
		}*/	
	}while((ch=fgetc(fp))!=EOF);

	writefile2(BAL);	

	fclose(fpt);
	fclose(fp);

	fpt=fopen("balance.dat", "r");
	fscanf(fp, "%f", &BAL.cash);
	fscanf(fp, "%f", &BAL.account);

	printf("Cash balance= %f\n", BAL.cash);
	printf("Account balance= %f\n", BAL.account);
}

void budget_week()
{
	printf("\nEnter the weekly budget");
	scanf("%f",&G.bud_week);
	fprintf(bud,"%f",G.bud_week);
	fclose(bud);
}

void budget_month()
{
	printf("\nEnter the monthly budget");
	scanf("%f",&G.bud_week);
	fprintf(bud,"%f",G.bud_month);
	fclose(bud);
}

void budget_on_the_go()
{
	printf("\nEnter the on the go budget");
	scanf("%f",&G.bud_on_the_go);
	fprintf(bud,"%f",G.bud_on_the_go);
	printf("Enter the comments");
	scanf("%s",G.comments);
	fprintf(bud,"%s",G.comments);   fclose(bud);
}

void budget_menu()
{
	int cho;
	printf("\nMenu");
	printf("\n1.Weekly");
	printf("\n2.Monthly");
	printf("\n3.On The Go");
	scanf("%d",&cho);
	switch(cho)
	{
		case 1:
		budget_week();
		break;
		case 2:
		budget_month();
		break;
		case 3:
		budget_on_the_go();
		break;
		default:
		printf("\nWrong Choice entered");
	}
	bud=fopen("Budget.dat","w");
}

void month()
{
    FILE *fp;
    float sum=0;
    int yr,m,n;
    fp=fopen("user_entries.dat","r");
    printf("Enter year:\n");
    scanf("%d",&yr);
    printf("Enter month:\n");
    scanf("%d",&m);
    char cho;
    while((cho=fgetc(fp))!=EOF)
    {
        user_entry user1;
        user1=read_file(fp);
        if((user.year==yr)&&(user.month==m))
             sum+=user.amount;
        else break;
    }
    if(m!=2)
    {
        if(m<=7)
        {
            if(m%2==1)
                n=31;
            else
                n=30;
        }
        else
        {
            if(m%2==0)
                n=31;
            else
                n=30;
        }
    }
    else
    {
        if(yr%4==0)
            n=29;
        else
            n=28;
    }
    printf("Month total=%f\n",sum);
    float d_avg=sum/n;
    printf("Daily Average=%f\n",d_avg);
    float w_avg=d_avg*7;
    printf("Weekly Average=%f\n",w_avg);
    fclose(fp);
	
	if(w_avg>G.bud_week)
		printf("WEEKLY BUDGET EXCEEDED!\n");
}

void year()
{
    FILE *fp;
    float sum=0;
    fp=fopen("user_entries.dat","r");
    int yr;
    printf("Enter year:\n");
    scanf("%d",&yr);
    char cho;
    while((cho=fgetc(fp))!=EOF)
    {
        user_entry user2;
        user2=read_file(fp);
        if(user2.year==yr)
            sum+=user.amount;
        else break;
    }
    printf("Yearly total=%f\n",sum);
    float m_avg=sum/12;
    printf("Monthly Average=%f\n",m_avg);
    float w_avg=m_avg/4;
    printf("Weekly Average=%f\n",w_avg);
    fclose(fp);

	if(m_avg>G.bud_month)
		printf("MONTHLY BUDGET EXCEEDED!\n");
}

void food()
{
    FILE *fp1;
    int c,m,yr;
    float q;
    float sum=0;
    fp1=fopen("user_entries.dat","r");
    printf("FOOD MENU:\n");
    printf("1.Fruits and vegetables\n2.Groceries\n3.Eating out\n4.All\nEnter your option:\n");
    scanf("%d",&c);
    printf("Enter month:\n");
    scanf("%d",&m);
    printf("Enter year:\n");
    scanf("%d",&yr);
    if(c!=4)
    {
        char cho;
        user_entry user3;
        while((cho=fgetc(fp1))!=EOF)
        {
            user3=read_file(fp1);
            q=1+c/10.0;
            if((user3.month==m)&&(user3.category==q)&&(user3.year==yr))
            {
                sum=sum+user3.amount;
            }
        }
        char temp[30];
        switch(c)
        {
            case 1:strcpy(temp,"Fruits and Vegetables");break;
            case 2:strcpy(temp,"Groceries");break;
            case 3:strcpy(temp,"Eating out");break;
        }
        printf("Monthly amt spent on food/%s=%f\n",temp,sum);
        printf("Weekly avg spent on food/%s=%f\n",temp,sum/4.0);
    }
    else if(c==4)
    {
        char cho;
        user_entry user1;
        while((cho=fgetc(fp1))!=EOF)
        {
            user1=read_file(fp1);
            q=1+c/10.0;
            if((user1.month==m)&&(user1.year==yr))
                sum+=user.amount;
            else break;
        }
        printf("Monthly amt spent on all food=%f\n",sum);
        printf("Weekly avg spent on all food=%f\n",sum/4.0);
    }
    else
        printf("Invalid input! \n");
}
void travel()
{
    FILE *fp1;
    int c,m,yr;
    float q;
    float sum=0;
    fp1=fopen("user_entries.dat","r");
    printf("TRAVEL:\n");
    printf("1.Transport\n2.Repairs\n3.Both\nEnter your option:\n");
    scanf("%d",&c);
    printf("Enter month:\n");
    scanf("%d",&m);
    printf("Enter year:\n");
    scanf("%d",&yr);
    if(c!=3)
    {
        char cho;
        user_entry user3;
        while((cho=fgetc(fp1))!=EOF)
        {
            user3=read_file(fp1);
            q=2+c/10.0;
            if((user3.month==m)&&(user3.category==q)&&(user3.year==yr))
            {
                sum=sum+user3.amount;
            }
        }
        char temp[30];
        switch(c)
        {
            case 1:strcpy(temp,"Transport");break;
            case 2:strcpy(temp,"Groceries");break;
        }
        printf("Monthly amt spent on travel/%s=%f\n",temp,sum);
        printf("Weekly avg spent on travel/%s=%f\n",temp,sum/4.0);
    }
    else if(c==3)
    {
        char cho;
        while((cho=fgetc(fp1))!=EOF)
        {
            user_entry user1;
            user1=read_file(fp1);
            q=2+c/10.0;
            if((user1.month==m)&&(user1.year==yr))
                sum+=user.amount;
            else break;
        }
        printf("Monthly amt spent on all travel=%f\n",sum);
        printf("Weekly avg spent on all travel=%f\n",sum/4.0);
    }
    else
        printf("Invalid input! \n");
}

void bills()
{
    FILE *fp1;
    int c,m,yr;
    float q;
    float sum=0;
    fp1=fopen("user_entries.dat","r");
    printf("BILLS:\n");
    printf("1.Rents\n2.Electricity bills\n3.Education\n4.Telephone bills\n5.Household bills\n6.All\nEnter your option:\n");
    scanf("%d",&c);
    printf("Enter month:\n");
    scanf("%d",&m);
    printf("Enter year:\n");
    scanf("%d",&yr);
    if(c!=6)
    {
        char cho;
        user_entry user3;
        while((cho=fgetc(fp1))!=EOF)
        {
            user3=read_file(fp1);
            q=3+c/10.0;
            if((user3.month==m)&&(user3.category==q)&&(user3.year==yr))
            {
                sum=sum+user3.amount;
            }
        }
        char temp[30];
        switch(c)
        {
            case 1:strcpy(temp,"Rent");break;
            case 2:strcpy(temp,"Electricity bills");break;
            case 3:strcpy(temp,"Education");break;
            case 4:strcpy(temp,"Telephone bills");break;
            case 5:strcpy(temp,"Household bills");break;
        }
        printf("Monthly amt spent on Bills/%s=%f\n",temp,sum);
        printf("Weekly avg spent on Bills/%s=%f\n",temp,sum/4.0);
    }
    else if(c==6)
    {
        char cho;
        while((cho=fgetc(fp1))!=EOF)
        {
            user_entry user1;
            user1=read_file(fp1);
            q=3+c/10.0;
            if((user1.month==m)&&(user1.year==yr))
                sum+=user.amount;
            else break;
        }
        printf("Monthly amt spent on all bills=%f\n",sum);
        printf("Weekly avg spent on all bills=%f\n",sum/4.0);
    }
    else
        printf("Invalid input! \n");
}

void purchases()
{
    FILE *fp1;
    int c,m,yr;
    float q;
    float sum=0;
    fp1=fopen("user_entries.dat","r");
    printf("BILLS:\n");
    printf("1.Entertainment\n2.Clothing\n3.Books/Stationery\n4.Appliances\n5.Electronics\n6.All\nEnter your choice:\n");
    scanf("%d",&c);
    printf("Enter month:\n");
    scanf("%d",&m);
    printf("Enter year:\n");
    scanf("%d",&yr);
    if(c!=6)
    {
        char cho;
        user_entry user3;
        while((cho=fgetc(fp1))!=EOF)
        {
            user3=read_file(fp1);
            q=4+c/10.0;
            if((user3.month==m)&&(user3.category==q)&&(user3.year==yr))
            {
                sum=sum+user3.amount;
            }
        }
        char temp[30];
        switch(c)
        {
            case 1:strcpy(temp,"Entertainment");break;
            case 2:strcpy(temp,"Clothing");break;
            case 3:strcpy(temp,"Books/Stationery");break;
            case 4:strcpy(temp,"Appliances");break;
            case 5:strcpy(temp,"Electronics");break;
        }
        printf("Monthly amt spent on Purchases/%s=%f\n",temp,sum);
        printf("Weekly avg spent on Purchases/%s=%f\n",temp,sum/4.0);
    }
    else if(c==6)
    {
        char cho;
        while((cho=fgetc(fp1))!=EOF)
        {
            user_entry user1;
            user1=read_file(fp1);
            q=4+c/10.0;
            if((user1.month==m)&&(user1.year==yr))
                sum+=user.amount;
            else break;
        }
        printf("Monthly amt spent on all purchases=%f\n",sum);
        printf("Weekly avg spent on all purchases=%f\n",sum/4.0);
    }
    else
        printf("Invalid input! \n");
}
void other()
{
    FILE *fp1;
    int c,m,yr;
    float q;
    float sum=0;
    fp1=fopen("user_entries.dat","r");
    printf("OTHER:\n");
    printf("1.Loans/insurance\n2.Pets\n3.Charity\n4.Personal\n5.Miscellaneous\n6.All\nEnter your choice:\n");
    scanf("%d",&c);
    printf("Enter month:\n");
    scanf("%d",&m);
    printf("Enter year:\n");
    scanf("%d",&yr);
    if(c!=6)
    {
        char cho;
        user_entry user3;
        while((cho=fgetc(fp1))!=EOF)
        {
            user3=read_file(fp1);
            q=1+c/10.0;
            if((user3.month==m)&&(user3.category==q)&&(user3.year==yr))
            {
                sum=sum+user3.amount;
            }
        }
        char temp[30];
        switch(c)
        {
            case 1:strcpy(temp,"Loans/Insurance");break;
            case 2:strcpy(temp,"Pets");break;
            case 3:strcpy(temp,"Charity");break;
            case 4:strcpy(temp,"Personal");break;
            case 5:strcpy(temp,"Miscellaneous");break;
        }
        printf("Monthly amt spent on other expenses/%s=%f\n",temp,sum);
        printf("Weekly avg spent on other expenses/%s=%f\n",temp,sum/4.0);
    }
    else if(c==6)
    {
        char cho;
        while((cho=fgetc(fp1))!=EOF)
        {
            user_entry user1;
            user1=read_file(fp1);
            q=1+c/10.0;
            if((user1.month==m)&&(user1.year==yr))
                sum+=user.amount;
            else break;
        }
        printf("Monthly amt spent on all other expenses=%f\n",sum);
        printf("Weekly avg spent on all other expenses=%f\n",sum/4.0);
    }
    else
        printf("Invalid input! \n");
}

void reports()
{
	int choice;
      int c1;
    printf("REPORT MENU:\n");
    printf("1.Time Report\n2.Category report\n3.Balance\n");
    scanf("%d",&c1);
    if(c1==1)
    {
        int c2;
        printf("TIME REPORT MENU\n");
        printf("1.Monthly Report\n2.Yearly Report\nEnter your choice:\n");
        scanf("%d",&c2);
        switch(c2)
        {
            case 1:month();break;
            case 2:year();break;
            default:printf("Invalid input!\n");break;
        }
    }
    else if(c1==2)
    {
        int c3;
        printf("CATEGORY MENU:\n");
        printf("1.Food\n2.Travel\n3.Bills\n4.Purchases\n5.Other\nEnter your choice:\n");
        scanf("%d",&c3);
        switch(c3)
        {
            case 1:food();break;
            case 2:travel();break;
            case 3:bills();break;
            case 4:purchases();break;
            case 5:other();break;
            default:printf("Invalid input!\n");break;
        }
    }
    else if(c1==3)
	balancecal();
     else
		printf("Invalid input!\n");
}

void main()
{      
         printf("$	CLUTCH		$\nFOR ALL YOUR BUDGETING NEEDS\n\n\n"); 
        /*int a,t,f=0; 
        char phrase[7]={"CLUTCH"};
        for(a=0;a<7;a++)
           {
              printf("%c",phrase[a]);
              for(t=0;t<10000000;t++)
                 {
                    f++;
                 }
           }*/

	int ch;
	printf("Enter a number from the menu:\n1.Entry\n2.Reports\n3.Budgets\n");
	scanf("%d", &ch);

	switch(ch)
	{
		case 1:  entries(); break;
		case 2:  reports(); break;
		case 3:  budget_menu(); break;
	}

}
