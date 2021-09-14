@echo off
title Installing Xampp
color 3F
rem What drive is the USB?
set /p name="Die Dateien werden gleich heruntergeladen und installiert. Bitte geben Sie das Laufwerk des USB an (z. B. D oder F), um dort die Dateien zu installieren:"
rem Download and install xampp
powershell -command Invoke-WebRequest 'https://kumisystems.dl.sourceforge.net/project/xampp/XAMPP%20Windows/8.0.10/xampp-portable-windows-x64-8.0.10-0-VS16.zip' -OutFile %name%:\xampp.zip
cls
powershell -command Expand-Archive -Force %name%:\xampp.zip %name%:\ 
echo Entpackung von xampp abgeschlossen
timeout 1
, echo
cd %name%:
cd %name%:\xampp
setup_xampp.bat
timeout 4
xampp-control.exe
del /f /q "%name%:\xampp.zip"
echo Vielen Dank, Sie koennen jetzt den USB entfernen. Sobald Sie dies tun, wird das sich selbst Programm beenden. Alternativ können sie das Programm auch einfach schließen und XAMPP jetzt schon benutzen.
echo Einen schönen Tag noch
rem check if the USB is still in the usb-port.
    :start
if exist %name%:\ ( goto start) else ( echo Auf Wiedersehen)
timeout 3 > NULL
exit