::毫无卵用下载器，使用bitsadmin
@echo off
set /p a=<tmp.txt
set /p b=<tmp1.txt
start bitsadmin /transfer aaa %a% %b%
ping 127.0.0.1>nul
bitsadmin /setpriority aaa foreground
exit