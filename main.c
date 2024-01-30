#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include <stdbool.h>
#include <stdlib.h>
#include <direct.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <windows.h>
void make_files (char cwd[]) {
    if (getcwd (cwd , sizeof (cwd)) != 0) {
        return 1;
    }
    FILE *file;
    file = fopen (".main/config.txt" , "w");
    fclose (file);
    file = fopen (".main/username.txt" , "w");
    fclose (file);
    file = fopen (".main/emain.txt" , "w");
    fclose (file);
}
int init (int argc , char * const argv[]) {
    char cwd[FILENAME_MAX];
    if (getcwd (cwd , sizeof(cwd)) == NULL) {
        return 1;
    }
    char temp_dir[FILENAME_MAX];
    bool exist = false;
    struct dirent *entry;
    do {
        DIR *dir = opendir (cwd);
        if (dir == NULL) {
            return 1;
        }
        while ((entry = readdir (dir)) != NULL) {
            if (entry->d_type == DT_DIR && strcmp (entry->d_name , ".neogit") == 0) {
                exist = true;
            }
        }
        if (getcwd (temp_dir , sizeof(temp_dir)) == NULL) {
            return 1;
        }
        if (strcmp (temp_dir , "D:\\") != 0) {
            if (chdir ("..") != 0) {
                return 1;
            }
        }
    } while (strcmp (temp_dir , "D:\\") != 0);
    if (chdir (cwd) != 0) {
        return 1;
    }
    if (exist) {
        perror ("neogit repository already exists!\n");
    } else {
        CreateDirectory (".main" , NULL);
        make_files (cwd);
    }
    return 0;
}

int main (int argc , char *argv[]) {
    for (int i = 0; i < argc; i++) {
        printf ("argv %d : %s\n",i , argv[i]);
    }
    if (argc < 2) {
        perror ("please enter a valid command:\n");
        return 1;
    } else if (strcmp (argv[1] , "config") == 0) {
        if (argc == 2) {
            printf ("invalid command!\n");
        } else if (strcmp (argv[2] , "-global") == 0) {
            if (argc == 3) {
                printf ("invalid command!\n");
            }else if (strcmp (argv[3] , "user.name") == 0) {
                if (argc == 4) {
                    return 1;
                }
                FILE *global;
                global = fopen ("global/user.name.txt" , "w");
                fprintf (global , "user.name : %s\n", argv[4]);
                fclose (global);
            } else if (strcmp (argv[3] , "user.email") == 0) {
                if (argc == 4) {
                    return 1;
                }
                FILE *global;
                global = fopen ("global/user.email.txt" , "w");
                fprintf (global , "user.email : %s\n", argv[4]);
                fclose (global);
            } else {
                perror ("invalid command!\n");

            }
        } else {
            perror ("invalid command!\n");
        }
    } else if (strcmp (argv[1] , "init") == 0) {
        init (argc , argv);
    } else {
        perror ("this is not a valid command\n");
    }

    return 0;
}