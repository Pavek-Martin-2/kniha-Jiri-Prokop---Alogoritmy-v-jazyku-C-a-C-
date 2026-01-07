@echo off
echo "spustim vsechny casti procesu ve spravnem poradi jak jdou za sebou"

del holmes.txt
del sifr_klic.txt
del sifrov.txt
del desifr_klic.txt
del rozsifr.txt
del sifrovani_1.exe
del frekv_analyza_1.exe
del prolomeni_1.exe
sleep 1

copy ..\sifrovani_1.exe
copy ..\frekv_analyza_1.exe
copy ..\prolomeni_1.exe
copy ..\holmes.txt
copy ..\sifr_klic.txt
sleep 1

sifrovani_1.exe
frekv_analyza_1.exe
prolomeni_1.exe

