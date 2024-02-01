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
void make_files (int argc , char *const argv[]) {
    FILE *file;
    file = fopen (".main/config.txt" , "w");
    fclose (file);
    file = fopen (".main/username.txt" , "w");
    fclose (file);
    file = fopen (".main/email.txt" , "w");
    fclose (file);
    CreateDirectory (".main/stages" , NULL);
    CreateDirectory (".main/commits" , NULL);
    CreateDirectory (".main/unstages" , NULL);
}
int init (int argc , char *const argv[]) {
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
            if (entry->d_type == DT_DIR && strcmp (entry->d_name , ".main") == 0) {
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
        perror ("the repository already exists!\n");
    } else {
        CreateDirectory (".main" , NULL);
        make_files (argc , argv);
    }
    return 0;
}
int addtostagef (int argc , char *const argv[]) {
    for (int p = 3; p < argc; p++) {
        char fff[FILENAME_MAX];
        getcwd (fff , sizeof (fff));
        DIR *dir = opendir (".main");
        if (chdir (".main") != 0) {
            return 1;
        }
        char fileaddress[FILENAME_MAX] , fileinput[FILENAME_MAX];
        struct dirent *entry;
        while ((entry = readdir (dir)) != NULL) {
            if (entry->d_type == DT_DIR && strcmp (entry->d_name , argv[p]) == 0) {
                DIR *dir1 = opendir ("stages");
                if (chdir ("stages") != 0) {
                    return 1;
                }
                struct dirent *entry1;
                entry1 = readdir (dir1);
                do {
                    if (entry1->d_type == DT_DIR && strcmp (entry1->d_name , argv[p]) == 0) {
                        DIR *dir2 = opendir (argv[p]);
                        if (chdir (argv[p]) != 0){
                            return 1;
                        }
                        struct dirent *entry2;
                        while ((entry2 = readdir (dir2)) != NULL) {
                            remove (entry2->d_name);
                        }
                        if (chdir ("..") != 0) {
                            return 1;
                        }
                        if (rmdir (argv[p]) != 0) {
                            return 1;
                        }
                    }
                }
                while ((entry1 = readdir (dir1)) != NULL);
                CreateDirectory (argv[p] , NULL);
                if (getcwd (fileaddress , sizeof (fileaddress)) == NULL) {
                    return 1;
                }
                if (chdir ("..") != 0) {
                    return 1;
                }
                DIR *dir11 = opendir (argv[p]);
                if (dir11 == NULL) {
                    return 1;
                }
                if (chdir (argv[p]) != 0) {
                    return 1;
                }
                if (getcwd (fileinput , sizeof (fileinput)) == NULL) {
                    return 1;
                }
                struct dirent *entry11;
                while ((entry11 = readdir (dir11)) != NULL) {
                    FILE *file1 = fopen (entry11->d_name , "r");
                    if (file1 != NULL) {
                        if (chdir (fileaddress) != 0) {
                            return 1;
                        }
                        if (chdir (argv[p]) != 0) {
                            return 1;
                        }
                        char name_temp[100];
                        strcpy (name_temp , entry11->d_name);
                        FILE *file2 = fopen (name_temp , "w");
                        char ch = getc (file1);
                        while (ch != EOF) {
                            putc (ch , file2);
                            ch = getc (file1);
                        }
                        if (chdir (fileinput) != 0) {
                            return 1;
                        }
                        fclose (file2);
                    }
                    fclose (file1);
                }
                for (int i = 0; i < 1; i++) {
                    if (chdir ("..") != 0) {
                        return 1;
                    }
                }
            } else if (strcmp (argv[p] , entry->d_name) == 0) {
                FILE *file1 , *file2;
                file1 = fopen (argv[p] , "r");
                DIR *dir1 = opendir ("stages");
                if (chdir ("stages") != 0) {
                    return 1;
                }
                struct dirent *entry1;
                entry1 = readdir (dir1);
                do {
                    if (strcmp (entry1->d_name , argv[p]) == 0) {
                        remove (argv[p]);
                    }
                } while ((entry1 = readdir (dir1)) != NULL);
                file2 = fopen (argv[p] , "w");
                char ch = getc (file1);
                while (ch != EOF) {
                    putc (ch , file2);
                    ch = getc (file1);
                }
                fclose (file1);
                fclose (file2);
                for (int i = 0; i < 1; i++) {
                    if (chdir ("..") != 0) {
                        return 1;
                    }
                }
            }
        }
        int flag = 0;
        if (chdir ("..") != 0) {
            return 1;
        }
        DIR *dir13 = opendir (".main");
        struct dirent *entry13;
        while ((entry13 = readdir (dir13)) != NULL) {
            if (strcmp (argv[p] , entry13->d_name) == 0) {
                flag = 1;
            }
        }
        if (flag == 0) {
            printf ("%s is not existed.\n", argv[p]);
        }
    }
    return 0;
}
int addtostage (int argc , char *const argv[]) {
        DIR *dir = opendir (".main");
        if (chdir (".main") != 0) {
            return 1;
        }
        char fileaddress[FILENAME_MAX] , fileinput[FILENAME_MAX];
        struct dirent *entry;
        while ((entry = readdir (dir)) != NULL) {
            if (entry->d_type == DT_DIR && strcmp (entry->d_name , argv[2]) == 0) {
                DIR *dir1 = opendir ("stages");
                if (chdir ("stages") != 0) {
                    return 1;
                }
                struct dirent *entry1;
                entry1 = readdir (dir1);
                do {
                    if (entry1->d_type == DT_DIR && strcmp (entry1->d_name , argv[2]) == 0) {
                        DIR *dir2 = opendir (argv[2]);
                        if (chdir (argv[2]) != 0){
                            return 1;
                        }
                        struct dirent *entry2;
                        while ((entry2 = readdir (dir2)) != NULL) {
                            remove (entry2->d_name);
                        }
                        if (chdir ("..") != 0) {
                            return 1;
                        }
                        if (rmdir (argv[2]) != 0) {
                            return 1;
                        }
                    }
                }
                while ((entry1 = readdir (dir1)) != NULL);
                CreateDirectory (argv[2] , NULL);
                if (getcwd (fileaddress , sizeof (fileaddress)) == NULL) {
                    return 1;
                }
                if (chdir ("..") != 0) {
                    return 1;
                }
                DIR *dir11 = opendir (argv[2]);
                if (dir11 == NULL) {
                    return 1;
                }
                if (chdir (argv[2]) != 0) {
                    return 1;
                }
                if (getcwd (fileinput , sizeof (fileinput)) == NULL) {
                    return 1;
                }
                struct dirent *entry11;
                while ((entry11 = readdir (dir11)) != NULL) {
                    FILE *file1 = fopen (entry11->d_name , "r");
                    if (file1 != NULL) {
                        if (chdir (fileaddress) != 0) {
                            return 1;
                        }
                        if (chdir (argv[2]) != 0) {
                            return 1;
                        }
                        char name_temp[100];
                        strcpy (name_temp , entry11->d_name);
                        FILE *file2 = fopen (name_temp , "w");
                        char ch = getc (file1);
                        while (ch != EOF) {
                            putc (ch , file2);
                            ch = getc (file1);
                        }
                        if (chdir (fileinput) != 0) {
                            return 1;
                        }
                        fclose (file2);
                    }
                    fclose (file1);
                }
                for (int i = 0; i < 1; i++) {
                    if (chdir ("..") != 0) {
                        return 1;
                    }
                }
            } else if (strcmp (argv[2] , entry->d_name) == 0) {
                FILE *file1 , *file2;
                file1 = fopen (argv[2] , "r");
                DIR *dir1 = opendir ("stages");
                if (chdir ("stages") != 0) {
                    return 1;
                }
                struct dirent *entry1;
                entry1 = readdir (dir1);
                do {
                    if (strcmp (entry1->d_name , argv[2]) == 0) {
                        remove (argv[2]);
                    }
                } while ((entry1 = readdir (dir1)) != NULL);
                file2 = fopen (argv[2] , "w");
                char ch = getc (file1);
                while (ch != EOF) {
                    putc (ch , file2);
                    ch = getc (file1);
                }
                fclose (file1);
                fclose (file2);
                for (int i = 0; i < 1; i++) {
                    if (chdir ("..") != 0) {
                        return 1;
                    }
                }
            }
        }
        int flag = 0;
        if (chdir ("..") != 0) {
            return 1;
        }
        DIR *dir13 = opendir (".main");
        struct dirent *entry13;
        while ((entry13 = readdir (dir13)) != NULL) {
            if (strcmp (argv[2] , entry13->d_name) == 0) {
                flag = 1;
            }
        }
        if (flag == 0) {
            printf ("%s is not existed.\n", argv[2]);
        }
    return 0;
}
int add_check (int argc , char *const argv[]) {
    char cwd[FILENAME_MAX];
    if (getcwd (cwd , sizeof(cwd)) == NULL) {
        return 1;
    }
    char temp_dir[FILENAME_MAX];
    bool exist = false;
    struct dirent *entry;
    do {
        DIR *dir = opendir (cwd);
        while ((entry = readdir (dir)) != NULL) {
            if (entry->d_type == DT_DIR && strcmp (entry->d_name , ".main") == 0) {
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
        if (strcmp (argv[2] , "-f") == 0) { 
            addtostagef (argc , argv);
        } else {
            addtostage (argc , argv);
        }
    } else {
        perror ("there is no repository!\n");
    }
    return 0;
}
int resetf (int argc , char *const argv[]) {
    for (int p = 3; p < argc; p++) {
        if (chdir (".main") != 0) {
            perror ("there is no repository!\n");
            return 1;
        }
        DIR *dir = opendir ("stages");
        if (chdir ("stages") != 0) {
            return 1;
        }
        struct dirent *entry;
        int flag = 0;
        while ((entry = readdir(dir)) != NULL) {
            if (strcmp (entry->d_name , argv[p]) == 0 && entry->d_type == DT_DIR) {
                flag = 1;
                DIR *dir1 = opendir (argv[p]);
                if (chdir (argv[p]) != 0) {
                    return 1;
                }
                struct dirent *entry1;
                while ((entry1 = readdir (dir1)) != NULL) {
                    remove (entry1->d_name);
                }
                if (chdir ("..") != 0) {
                    return 1;
                } 
                rmdir (argv[p]);        
            } else if (strcmp (entry->d_name , argv[p]) == 0) {
                flag = 1;
                remove (argv[p]);
            }
        }
        for (int i = 0; i < 2; i++) {
            if (chdir ("..") != 0) {
                return 1;
            }
        }
        if (flag == 0) {
            printf ("%s is not in stage.\n", argv[p]);
        }
    }
}
int reset (int argc , char *const argv[]) {
    if (chdir (".main") != 0) {
        perror ("there is no repository\n");
        return 1;
    }
    DIR *dir = opendir ("stages");
    if (chdir ("stages") != 0) {
        return 1;
    }
    struct dirent *entry;
    int flag = 0;
    while ((entry = readdir(dir)) != NULL) {
        if (strcmp (entry->d_name , argv[2]) == 0 && entry->d_type == DT_DIR) {
            flag = 1;
            DIR *dir1 = opendir (argv[2]);
            if (chdir (argv[2]) != 0) {
                return 1;
            }
            struct dirent *entry1;
            while ((entry1 = readdir (dir1)) != NULL) {
                remove (entry1->d_name);
            }
            if (chdir ("..") != 0) {
                return 1;
            } 
            rmdir (argv[2]);        
        } else if (strcmp (entry->d_name , argv[2]) == 0) {
            flag = 1;
            remove (argv[2]);
        }
    }
    for (int i = 0; i < 2; i++) {
        if (chdir ("..") != 0) {
            return 1;
        }
    }
    if (flag == 0) {
        printf ("%s is not in stage.\n", argv[2]);
    }
    return 0;
}
int main (int argc , char *argv[]) {
    for (int i = 0; i < argc; i++) {
        printf ("argv%d : %s\n",i , argv[i]);
    }
    char cwd1[FILENAME_MAX];
    if (argc < 2) {
        perror ("please enter a valid command:\n");
    } else if (strcmp (argv[1] , "config") == 0) {
        if (argc == 2) {
            perror ("invalid command!\n");
        } else if (strcmp (argv[2] , "-global") == 0) {
            if (argc == 3) {
                perror ("invalid command!\n");
            }else if (strcmp (argv[3] , "user.name") == 0) {
                if (argc == 4) {
                    perror ("please enter an username.\n");
                }
                FILE *global;
                global = fopen ("global/user.name.txt" , "w");
                fprintf (global , "user.name : %s\n", argv[4]);
                fclose (global);
            } else if (strcmp (argv[3] , "user.email") == 0) {
                if (argc == 4) {
                    perror ("please enter an useremail.\n");
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
    } else if (strcmp (argv[1] , "add") == 0) {
        if (argc == 2) {
            perror ("please enter a file or a directory.\n");
            return 1;
        }
        add_check (argc , argv);
    } else if (strcmp (argv[1] , "reset") == 0) {
        if (argc == 2) {
            perror ("please enter a file or a directory.\n");
            return 1;
        }
        if (strcmp (argv[2] , "-f") == 0) {
            if (argc == 3) {
                perror ("please enter a file or a directory.\n");
                return 1;
            }
            resetf (argc , argv);
        } else {
            reset (argc , argv);
        }
    } else {
        perror ("this is not a valid command\n");
    }
    return 0;
}