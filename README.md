<div align="center">

[![Compiling Test](https://github.com/mariospapaz/the_diamond_chase/actions/workflows/compile_test.yml/badge.svg)](https://github.com/mariospapaz/the_diamond_chase/actions/workflows/compile_test.yml)

</div>

## The Diamond Chase
*(insert deep lore)*


A challenge awakens in the Shadow Maze of our University.
The Evil Teacher grants freedom to any student that gets the self manipulated Diamond first, loser stays on the maze for an eternity.

`(You) Mpampis Poteridis` and thy best friend  `Malphoes Loukas`  accept the challenge.

## Showcase
![Screen Shot 2022-05-29 at 4 50 52 PM](https://user-images.githubusercontent.com/30930688/170873445-b3bc6d52-bbea-4ec1-9674-cb566c1ffd6b.png)
![map2](https://user-images.githubusercontent.com/30930688/170873497-680a1265-464b-4b52-a9f4-e4d93ce3c298.png)


## Note
Source Code will be released after 6th June. Stay tuned!


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
