gcc -c -o torun.a torun.c
gcc -shared -o torun.run torun.a
gcc -o runer runer.c -ldl
./runer ./torun.run
