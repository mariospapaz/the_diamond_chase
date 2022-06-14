<div align="center">

[![Compile Test](https://github.com/mariospapaz/the_diamond_chase/actions/workflows/blank.yml/badge.svg)](https://github.com/mariospapaz/the_diamond_chase/actions/workflows/blank.yml)

</div>

## The Diamond Chase
*(insert deep lore)*


A challenge awakens in the Shadow Maze of our University.
The Evil Teacher grants freedom to any student that gets the self manipulated Diamond first, loser stays on the maze for an eternity.

`(You) Mpampis Poteridis` and thy best friend  `Malphoes Loukas`  accept the challenge.

## Showcase
![image](https://user-images.githubusercontent.com/30930688/173535101-d80248ac-b0db-4d67-a5fc-ea59e7160a0e.png)



## Note
AI Algorithm is bad and I am not gonna bother to improve it :D


## Warning
nCurses is not for Windows, this guide is meant only for `Unix` and `GNU/Linux`.
User must have `el_GR.UTF8` enabled in `/etc/locale.conf` in order to play the game.

Do you not have Greek preinstalled in your computer? that is okay here is a guide!
Edit `/etc/locale.conf`, find and uncomment all `el_GR.` from the script.



<img width="280" alt="Screen_Shot_2022-05-12_at_7 44 18_PM" src="https://user-images.githubusercontent.com/30930688/170873428-34d99fdf-84a3-4e4c-9e88-0bb44fc8840e.png">
<img width="413" alt="Screen_Shot_2022-05-12_at_7 41 44_PM (1)" src="https://user-images.githubusercontent.com/30930688/170873524-50990be1-a0db-4a69-af3c-eb1287448648.png">


now run `locale-gen` with root privileges, reboot and you are good to go!



## Installation
```shell
git clone https://github.com/mariospapaz/the_diamond_chase.git 

cd the_diamond_chase

g++ *.cpp -lncursesw
```

## How to play
`./a.out your_map.txt`

## ncursesw linker error (not found)
```shell
Debian:
    sudo apt install libncursesw5-dev

Arch:
    sudo pacman -S ncurses

# Tip: You should switch to doas. 🙄
```
