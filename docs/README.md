# debian-createstructure
[![GitHub license](https://img.shields.io/badge/license-GNU-green?style=flat)](https://github.com/createstructure/libraries-createstructure/blob/UML-beta/docs/LICENSE)
![Author](https://img.shields.io/badge/author-Castellani%20Davide-green?style=flat)
![sys.platform supported](https://img.shields.io/badge/OS%20platform%20supported-all-blue?style=flat) 

##  Description 
Repo containing the library used by core-createstructure  manager-createstructure
![createstructure/libraries-createstructure](https://opengraph.githubassets.com/436fc4cbeb544e799612a4fa3c06f793a5f2031eb62d88fbe08daa252d7f8ec6/createstructure/libraries-createstructure)
##  Class UML 
![Class UML](https://raw.githubusercontent.com/createstructure/librerias-createstructure/UML-beta/docs/librerias-createstructure-Class-uml.svg)
##  Directory structure 

```
../repo
├── bin # source code
│   ├── cryptation.hpp
│   ├── emoji.hpp
│   ├── inputs.hpp
│   ├── json.hpp
│   ├── positive.hpp
│   ├── rest.hpp
│   └── sleep.hpp
└── docs # documentation
    ├── CHANGELOG.md
    ├── LICENSE
    ├── README.md
    ├── libraries-createstructure-Class-UML.svg
    └── libraries-createstructure.drawio

2 directories, 12 files
```
##  Changelog 
Repo containing the library used by [core-createstructure](https://github.com/createstructure/core-createstructure) & [manager-createstructure](https://github.com/createstructure/manager-createstructure)

- [ Changelog ](#changelog)
  - [[10.01.02] - 2022-01-05](#100102---2022-01-05)
  - [[10.01.01] - 2021-12-10](#100101---2021-12-10)
  - [[09.01.17] - 2021-09-10](#090117---2021-09-10)
    - [Changed](#changed)
  - [[09.01.16] - 2021-09-10](#090116---2021-09-10)
    - [Changed](#changed-1)
  - [[09.01.15] - 2021-09-10](#090115---2021-09-10)
    - [Changed](#changed-2)
  - [[09.01.14] - 2021-09-07](#090114---2021-09-07)
    - [Changed](#changed-3)
  - [[09.01.13] - 2021-08-13](#090113---2021-08-13)
    - [Changed](#changed-4)
  - [[09.01.12] - 2021-07-18](#090112---2021-07-18)
    - [Changed](#changed-5)
  - [[09.01.11] - 2021-07-18](#090111---2021-07-18)
    - [Added](#added)
  - [[09.01.10] - 2021-07-18](#090110---2021-07-18)
    - [Added](#added-1)
    - [Changed](#changed-6)
  - [[09.01.09] - 2021-07-17](#090109---2021-07-17)
    - [Changed](#changed-7)
  - [[09.01.08] - 2021-07-17](#090108---2021-07-17)
    - [Added](#added-2)
    - [Changed](#changed-8)
  - [[09.01.07] - 2021-07-17](#090107---2021-07-17)
    - [Changed](#changed-9)
  - [[09.01.06] - 2021-07-15](#090106---2021-07-15)
    - [Changed](#changed-10)
  - [[09.01.05] - 2021-07-13](#090105---2021-07-13)
    - [Changed](#changed-11)
  - [[09.01.04] - 2021-07-07](#090104---2021-07-07)
    - [Changed](#changed-12)
  - [[09.01.03] - 2021-07-07](#090103---2021-07-07)
    - [Changed](#changed-13)
  - [[09.01.02] - 2021-07-04](#090102---2021-07-04)
    - [Changed](#changed-14)
  - [[09.01.01] - 2021-06-25](#090101---2021-06-25)
    - [Added](#added-3)

### [10.01.02] - 2022-01-05
- [Add sponsorship button](https://github.com/createstructure/createstructure.github.io/issues/36)

### [10.01.01] - 2021-12-10
- [v10-beta (libraries-createstructure)](https://github.com/createstructure/libraries-createstructure/issues/3)
  - [Improve libraries management and distribution](https://github.com/createstructure/libraries-createstructure/issues/)

### [09.01.17] - 2021-09-10
#### Changed
- Fixed a problem of an [issue](https://github.com/createstructure/libraries-createstructure/issues/1)

### [09.01.16] - 2021-09-10
#### Changed
- Fixed an [issue](https://github.com/createstructure/libraries-createstructure/issues/2)

### [09.01.15] - 2021-09-10
#### Changed
- Fixed an [issue](https://github.com/createstructure/libraries-createstructure/issues/1)

### [09.01.14] - 2021-09-07
#### Changed
- Try to change reboot waiting-time (3h => 6h)

### [09.01.13] - 2021-08-13
#### Changed
- Change reboot waiting-time (12h => 3h)

### [09.01.12] - 2021-07-18
#### Changed
- Fixed a bug

### [09.01.11] - 2021-07-18
#### Added
- Now it's easier to manage CLI inputs, the "createstructure_inputs.hpp" library now manage multiple ways to do the same thing (eg. -h is now equal to --help)

### [09.01.10] - 2021-07-18
#### Added
- Some librerias by debian packaging
#### Changed
- Optimized importation

### [09.01.09] - 2021-07-17
#### Changed
- Optimized files formattation

### [09.01.08] - 2021-07-17
#### Added
- debian-createstructure update management
#### Changed
- Changed reboot instruction to "stable" version

### [09.01.07] - 2021-07-17
#### Changed
- Changed reboot instruction to test bugs

### [09.01.06] - 2021-07-15
#### Changed
- Changed reboot time to test bugs

### [09.01.05] - 2021-07-13
#### Changed
- Fixed a bug

### [09.01.04] - 2021-07-07
#### Changed
- Fixed a bug

### [09.01.03] - 2021-07-07
#### Changed
- Optimized some librerias (for manager-createstructure)

### [09.01.02] - 2021-07-04
#### Changed
- Optimized rest library

### [09.01.01] - 2021-06-25
#### Added
- Initial version for this repo
---
Made w/ :heart: by Castellani Davide

If you want to contribute you can start with:
- [Discussion](https://github.com/createstructure/libraries-createstructure/discussions)
- [Issue](https://github.com/createstructure/libraries-createstructure/issues/new)
