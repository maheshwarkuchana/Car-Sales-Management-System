#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 20 // maximum number of orders can be given

int hc = 100, ma = 100, sp = 100, ar = 100, la = 100, vq = 100, pb = 100, gc = 100, ts = 100, oa = 100; //maximum quatities of cars

// This is the declaration of Order list in queue using linked list

struct Node
{
  char data[2];
  int required;
  struct Node *next;
} *front = NULL, *rear = NULL;

// Priority Queue in which the model by popularity is stored

struct node
{
  int priority;
  char data[2];
  struct node *link;
} *Front = NULL;

void insert(char[]);
void deleted(int);
void display();
void Orders();
void modelByPopularity();
void modelByPrice();
int dataBase(char data[2], int);

void SortingPopularity(char[], int);
void displayPopularity();
void sortingPriority();

int main()
{
  int x, y;
  printf("\n");
  printf("\n");
  printf("\t \t \t \t \t\t\tLa Voiture\n");
  printf("\t\t\t\t\t______________________________________________");
  printf("\n");
  printf("\n\t\t\t\t\t  Welcome to Global Car Sales Company and Co.\n");
  printf("\t\t\t\t\t______________________________________________");
  int choice;
  printf("\n");
  printf("\n");
  printf("\n");
  printf("\t \t * * * * * * * * * * * * * * * * * * * * Take Orders * * * * * * * * * * * * * * * * * * * *\n");
  printf("\n");
  printf("\t\t\t\t\t\tEnter 1 to access the Main Menu :  ");
  scanf("%d", &choice);
  switch (choice)
  {
  case 1:
    Orders();
    break;
  }
  return 0;
}

void Orders()
{
  int choice;
  char img[1];
  char ch;
  char value[2];
  //printf("\n:: Orders ::\n");
  while (1)
  {
    system("COLOR 07");

    printf("\n\t\t\t\t\t****** MENU ******\n");
    printf("\t\t\t\t\t1. Add an order\n\t\t\t\t\t2. Delete the given Order\n\t\t\t\t\t3. Display all the orders\n");
    printf("\t\t\t\t\t4. Model By Popularity\n");
    printf("\t\t\t\t\t5. Model By Price\n");
    printf("\t\t\t\t\t6. Exit\n");
    printf("\n");
    printf("\t\t\tEnter your choice :  ");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
    again:
      printf("\n\n\n \t\t\t ----Choose any car\n");
      printf("\n");

      // Cars List Represented here
      printf("\t\t\t\t  1)Huracan Coupe                 (hc)          Rs.3,97,00,000/- \n");
      printf("\t\t\t\t  2)Mercedes AMG                  (ma)          Rs.77,50,000/- \n");
      printf("\t\t\t\t  3)488 Spider                    (sp)          Rs.1,76,53,234/- \n");
      printf("\t\t\t\t  4)Audi R8                       (ar)          Rs.2,47,00,000/- \n");
      printf("\t\t\t\t  5)Lamborghini Aventador         (la)          Rs.2,54,85,845/- \n");
      printf("\t\t\t\t  6)Aston Martin Vanquish S       (vq)          Rs.3,85,00,000/- \n");
      printf("\t\t\t\t  7)Porsche Boxster 718           (pb)          Rs.92,02,000/- \n");
      printf("\t\t\t\t  8)Maserati GranCabrio           (gc)          Rs.1,98,00,000/- \n");
      printf("\t\t\t\t  9)Tesla Model 3                 (ts)          Rs.53,23,548/- \n");
      printf("\t\t\t\t  10)Aston Martin Vantage AMR     (oa)          Rs.1,22,53,105/- \n");

      while (1)
      {
        printf("\nEnter the code corresponding to the car you have selected : ");
        scanf("%s", value);

        int rfdb = dataBase(value, 0); //rfdb is returning from database
        if (rfdb == 0)
        {
          printf("\nItem found. Proceeding further....\n\n");
          break;
        }
        else
        {
          system("COLOR FC");

          printf("Item not found in database. Please select from the given list of cars!\n");
        }
      }

      // Here the image (external file) is invoked using system() : command

      system("COLOR 07");
      printf("To get a glance of the Selected car, Enter the corresponding index :  ");
      scanf("%s", img); //here img is the index of the selected car in the given list
      system(strcat(img, ".jpg"));

      printf("\nAre you sure you want to select this car (y/n) : ");
      fflush(stdin);
      scanf("%c", &ch);
      fflush(stdin);
      if (ch == 'y' || ch == 'Y')
      {
        insert(value);
      }
      else if (ch == 'n' || ch == 'N')
      {
        goto again;
      }
      break;
    case 2:
      deleted(1);
      break;
    case 3:
      display();
      break;
    case 4:
      modelByPopularity();
      break;
    case 5:
      modelByPrice();
      break;
    case 6:
      exit(0);
    default:
      system("COLOR FC");

      printf("\nWrong selection!!! Please try again!!!\n");
    }
  }
}

