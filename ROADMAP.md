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
  Library  |Memory|Network|Database|Cache|
           |Storage|               |
           |                       |-------------------------
           |                       |         Channel
=============================================================
                         Driver
-------------------------------------------------------------
vMemory|vDisk|
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