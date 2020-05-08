//Hangman Game in C Language
// Copyright Shubhadeep Mandal, Soubhik Maji and Soumya Koley

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    char ch='y';
	while(ch=='y'||ch=='Y')
	{
    char ans[100],alpha[100],display[100],name[100],s;
    int c=3,match=0,count=0,pos=0,w,length,i,ch;
    printf("Enter your Name : ");
    scanf("%[^\n]s",name);
    system("cls");
    printf("Hello %s !! \nYou are requested to choose any question topic of your choice from the options mentioned below\n",name);
    printf("\nPress 1 to Guess the Company's Name \nPress 2 to Guess the Flower's Name \nPress 3 to Guess the Bird's Name \nPress 4 to Guess the Animal's Name \nPress 5 to Guess the City's Name \nPress 6 for Custom Guess\n");
    printf("Enter your Choice : ");
    scanf("%d",&ch);

    switch(ch)
    {
    case 1:
        {
        strcpy(ans,"apple");
        system("cls");
        printf("Question : Guess Who ?\n");
        printf("\n[ Hint : It is an American multinational technology company headquartered in Cupertino, California, that designs, develops, and sells consumer electronics, computer software, and online services. It is considered one of the Big Four of technology along with Amazon, Google, and Facebook. ]\nPress Enter to Continue");
        getchar();
        break;
        }
    case 2:
        {
        strcpy(ans,"tulip");
        system("cls");
        printf("Question : Guess Who ?\n");
        printf("\n[ Hint : They form a genus of spring-blooming perennial herbaceous bulbiferous geophytes. The flowers are usually large, showy and brightly coloured, generally red, pink, yellow, or white. They often have a different coloured blotch at the base of the tepals, internally. ]\nPress Enter to Continue");
        getchar();
        break;
        }
    case 3:
        {
        strcpy(ans,"eagle");
        system("cls");
        printf("Question : Guess Who ?\n");
        printf("\n[ Hint : It is the common name for many large birds of prey of the family Accipitridae. They belong to several groups of genera, not all of which are closely related. Most of the 60 species of them are from Eurasia and Africa. ]\nPress Enter to Continue");
        getchar();
        break;
        }
    case 4:
        {
        strcpy(ans,"tiger");
        system("cls");
        printf("Question : Guess Who ?\n");
        printf("\n[ Hint : It is the largest species among the Felidae and classified in the genus Panthera. It is most recognizable for its dark vertical stripes on reddish-orange fur with a lighter underside. It is an apex predator, primarily preying on ungulates such as deer and bovids. ]\nPress Enter to Continue");
        getchar();
        break;
        }
    case 5:
        {
        strcpy(ans,"mumbai");
        system("cls");
        printf("Question : Guess Who ?\n");
        printf("\n[ Hint : It is a densely populated city on India’s west coast. A financial center, it's India's largest city. ]\nPress Enter to Continue");
        getchar();
        break;
        }
    case 6:
        {
        printf("\nEnter the Answer (in lower case only) : ");
        scanf("%s",ans);
        getchar();
        char hint[500];
        printf("\nNow, Enter your Hint : ");
        scanf("%[^\n]s",hint);
        getchar();
        system("cls");
        printf("Question : Guess Who ?\n");
        printf("\n[  Hint : %s ]\nPress Enter to Continue",hint);
        break;
        }
    default:
        printf("Error !! Please enter a number between 1 to 6");
    }
    getchar();
    length=strlen(ans);

    //system("cls");
    printf("\n\nYou will get 3 chances to guess the right answer \nPress Enter to Continue");
    getchar();

    printf("\n\n\nThe word has %d alphabets\n",length);
    for(i=0;i<length;i++)
    {
        display[i]='*';
        display[length]='\0';
    }

    for(i=0;i<length;i++)
    {
        printf(" ");
        printf("%c",display[i]);
    }
    while(c!=0)
    {
        match=0;
        printf("\n\nEnter any alphabet from a to z : ");
        scanf("%c",&s);
    if(s<'a'||s>'z')
    {
        printf("\nWrong Input !! Please enter alphabet from a to z Only");
        match=2;
    }

    if (match!=2)
    {
        for(count=0;count<length;count++)
	    {
		    if(s==ans[count])
		     {
		       match=1;
		       //printf("\n Great !! Move On");
             }
        }

	   if(match==0)
	    {
     	      printf("\nWrong Guess !! You have %d tries left\n",--c);
	          getchar();
	    }
	   else
	   {
	     for(count=0;count<length;count++)
             {
     	         match=0;
              if(s==ans[count])
                {
                    pos=count ;
                    match=1;
                }
    	      if(match==1)
	          {
                 for(i=0;i<length;i++)
                 {
                      if(i==pos)
                  	  {
                          display[i]=s;
                      }
                      else if(display[i]>='a'&&display[i]<='z')
                      {
                          continue;
                  	  }
                      else
                      {
                          display[i]='*';
                      }
                }
                alpha[pos]=s;
                alpha[length]='\0';
                w=strcmp(alpha,ans);

                if(w==0)
                {
                    printf("\nCongratulations !!");
                    printf("\nYou made the right guess, The Answer was : %s \n",ans);
                    getchar();
                    return 0;
                }
            }
        }
    }
}

    printf("\n");
    for(i=0;i<length;i++)
      {
          printf(" ");
          printf("%c",display[i]);
      }
      getchar();
      }

      if(c<=0)
      {
          printf("\nSorry !!");
          printf("\nYou failed to guess the right answer, The Answer was : %s \n",ans);
      }
		fflush(stdin);
		printf("\n\nDo you want to Continue?(Y/N): ");
		scanf("%c",&ch);
		return 0;
	}
return 0;
}
