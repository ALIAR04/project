#include <stdio.h>
#include <string.h>
int main (int argc , char *argv[]) {
    for (int i = 0; i < argc; i++) {
        printf ("argv %d : %s\n", i , argv[i]);
    }
    if (strcmp (argv[2] , "config") == 0) {
        if (strcmp (argv[3] , "-global") == 0) {
            if (strcmp (argv[4] , "user.name") == 0) {
                FILE *global;
                global = fopen ("global/user.name.txt" , "w");
                fprintf (global , "user.name : %s\n", argv[5]);
                fclose (global);
            } else if (strcmp (argv[4] , "user.email") == 0) {
                FILE *global;
                global = fopen ("global/user.email.txt" , "a");
                fprintf (global , "user.email : %s\n", argv[5]);
                fclose (global);
            } else {
            printf ("invalid command!");

            }
        } else {
            printf ("invalid command!");
        }
    }

    return 0;
}