#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define NAME_SIZE 5

typedef struct {
    int age;
    long salary;
} record;

typedef struct {
    char first  [NAME_SIZE] ;
    char last  [NAME_SIZE] ;
    char m;
    record * personal_record;

} person;


void print_person( person * p) {
    printf("%-10s %-20s\n", "First:", p->first);
    printf("%-10s %-20s\n", "Last:", p->last);
    printf("%-10s %-20c\n", "Initial:", p->m);
    printf("%-10s %-20d\n", "Age:", p->personal_record->age);
    printf("%-10s %-20ld\n", "Salary:", p->personal_record->salary);
}

void strcopy( char * dest, char * src ) {
    if (src == NULL || dest == NULL) return;

    for (; *src!= '\0'; src++) {
      *dest = *src;
      dest++;
    }
    *dest = '\0';
}


int main (int argc, char *argv[] ) {
    person p;

    //SHOW CONTENT OF STRUCT p
    
    record *r = (record*)malloc(sizeof(record));
    if (r == 0) return -1;
    r->age = 21;
    r->salary = 70000;
    p.personal_record = r;

    p.m = 'L';

    //SHOW CONTENT OF STRUCT p

    if (argc < 3) {

      strcopy(p.first, "Joe");
      strcopy(p.last, "Fox");
    }
    else {
      strcopy(p.first, argv[1]);
      strcopy(p.last, argv[2]);
    }

    //SHOW CONTENT OF STRUCT p

    print_person(&p);

    if (r != 0 ) free(r);

    return 0;
}
