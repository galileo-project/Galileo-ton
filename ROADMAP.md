## ROADMAP

```
                    User Application
=============================================================
                     Application
-------------------------------------------------------------
File System|App Channel|Routine|Dispatch
=============================================================
           |                     Kernel
           |-------------------------------------------------
           |        Local          |         Global
           |-----------------------|-------------------------
  Library  |Database|Storage       |Cache
           |                       |
           |                       |-------------------------
           |                       |         Channel
=============================================================
                      Device Driver
-------------------------------------------------------------
vDisk|Network
=============================================================
                         Linux
```

## Project structure

```
include     Common include files
driver      Driver
lib         Common library
ton         TON sys application
kernel      Kernel

```

## File tree

```
include /usr/include/ton
lib     /usr/lib/ton

Storage /var/ton
```


## Note

1. Maybe VM