## ROADMAP

```
                    User Application
=============================================================
                     Application
-------------------------------------------------------------
Routine|Dispatch            
=============================================================
                       Library                               ---|
-------------------------------------------------------------   |
                System Call Interface                           |
-------------------------------------------------------------   |
            Local        |         Global                       |---Kernel
-------------------------|-----------------------------------   |
Database|VFS             |Cache                                 |
-------------------------------------------------------------   |
                      Channel                                ---|
=============================================================
                      Device Driver
-------------------------------------------------------------
Disk|Network
=============================================================
                         Linux
                         

VFS: virtual File System                         

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