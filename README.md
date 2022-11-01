# Priceladder

## Description
The "priceladder"-project generates a GUI for parties.

The purpose of the application is to animate the common party people to drink with special drink prices.

Therefor a GUI was created, the surface shows for example 5 counters. With puhsing the 'Start'-Button the first Countdown begins to run. It runs until the defined time is over. Now the second Countdown runs.

At the moment, the Background of the surfache is a static jpg of the user. Also the values of the countdowns and the size of the application have to edit manually within the c++ code.

For this purpose it would be the best, if the user of the application could edit the basic-settings within the running application.

If you want to join this project, be free and fork or branch it. I will always be thankful for every comment ;)

Much fun and don't trink to much...

## Requirements

| Tool   | Version |
| -      | -       |
| Conan  | 1.53.0  |
| Python | 3.10.8  |
| Pip    | 22.2.2  |

## Tested compilers

| Arch   | Compiler    | Version  |
| -      | -           | -        |
| macOS Catalina (10.15.7)  | Apple clang | 12.0.0   |

## How to build the project

```
conan install conanfile.py -if build
```

## Bugs and Workarounds

### Conan install failes for macOS
The `conan install` command failes for the macOS:
```
ERROR: Missing prebuilt package for 'libmysqlclient/8.0.29', 'qt/5.15.3'
```
You have to build qt on your pc with the conan command
```
conan install conanfile.py -if build --build=qt
```