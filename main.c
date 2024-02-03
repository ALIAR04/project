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
#define x strcmp(entry->d_name,
#define y !=0
int global (int argc , char *const argv[]) {
    if (strcmp (argv[3] , "user.name") == 0) {
        if (argc == 4) {
            perror ("please enter an username\n");
            return 1;
        }
        FILE *global;
        global = fopen ("global/user.name.txt" , "w");
        fprintf (global , "%s", argv[4]);
        fclose (global);
    } else if (strcmp (argv[3] , "user.email") == 0) {
        if (argc == 4) {
            perror ("please enter an email\n");
            return 1;
        }
        FILE *global;
        global = fopen ("global/user.email.txt" , "w");
        fprintf (global , "%s", argv[4]);
        fclose (global);
    } else {
        perror ("invalid command\n");
        return 1;
    }
    return 0;
}
int local (int argc , char *const argv[]) {
    if (strcmp (argv[2] , "user.name") == 0) {
        if (argc == 3) {
            perror ("please enter an username\n");
            return 1;
        }
        FILE *local;
        local = fopen (".main/local/user.name.txt" , "w");
        fprintf (local , "%s", argv[3]);
        fclose (local);
    } else if (strcmp (argv[2] , "user.email") == 0) {
        if (argc == 3) {
            perror ("please enter an email\n");
            return 1;
        }
        FILE *local;
        local = fopen (".main/local/user.email.txt" , "w");
        fprintf (local , "%s", argv[3]);
        fclose (local);
    } else {
        perror ("invalid command\n");
    }
    return 0;
}
void make_files_init2 (int argc , char *const argv[]) {
    FILE *file;
    CreateDirectory ("stages" , NULL);
    CreateDirectory ("commits" , NULL);
    file = fopen ("commits/commitnumber", "w");
    fclose (file);
}
void make_files_init1 (int argc , char *const argv[]) {
    CreateDirectory ("local" , NULL);
}
int init (int argc , char *const argv[]) {
    char cwd[FILENAME_MAX];
    getcwd (cwd , sizeof(cwd));
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
        getcwd (temp_dir , sizeof(temp_dir));
        if (strcmp (temp_dir , "D:\\") != 0) {
            if (chdir ("..") != 0) {
                return 1;
            }
        }
    } while (strcmp (temp_dir , "D:\\") != 0);
    chdir (cwd);
    if (exist) {
        perror ("the repository already exists!\n");
    } else {
        CreateDirectory (".main" , NULL);
        chdir (".main");
        make_files_init1 (argc , argv);
        CreateDirectory ("master" , NULL);
        chdir ("master");
        make_files_init2 (argc , argv);
        chdir ("..");
        chdir ("..");
    }
    return 0;
}
int addtostagef (int argc , char *const argv[]) {
    for (int p = 3; p < argc; p++) {
        DIR *dir = opendir (".");
        char fileaddress[FILENAME_MAX] , fileinput[FILENAME_MAX];
        struct dirent *entry;
        while ((entry = readdir (dir)) != NULL) {
            if (x".")y && x"..")y && x".git")y && x".main")y && x".vscode")y && x"global")y && x"main.c")y && x"main.exe")y && x"README.md")y && x"tempCodeRunnerFile.c")y ) {
                if (entry->d_type == DT_DIR && strcmp (entry->d_name , argv[p]) == 0) {
                    DIR *dir1 = opendir (".main/master/stages");
                    chdir (".main/master/stages");
                    struct dirent *entry1;
                    entry1 = readdir (dir1);
                    do {
                        if (entry1->d_type == DT_DIR && strcmp (entry1->d_name , argv[p]) == 0) {
                            DIR *dir2 = opendir (argv[p]);
                            chdir (argv[p]);
                            struct dirent *entry2;
                            while ((entry2 = readdir (dir2)) != NULL) {
                                remove (entry2->d_name);
                            }
                            chdir ("..");
                            rmdir (argv[p]);
                        }
                    } while ((entry1 = readdir (dir1)) != NULL);
                    CreateDirectory (argv[p] , NULL);
                    chdir (argv[p]);
                    getcwd (fileaddress , sizeof (fileaddress));
                    chdir ("..");
                    chdir ("..");
                    chdir ("..");
                    chdir ("..");
                    DIR *dir11 = opendir (argv[p]);
                    chdir (argv[p]);
                    getcwd (fileinput , sizeof (fileinput));
                    struct dirent *entry11;
                    while ((entry11 = readdir (dir11)) != NULL) {
                        FILE *file1 = fopen (entry11->d_name , "r");
                        if (file1 != NULL) {
                            chdir (fileaddress);
                            char name_temp[100];
                            FILE *file2 = fopen (entry11->d_name , "w");
                            char ch = getc (file1);
                            while (ch != EOF) {
                                putc (ch , file2);
                                ch = getc (file1);
                            }
                            chdir (fileinput);
                            fclose (file2);
                        }
                        fclose (file1);
                    }
                    chdir ("..");
                } else if (strcmp (argv[p] , entry->d_name) == 0) {
                    FILE *file1 , *file2;
                    file1 = fopen (argv[p] , "r");
                    chdir (".main");
                    chdir ("master");
                    chdir ("stages");
                    file2 = fopen (argv[p] , "w");
                    char ch = getc (file1);
                    while (ch != EOF) {
                        putc (ch , file2);
                        ch = getc (file1);
                    }
                    fclose (file1);
                    fclose (file2);
                    for (int i = 0; i < 3; i++) {
                        chdir ("..");
                    }
                }
            }
        }
        int flag = 0;
        DIR *dir13 = opendir (".");
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
        DIR *dir = opendir (".");
        char fileaddress[FILENAME_MAX] , fileinput[FILENAME_MAX];
        struct dirent *entry;
        while ((entry = readdir (dir)) != NULL) {
            if (x".")y && x"..")y && x".git")y && x".main")y && x".vscode")y && x"global")y && x"main.c")y && x"main.exe")y && x"README.md")y && x"tempCodeRunnerFile.c")y ) {
                if (entry->d_type == DT_DIR && strcmp (entry->d_name , argv[2]) == 0) {
                    DIR *dir1 = opendir (".main/master/stages");
                    chdir (".main/master/stages");
                    struct dirent *entry1;
                    entry1 = readdir (dir1);
                    do {
                        if (entry1->d_type == DT_DIR && strcmp (entry1->d_name , argv[2]) == 0) {
                            DIR *dir2 = opendir (argv[2]);
                            chdir (argv[2]);
                            struct dirent *entry2;
                            while ((entry2 = readdir (dir2)) != NULL) {
                                remove (entry2->d_name);
                            }
                            chdir ("..");
                            rmdir (argv[2]);
                        }
                    } while ((entry1 = readdir (dir1)) != NULL);
                    CreateDirectory (argv[2] , NULL);
                    chdir (argv[2]);
                    getcwd (fileaddress , sizeof (fileaddress));
                    chdir ("..");
                    chdir ("..");
                    chdir ("..");
                    chdir ("..");
                    DIR *dir11 = opendir (argv[2]);
                    chdir (argv[2]);
                    getcwd (fileinput , sizeof (fileinput));
                    struct dirent *entry11;
                    while ((entry11 = readdir (dir11)) != NULL) {
                        FILE *file1 = fopen (entry11->d_name , "r");
                        if (file1 != NULL) {
                            chdir (fileaddress);
                            char name_temp[100];
                            FILE *file2 = fopen (entry11->d_name , "w");
                            char ch = getc (file1);
                            while (ch != EOF) {
                                putc (ch , file2);
                                ch = getc (file1);
                            }
                            chdir (fileinput);
                            fclose (file2);
                        }
                        fclose (file1);
                    }
                    chdir ("..");
                } else if (strcmp (argv[2] , entry->d_name) == 0) {
                    FILE *file1 , *file2;
                    file1 = fopen (argv[2] , "r");
                    chdir (".main");
                    chdir ("master");
                    chdir ("stages");
                    file2 = fopen (argv[2] , "w");
                    char ch = getc (file1);
                    while (ch != EOF) {
                        putc (ch , file2);
                        ch = getc (file1);
                    }
                    fclose (file1);
                    fclose (file2);
                    for (int i = 0; i < 3; i++) {
                        chdir ("..");
                    }
                }
            }
        }
        int flag = 0;
        DIR *dir13 = opendir (".");
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
            perror ("there is no repository\n");
            return 1;
        }
        chdir ("master");
        DIR *dir = opendir ("stages");
        chdir ("stages");
        struct dirent *entry;
        int flag = 0;
        while ((entry = readdir(dir)) != NULL) {
            if (strcmp (entry->d_name , argv[p]) == 0 && entry->d_type == DT_DIR) {
                flag = 1;
                DIR *dir1 = opendir (argv[p]);
                chdir (argv[p]);
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
        for (int i = 0; i < 3; i++) {
            chdir ("..");
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
    chdir ("master");
    DIR *dir = opendir ("stages");
    chdir ("stages");
    struct dirent *entry;
    int flag = 0;
    while ((entry = readdir(dir)) != NULL) {
        if (strcmp (entry->d_name , argv[2]) == 0 && entry->d_type == DT_DIR) {
            flag = 1;
            DIR *dir1 = opendir (argv[2]);
            chdir (argv[2]);
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
    for (int i = 0; i < 3; i++) {
        chdir ("..");
    }
    if (flag == 0) {
        printf ("%s is not in stage.\n", argv[2]);
    }
    return 0;
}




int commit (int argc , char *const argv[]) {
    if (argc > 4) {
        perror ("please enter the commit message between \"\"\n");
        return 1;
    }
    if (argc == 3) {
        perror ("please enter a commit message\n");
    }
    if (strlen (argv[3]) > 72) {
        perror ("the commit message is too long!\n");
        return 1;
    }
    if (chdir (".main") != 0) {
        perror ("there is no repository!\n");
    }
    chdir ("stages");
    char add_stage[FILENAME_MAX] , add_commit[FILENAME_MAX];
    getcwd (add_stage , sizeof(add_stage));
    printf ("add_stage : %s\n" , add_stage);
    chdir ("..");
    chdir ("commits");
    FILE *commitnumber = fopen ("commitnumber" , "r");
    int number = 1;
    if (commitnumber != NULL) {
        fscanf (commitnumber , "%d", &number);
    }
    fclose (commitnumber);
    char combined[100];
    sprintf (combined , "commit%d", number);
    CreateDirectory (combined , NULL);
    number++;
    commitnumber = fopen ("commitnumber" , "w");
    fprintf (commitnumber , "%d", number);
    fclose (commitnumber);
    chdir (combined);
    getcwd (add_commit , sizeof (add_commit));
    printf ("add_commit : %s\n", add_commit);
    DIR *dir = opendir (add_stage);
    struct dirent *entry;
    while ((entry = readdir (dir)) != NULL /*&& strcmp (entry->d_name , ".") != 0 && strcmp (entry->d_name , "..") != 0*/) {
        printf ("%s\n", entry->d_name);
        if (entry->d_type == DT_DIR) {
            printf ("%s is a (dir)\n", entry->d_name);
            FILE *file1 , *file2;
            char add1[FILENAME_MAX] , add2[FILENAME_MAX];
            chdir (add_stage);
            chdir (entry->d_name);
            getcwd (add1 , sizeof (add1));
            printf ("add1 : %s\n", add1);
            chdir (add_commit);
            CreateDirectory (entry->d_name , NULL);
            _chdir (entry->d_name);
            getcwd (add2 , sizeof (add2));
            printf ("add2 : %s\n", add2);
            chdir (add_stage);
            DIR *dir1 = opendir (entry->d_name);
            chdir (entry->d_name);
            struct dirent *entry1;
            while ((entry1 = readdir (dir1)) != NULL) {
                file1 = fopen (entry1->d_name , "r");
                chdir (add2);
                file2 = fopen (entry1->d_name , "w");
                char ch = getc (file1);
                while (ch != EOF) {
                    putc (ch , file2);
                    ch = getc (file1);
                }
                fclose (file1);
                fclose (file2);
            }
            chdir (combined); 
        } else {
            FILE *file1 , *file2;
            chdir (add_stage);
            file1 = fopen (entry->d_name , "r");
            chdir (add_commit);
            file2 = fopen (entry->d_name , "w");
            char ch = getc (file1);
            while (ch != EOF) {
                putc (ch , file2);
                ch = getc (file1); 
            }
            fclose (file1);
            fclose (file2);
            chdir (combined);
        }
    }
    return 0;
}
int main (int argc , char *argv[]) {
    for (int i = 0; i < argc; i++) {
        printf ("argv%d : %s\n",i , argv[i]);
    }
    if (argc < 2) {
        perror ("please enter a valid command:\n");
        return 1;
    }
    if (strcmp (argv[1] , "config") == 0) {
        if (argc == 2) {
            perror ("invalid command!\n");
            return 1;
        } else if (strcmp (argv[2] , "-global") == 0) {
            if (argc == 3) {
                perror ("invalid command!\n");
                return 1;
            } else {
                global (argc , argv);
            }
        } else {
                local (argc , argv);
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
    } else if (strcmp (argv[1] , "commit") == 0) {
        if (strcmp (argv[2] , "-m") == 0) {
            commit (argc , argv);
        } else {
            perror ("invalid command!\n");
            return 1;
        }
    } else {
        perror ("this is not a valid command\n");
    }
    return 0;
}