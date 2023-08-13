#include <stdio.h>
#include <stdlib.h>
struct variables
{
    int book_count;
};

struct book_info
{
    char book_name[20];
    char author_name[30];
    int code;
    int copies;
}b[100];

struct info
{
    char name[30];
    char usn[30];
    int books_taken;
    int books_given;
}info;

struct info s;

void add_student()
{
   FILE *fp;
   struct info s;
   int temp1=0;
   s.books_taken=0;
   s.books_given=0;
   printf("\n\t\t\t\t\t Enter the students name: ");
   scanf("%s",s.name);
   while(temp1==0)
   {
       printf("\nEnter the usn: 1SI");
       scanf("%s",s.usn);
       if(isalpha(s.usn[0])!=0||isalpha(s.usn[1])!=0||isdigit(s.usn[2])!=0||isdigit(s.usn[3])!=0||isalpha(s.usn[4])!=0||isalpha(s.usn[5])!=0||isalpha(s.usn[6])!=0)
           {
             printf("You have entered a wrong USN, Please fill the usn once again!\n");
             temp1=0;
           }
        else
            temp1=1;
   }

   fp=fopen(s.usn,"w");
   fprintf(fp,"%s\n1SI%s\n%d\n%d",s.name,s.usn,s.books_taken,s.books_given);
   fclose(fp);
}

void search_student()
{
    FILE *fp;
    char u[20];
    char nam[30],us[40];
    int bt,bg;
    int temp1=0;
  //  printf("Enter the usn of the student: 1SI");
    while(temp1==0)
   {
       printf("\nEnter the usn of the student: 1SI");
       scanf("%s",u);
       if(isalpha(u[0])!=0||isalpha(u[1])!=0||isdigit(u[2])!=0||isdigit(u[3])!=0||isalpha(u[4])!=0||isalpha(u[5])!=0||isalpha(u[6])!=0)
           {
             printf("You have entered a wrong USN, Please fill the usn once again!\n");
             temp1=0;
           }
        else
            temp1=1;
   }
    fp=fopen(u,"r");
    fscanf(fp,"%s%s%d%d",nam,us,&bt,&bg);
    printf("name: %s\nusn: %s\nBooks Taken: %d\nBooks given: %d\n",nam,us,bt,bg);
    fclose(fp);
}
void add_books()
{
    FILE *fp;
    int book_count;
    int temp=0;
    int n,i;
    printf("Enter the number of books to be added: ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
    fp=fopen("variables","r");
    fscanf(fp,"%d",&book_count);
    fclose(fp);
    printf("\nEnter the name of the book: ");
    scanf("%s",b[book_count].book_name);
    printf("\nEnter the author name: ");
    scanf("%s",b[book_count].author_name);
    printf("\nEnter the book code: ");
    scanf("%d",&b[book_count].code);
    printf("\nEnter the copies of book: ");
    scanf("%d",&b[book_count].copies);
    fp=fopen("Books_information","r");
    if(fp==NULL)
        temp=1;
     fclose(fp);
        if(temp==1)
        {
            fp=fopen("Books_information","w");
            fclose(fp);
        }
      fp=fopen("Books_information","a");
      fprintf(fp,"%s\t%s\t%d\t%d\n",b[book_count].book_name,b[book_count].author_name,b[book_count].code,b[book_count].copies);
      fclose(fp);
    book_count++;
    printf("\nBooks added: %d\n",book_count);
    fp=fopen("variables","w");
    fprintf(fp,"%d",book_count);
    fclose(fp);
    }

}
void books_count(){}
void issue_books(){}
void return_books(){}

int main()
{
    for(;;){
    struct variables v;
    FILE *fp1;
    int temp=0;
    fp1=fopen("variables","r");
    if(fp1==NULL)
        temp=1;
        fclose(fp1);
        if(temp==1)                        // Creating a variable file
        {
            fp1=fopen("variables","w");
            v.book_count=0;
            fprintf(fp1,"%d",v.book_count);
            fclose(fp1);
        }
        int choice;
       system("cls");
    printf("\n\t\t\t\t\t\t---------------------------------\t\t\t\t\t\n");
    printf("\t\t\t\t\t\t\tLibrary Management\t\t\t\t\t\t");
    printf("\n\t\t\t\t\t\t\t     System\t\t\t\t\t");
    printf("\n\t\t\t\t\t\t---------------------------------\t\t\t\t\t");
    printf("\n\n\n\t\t\t\t\t\t Enter any key to continue....");
    getch();
    system("cls");
    printf("\n\t\t\t\t\t\t---------------------------------\t\t\t\t\t\n");
    printf("\t\t\t\t\t\t\tLibrary Management\t\t\t\t\t\t");
    printf("\n\t\t\t\t\t\t\t     System\t\t\t\t\t");
    printf("\n\t\t\t\t\t\t---------------------------------\t\t\t\t\t");
    printf("\n\n\n\n");
    printf("\t\t\t\t\t\t\t1.Add Student\n");
    printf("\t\t\t\t\t\t\t2.Search Student\n");
    printf("\t\t\t\t\t\t\t3.Add Books\n");
    printf("\t\t\t\t\t\t\t4.Book Count\n");
    printf("\t\t\t\t\t\t\t5.Issue Books\n");
    printf("\t\t\t\t\t\t\t6.Return Books\n");
    printf("\n\n\n\t\t\t\t\t\t  Enter your choice ");
    scanf("%d",&choice);
    system("cls");
    printf("\n\t\t\t\t\t\t---------------------------------\t\t\t\t\t\n");
    printf("\t\t\t\t\t\t\tLibrary Management\t\t\t\t\t\t");
    printf("\n\t\t\t\t\t\t\t     System\t\t\t\t\t");
    printf("\n\t\t\t\t\t\t---------------------------------\t\t\t\t\t");
    printf("\n\n\n\n");
        switch(choice)
        {
            case 1: add_student();
                    break;
            case 2: search_student();
                    break;
            case 3: add_books();
                    break;
            case 4: books_count();
                    break;
            case 5: issue_books();
                    break;
            case 6: return_books();
                    break;
            default: printf("Invalid choice");
        }
    }
    return 0;
}
