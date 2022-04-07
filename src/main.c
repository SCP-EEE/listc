#include <stdio.h>
#include <stdlib.h>

#define max 100

struct list{
  int a;
  struct list* nextlist;
};

struct list * addlist(struct list * listp)
{
  struct list * new_list;
  new_list = (struct list *)malloc(sizeof(struct list));
  new_list->a = 0;
  if(listp != NULL)
    listp->nextlist = new_list;
  new_list->nextlist = NULL;
  return new_list;
}

int main(void){
  struct list first_list;
  struct list * old_list;
  struct list * now_list;
  int a=0;
  now_list = &first_list;
  for(int x=0; x<max; x++)
    {
      fscanf(stdin, "%d", &a);
      now_list->a = a;
      old_list = addlist( now_list );
      now_list = old_list;
    }
  now_list = &first_list;
  for(int x=0; x<max; x++)
    {
      printf("%d:%p\n", now_list->a, now_list);
      old_list = now_list->nextlist;
      now_list = old_list;
      if(now_list == NULL)
	{
	  printf("error");
	  return -1;
	}
    }
  now_list = &first_list;
  for(int x=0; x<max; x++)
    {
      printf("%d:%p\n", now_list->a, now_list);
      old_list = now_list->nextlist;
      now_list = old_list;
      if(now_list == NULL)
	{
	  printf("error");
	  return -1;
	}
    }
  now_list = &first_list;
  old_list = now_list->nextlist;
  now_list = old_list;
  fscanf(stdin, "%d", &a);
  for(int x=0; x<(max-1); x++)
    {
      old_list = now_list->nextlist;
      printf("%p is freeing ...\n", now_list);
      free(now_list);
      printf("%p is free!\n", now_list);
      now_list = old_list;
      if(now_list == NULL)
        {
          printf("error");
          return -1;
        }
      }
  now_list = &first_list;
  for(int x=0; x<max; x++)
    {
      printf("%d:%p\n", now_list->a, now_list);
      old_list = now_list->nextlist;
      now_list = old_list;
      if(now_list == NULL)
	{
	  printf("error");
	  return -1;
	}
    }
  return 0;

}