void insert(char value[])
{

  struct Node *newNode;
  newNode = (struct Node *)malloc(sizeof(struct Node));
  strcpy(newNode->data, value);
  // newNode->data = value;  :: We cannot do this when we are copying a string into a node, it shows error whereas we have to use strcpy
  newNode->next = NULL;
  if (front == NULL)
    front = rear = newNode;
  else
  {
    rear->next = newNode;
    rear = newNode;
  }
  printf("\nEnter the quantity required :  ");
  scanf("%d", &newNode->required);
  int rfdb = dataBase(newNode->data, newNode->required); //rfdb is returning from database
  if (rfdb == 0)
  {
    SortingPopularity(newNode->data, newNode->required);
    printf("\nOrder has been placed in Queue. Please wait for verification!!!\n");
  }
  else if (rfdb == 2)
  {
    system("COLOR FC");
    printf("\nSorry Please go with another car\n");
    deleted(0);
  }
}

void deleted(int noItem)
{
  if (front == NULL)
    printf("\nOrder list is empty!!!\n");
  else if (noItem == 0)
  {
    struct Node *temp = front;
    front = front->next;
    printf("\nWrong Order: %s (%d)  has been deleted\n", temp->data, temp->required);
    free(temp);
  }
  else
  {
    struct Node *temp = front;
    front = front->next;
    printf("\nCompleted Order: %s (%d)\n", temp->data, temp->required);
    free(temp);
  }
}

void display()
{
  if (front == NULL)
    printf("\nOrder list is empty!!!\n");
  else
  {
    struct Node *temp = front;
    while (temp->next != NULL)
    {
      printf(" %s (%d)--->", temp->data, temp->required);
      temp = temp->next;
    }
    printf("%s (%d)--->NULL\n", temp->data, temp->required);
  }
}

