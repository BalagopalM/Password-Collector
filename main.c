#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct timetable
{ char sub[50];
  char pass[50];
  char username[50]
} t1;
char fname[]={"USERNAME_PASSWORD.dat"};
void append();
void display();
void disp_all();
void del();
void mod();

int main()
{ char Access[10];
  int want=1;
 while(want)
{printf("ENTER THE ENTRY CODE:\n");
  scanf("%s",Access);
  if(strcmp(Access,"9393")==0)
   {  printf("ACCESS GRANDED");
      printf("\n\n\n\n\n\n\n\n\n\n");
      printf("                                                                                      ___           ____     ___     _    _     ___      \n");
      printf("                                                                            |    |   |       |     |        |   |   | \\  / |   |        \n");
      printf("                                                                            | /\\ |   |---    |     |        |   |   |  \\/  |   |---    \n");
      printf("                                                                            |/  \\|   |___    |___  |____    |___|   |      |   |___     \n");
      printf("\n");

    int ch;
while(1)
{
printf("\n\n\n\n");
printf(" ========================: MENU :==========================\n");
printf(" \"                          |                             \"\n");
printf(" \"                KEY       |     OPTION                  \"\n");
printf(" \"--------------------------|-----------------------------\"\n");
printf(" \"                 1.       |      Insert Data            \"\n");
printf(" \"                          |                             \"\n");
printf(" \"                 2.       |        Modify               \"\n");
printf(" \"                          |                             \"\n");
printf(" \"                 3.       |        Delete               \"\n");
printf(" \"                          |                             \"\n");
printf(" \"                 4.       |  Display Account Details:   \"\n");
printf(" \"                          |                             \"\n");
printf(" \"                 5.       |  Display Entire Data:       \"\n");
printf(" \"                          |                             \"\n");
printf(" \"                 0.       |         Exit                \"\n");
printf(" \"                          |                             \"\n");
printf(" \"=========================+=+============================\"\n\n");

printf("\n Please enter your Choice:");
scanf("%d",&ch);

switch(ch)
{
case 1: append();
        break;

case 2: modify();
        break;

case 3: del();
        break;


case 4: display();
        break;

case 5: display_all();
break;

case 0:
        printf("\n\n=================== : SIGNED OUT : ====================== ");
        printf("\n\n\n");
        exit(0);
}

}
   }
else
{ printf("ACCESS DENIED:\n");
    printf("WANT TO RE-ENTER PASSWORD? (0,1)");
    scanf("%d",&want);
   }
}
return 0;
}

void append()
{
 FILE *fp;
 fp=fopen(fname,"ab");

 printf("ENTER THE PLATFORM: ");
 scanf("%s",t1.sub);
 printf("\n");
 printf("ENTER THE USERNAME: ");
 scanf("%s",t1.username);
 printf("\n");
 printf("ENTER PASSWORD: ");
 scanf("%s",t1.pass);
 fwrite(&t1,sizeof(t1),1,fp);
 fclose(fp);
}

void display()
{ FILE *fp;
  struct timetable t1;
  int choice=1;
  int found=0;
  char str_sub[10];
  while(choice)
  { fp=fopen(fname,"rb");
    printf("ENTER THE PLATFORM: ");
    scanf("%s",str_sub);
    while(1)
    { fread(&t1,sizeof(t1),1,fp);
      if(feof(fp))
      { break;
      }
      if(strcmpi(t1.sub,str_sub)==0)
      {   found=1;
          printf("\n\n================ ACCOUNT DETAILS ==================\n\n\n");
          printf("SITE:     ");
          printf("%s",t1.sub);
          printf("\n");
          printf("EMAIL_ID: ");
          printf("%s",t1.username);
          printf("\n");
          printf("PASSWORD: ");
          printf("%s",t1.pass);
          printf("\n");
          fclose(fp);
          break;
      }
    }
    if(found==0)
    { printf("======================SORRY,NO SUCH RECORD:==================\n\n");
        fclose(fp);
    }
    printf("\n");
    printf("WANT TO CONTINUE DISPLAYING DATA?(0,1)\n");
   scanf("%d",&choice);
   if(choice==0)
   {return;
   }
  }
}

void modify()
{ FILE *fp,*fp1;
   struct timetable t;
  int found=0;
  fp=fopen(fname,"rb");
  fp1=fopen("TEMP_ACCOUNT.dat","wb");
  char search[20];
  printf("\nENTER THE DATA TO BE MODIFIED: ");
  scanf("%s",search);
  while(1)
  { fread(&t,sizeof(t),1,fp);
    if(feof(fp))
    { fclose(fp);
      fclose(fp1);
      break;

    }
    if(strcmp(t.sub,search)==0)
    {found=1;
     printf("ENTER THE PLATFORM: ");
     scanf("%s",t.sub);
     printf("\n");
     printf("ENTER THE USERNAME: ");
     scanf("%s",&t.username);
     printf("\n");
     printf("ENTER THE PASSWWORD: ");
     scanf("%s",&t.pass);
     fwrite(&t,sizeof(t),1,fp1);

    }
    else
    { fwrite(&t,sizeof(t),1,fp1);

    }
  }
    if(found==0)
    { printf("===================SORRY,NO RECORDS TO DISPLAY=================");

    }
    else
    { fp=fopen(fname,"wb");
      fp1=fopen("TEMP_ACCOUNT.dat","rb");
      while(1)
      { fread(&t,sizeof(t),1,fp1);

         if(feof(fp1))
         {fclose(fp);
          fclose(fp1);
          break;
         }

        fwrite(&t,sizeof(t),1,fp);

      }

    }

}


void display_all()
{ FILE *fp;
  struct timetable t;

  fp=fopen(fname,"rb");
  printf("\n");
  printf("      ========== :ENTIRE ACCOUNT DETAILS: ==========\n\n");
  printf("\n     \SITE\t\t|\tUSERNAME\t|\tPASSWORD\t\t\n");
  printf("------------------------------------------------------------\n");
  while(1)
  { fread(&t,sizeof(t),1,fp);
    if(feof(fp))
    {fclose(fp);
     break;}

    printf("%s\t\t",t.sub);
    printf("%s\t\t",t.username);
    printf("%s\t\t",t.pass);
    printf("\n\n");

  }

}
void del()
{ FILE *fp,*fp1;
   struct timetable t;
  int found=0;
  fp=fopen(fname,"rb");
  fp1=fopen("TEMP_ACCOUNT.dat","wb");
  char search[20];
  printf("\nENTER THE DATA TO BE DELETED FROM RECORD: ");
  scanf("%s",search);
  while(1)
  { fread(&t,sizeof(t),1,fp);
    if(feof(fp))
    { fclose(fp);
      fclose(fp1);
      break;

    }
    if(strcmp(t.sub,search)!=0)
    {found=1;
     fwrite(&t,sizeof(t),1,fp1);
    }
  }
    if(found==0)
    { printf("=================== :SORRY,NO SUCH RECORD :===================\n");

    }
    else
    { fp=fopen(fname,"wb");
      fp1=fopen("TEMP_ACCOUNT.dat","rb");
      while(1)
      { fread(&t,sizeof(t),1,fp1);

         if(feof(fp1))
         {fclose(fp);
          fclose(fp1);
          break;
         }

        fwrite(&t,sizeof(t),1,fp);

      }

    }

}

