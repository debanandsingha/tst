#To write a program for signal handling in UNIX.
#!/bin/bash

echo program for performing KILL operations
ps
echo enter the pid
read pid
kill-9 $pid
echo finished