int dataBase(char data[2], int req)
{
  char *carsList[10] = {"hc", "ma", "sp", "ar", "la", "vq", "pb", "gc", "ts", "oa"}; // we can store string array in c in this way by creating a pointer array
  int i;
  if (req <= 100)
  {
    for (i = 0; i < 10; i++)
    {
      int j = strcmp(data, carsList[i]); // Checking whether the required car is present in the database or not
      if (j == 0)
      {
        //Remaining cars which are there in Data base are shown from this to the users
        switch (data[0])
        {
        case 'h':
          if (hc > 0)
          {
            hc = hc - req;
            printf("\nNo.of Huracan Coupe Cars Remaining are %d\n", hc);
          }
          else if (hc == 0)
          {
            printf("Huracan Coupe Cars have been completed. Please wait for 30 days\n");
          }
          break;

        case 'm':
          if (ma > 0)
          {
            ma = ma - req;
            printf("\nNo.of Mercedes AMG Cars Remaining are %d\n", ma);
          }
          else if (ma == 0)
          {
            printf("Mercedes AMG Cars have been completed. Please wait for 30 days\n");
          }
          break;

        case 's':
          if (sp > 0)
          {
            sp = sp - req;
            printf("\nNo.of 488 Spider Cars Remaining are %d\n", sp);
          }
          else if (sp == 0)
          {
            printf("488 Spider Cars have been completed. Please wait for 30 days\n");
          }
          break;

        case 'a':
          if (ar > 0)
          {
            ar = ar - req;
            printf("\nNo.of Audi R8 Cars Remaining are %d\n", ar);
          }
          else if (ar == 0)
          {
            printf("Audi R8 Cars have been completed. Please wait for 30 days\n");
          }
          break;

        case 'l':
          if (la > 0)
          {
            la = la - req;
            printf("\nNo.of Lamborghini Aventador Cars Remaining are %d\n", la);
          }
          else if (la == 0)
          {
            printf("Lamborghini Aventador Cars have been completed. Please wait for 30 days\n");
          }
          break;

        case 'v':
          if (vq > 0)
          {
            vq = vq - req;
            printf("\nNo.of Aston Martin Vanquish S Cars Remaining are %d\n", vq);
          }
          else if (vq == 0)
          {
            printf("Aston Martin Vanquish S Cars have been completed. Please wait for 30 days\n");
          }
          break;

        case 'p':
          if (pb > 0)
          {
            pb = pb - req;
            printf("\nNo.of Porsche Boxster 718 Cars Remaining are %d\n", pb);
          }
          else if (pb == 0)
          {
            printf("Porsche Boxster 718 Cars have been completed. Please wait for 30 days\n");
          }
          break;

        case 'g':
          if (gc > 0)
          {
            gc = gc - req;
            printf("\nNo.of Maserati GranCabrio Cars Remaining are %d\n", gc);
          }
          else if (gc == 0)
          {
            printf("Maserati GranCabrio Cars have been completed. Please wait for 30 days\n");
          }
          break;

        case 't':
          if (ts > 0)
          {
            ts = ts - req;
            printf("\nNo.of Tesla Model 3 Cars Remaining are %d\n", ts);
          }
          else if (ts == 0)
          {
            printf("Tesla Model 3 Cars have been completed. Please wait for 30 days\n");
          }
          break;

        case 'o':
          if (oa > 0)
          {
            oa = oa - req;
            printf("\nNo.of Aston Martin Vantage AMR Cars Remaining are %d\n", oa);
          }
          else if (oa == 0)
          {
            printf("Aston Martin Vantage AMR Cars have been completed. Please wait for 30 days\n");
          }
          break;
        }
        return 0;
      }
    }
    return 1;
  }
  else
  {
    printf("\nNo enough items in garage\n");
    return 2;
  }
}

