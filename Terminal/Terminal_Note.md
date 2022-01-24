- [System Terminal](#system-terminal)
    - [Manage the permissions `chomd`](#manage-the-permissions-chomd)
    - [Display home dirction `pwd`](#display-home-dirction-pwd)
  - [Dirction](#dirction)
  - [Files](#files)
      - [Creat a new file `touch`](#creat-a-new-file-touch)
      - [Rename file `mv`](#rename-file-mv)
      - [Delete `rm`](#delete-rm)
    - [EEP HW 1](#eep-hw-1)
      - [Getting started](#getting-started)
      - [File paths and directory navigation](#file-paths-and-directory-navigation)
      - [Permissions](#permissions)
- [Docker](#docker)

# System Terminal

### Manage the permissions `chomd`

[Tutorial Note](https://kb.iu.edu/d/abdb)
![chomd_symbol](Image/chomd_symbol.png)


### Display home dirction `pwd`
```sh
pwd -P    # Full path 
```

## Dirction

## Files

#### Creat a new file `touch`
```sh
echo "Some line" > file1.txt
```

#### Rename file `mv`

#### Delete `rm`
```sh
rm -rf 'dirction'\

```


### EEP HW 1

#### Getting started

1. Enter a command to print "Hello 2022 and the new quarter!" on the screen.
2. Display the current date and time on the screen.

#### File paths and directory navigation

3. Display the full path of your home directory.
4. Go to your home directory.
5. List all the files in your current directory.
6. Now, create a new folder called ‘temp’.
7. Rename this folder to ‘temp_new’.
8. Go to the ‘temp_new’ folder.
9. Create a file called 'file5' without using a text editor. (There are at least three easy ways to do this.)
10. Rename 'file5' to 'test'
11. Go up one directory.
12. Delete the ‘temp_new’ folder with a single command. (The command you use should also delete 
all of the files inside of the folder.)

#### Permissions

13. Create a file called 'secretfile' containing the text “It's a secret!” using the echo command.
14. Change the permission of this file in such a way so that no one can write to it. Use the ls command to show the file name and permissions.
15. Try to add more text to 'secretfile' using the cat command.


weget

git 

chmod 

vim

# Docker
```sh
docker attach [acontainer name]      # Go into container
```
