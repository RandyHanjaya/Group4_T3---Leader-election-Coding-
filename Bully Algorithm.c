#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct process {
   int no;
   int priority;
   int active;
   struct process *next;
};
typedef struct process proc;

void bully() {
   proc *head;
   proc *p1;
   proc *p2;
   int n, i, pr, maxpri, a, pid, max, o;
   char ch;

   head = p1 = p2 = NULL;

   printf("\nnEnter how many process: ");
   scanf("%d", &n);

   for (i = 0; i < n; i++) {
      printf("\nEnter priority of process %d: ", i + 1);
      scanf("%d", &pr);
	  
      printf("\nIs process with id %d is active ?(0/1) :", i + 1);
      scanf("%d", &a);
      
	  if (head == NULL) {
         head = (proc*) malloc(sizeof(proc));
         if (head == NULL) {
            printf("\nMemory cannot be allocated");
            getch();
            exit(0);
         }
         head->no = i + 1;
         head->priority = pr;
         head->active = a;
         head->next = head;
         p1 = head;
      } else {
         p2 = (proc*) malloc(sizeof(proc));
         if (p2 == NULL) {
            printf("\nMemory cannot be allocated");
            getch();
            exit(0);
         }
         p2->no = i + 1;
         p2->priority = pr;
         p2->active = a;
         p1->next = p2;
         p2->next = head;
         p1 = p2;
      }
   } //end for

   printf("\nEnter the process id that invokes election algorithm: ");
   scanf("%d", &pid);
   p2 = head;
   while (p2->next != head) {
      if (p2->no == pid) {
         p2 = p2->next;
         break;
      }
      p2 = p2->next;
   }

   printf("\nProcess with id %d has invoked election algorithm", pid);
   printf("\t\nElection message is sent to processes");
   
   while (p2->next != head) {
      if (p2->no > pid)
         printf("%d", p2->no);
      p2 = p2->next;
   }

   printf("%d", p2->no);
   p2 = head;
   max = 0;

   while (1) {
      if (p2->priority > max && p2->active == 1)
         max = p2->no;
      p2 = p2->next;
      if (p2 == head)
         break;
   }

   printf("\n\tProcess with the id %d is the co-ordinator", max);
}

void main() {
   bully();
   getch();
}