void modelByPopularity()
{
  // Given car required quantities as parameter
  // arrange everything dynamically
  // Using Priority Queue
  displayPopularity();
}
void modelByPrice()
{
  int choice;
  printf("1.High to Low\n");
  printf("2.Low to High\n");
  scanf("%d", &choice);

  if (choice == 1)
  {
    printf("\t\t\t\t  =====================================================================\n");
    printf("\t\t\t\t  || 1)Huracan Coupe               (hc)            Rs.3,97,00,000/-  ||\n");
    printf("\t\t\t\t  || 2)Aston Martin Vanquish S     (vq)            Rs.3,85,00,000/-  ||\n");
    printf("\t\t\t\t  || 3)Lamborghini Aventador       (la)            Rs.2,54,85,845/-  ||\n");
    printf("\t\t\t\t  || 4)Audi R8                     (ar)            Rs.2,47,00,000/-  ||\n");
    printf("\t\t\t\t  || 5)Maserati GranCabrio         (gc)            Rs.1,98,00,000/-  ||\n");
    printf("\t\t\t\t  || 6)488 Spider                  (sp)            Rs.1,76,53,234/-  ||\n");
    printf("\t\t\t\t  || 7)Aston Martin Vantage AMR    (oa)            Rs.1,22,53,105/-  ||\n");
    printf("\t\t\t\t  || 8)Porsche Boxster 718         (pb)            Rs.92,02,000/-    ||\n");
    printf("\t\t\t\t  || 9)Mercedes AMG                (ma)            Rs.77,50,000/-    ||\n");
    printf("\t\t\t\t  ||10)Tesla Model 3               (ts)            Rs.53,23,548/-    ||\n");
    printf("\t\t\t\t  =====================================================================");
  }
  else if (choice == 2)
  {
    printf("\t\t\t\t  ====================================================================\n");
    printf("\t\t\t\t  || 1)Tesla Model 3               (ts)            Rs.53,23,548/-    ||\n");
    printf("\t\t\t\t  || 2)Mercedes AMG                (ma)            Rs.77,50,000/-    ||\n");
    printf("\t\t\t\t  || 3)Porsche Boxster 718         (pb)            Rs.92,02,000/-    ||\n");
    printf("\t\t\t\t  || 4)Aston Martin Vantage AMR    (oa)            Rs.1,22,53,105/-  ||\n");
    printf("\t\t\t\t  || 5)488 Spider                  (sp)            Rs.1,76,53,234/-  ||\n");
    printf("\t\t\t\t  || 6)Maserati GranCabrio         (gc)            Rs.1,98,00,000/-  ||\n");
    printf("\t\t\t\t  || 7)Audi R8                     (ar)            Rs.2,47,00,000/-  ||\n");
    printf("\t\t\t\t  || 8)Lamborghini Aventador       (la)            Rs.2,54,85,845/-  ||\n");
    printf("\t\t\t\t  || 9)Aston Martin Vanquish S     (vq)            Rs.3,85,00,000/-  ||\n");
    printf("\t\t\t\t  ||10)Huracan Coupe               (hc)            Rs.3,97,00,000/-  ||\n");
    printf("\t\t\t\t  ====================================================================");
  }
}

void SortingPopularity(char added_item[2], int required)
{
  int flag = 0;
  struct node *tmp, *q;
  int item_priority;

  tmp = (struct node *)malloc(sizeof(struct node));

  item_priority = required;

  strcpy(tmp->data, added_item);
  tmp->priority = item_priority;
  tmp->link = NULL;

  if (Front == NULL)
  {
    Front = tmp;
  }

  else if (Front->priority < item_priority)
  {
    tmp->link = Front;
    Front = tmp;
  }
  else
  {
    q = Front;
    while (q->link != NULL)
    {
      int j = strcmp(q->data, added_item);
      if (j == 0)
      {
        q->priority = (q->priority) + (item_priority);
        printf("%d\n", q->priority);
        flag = 1;
        sortingPriority();
        break;
      }
      else
      {
        q = q->link;
      }
    }
    if (flag != 1)
    {
      while (q->link != NULL && (q->link)->priority >= item_priority)
      {
        q = q->link;
      }
      tmp->link = q->link;
      q->link = tmp;
      sortingPriority();
    }
  }
}

void displayPopularity()
{
  struct node *ptr;
  ptr = Front;
  if (Front == NULL)
  {
    printf("\n--------------------------------------------------------------------------");
    printf("\n\nDatabase has just started. Please start ordering\n");
    printf("\n--------------------------------------------------------------------------");
  }
  else
  {
    printf("\n\n\t\t\t---------------------- Model By Popularity-------------------------\n\n\n");
    printf("\t\t\t\t\t\tCars\t\tSold\n\n");
    while (ptr != NULL)
    {
      printf("\t\t\t\t\t\t%s \t\t%d\n\n", ptr->data, ptr->priority);
      ptr = ptr->link;
    }
    printf("\n\n\t\t\t-------------------------------------------------------------------\n\n");
  }
}

void sortingPriority()
{

  struct node *i, *j;
  char tempo[2] = "";
  int num;
  i = Front;

  for (i = Front; i != NULL; i = i->link)
  {
    for (j = i->link; j != NULL; j = j->link)
    {
      if (i->priority < j->priority)
      {
        num = i->priority;
        i->priority = j->priority;
        j->priority = num;

        strcpy(tempo, i->data);
        strcpy(i->data, j->data);
        strcpy(j->data, tempo);
      }
    }
  }
}
