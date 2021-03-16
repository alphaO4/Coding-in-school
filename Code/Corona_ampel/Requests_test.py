import json
import requests
from datetime import date, timedelta         #Time is important
from operator import index
import PySimpleGUI as sg

# Get the date from yesterday, so the printout is more organiesd even after a long time of running.
yesterday = date.today() - timedelta(days=1)
spl_word = yesterday                        #
print("Coronazahlen vom: " + str(spl_word))
print("\n")

# get the API data.
r = requests.get('https://www.berlin.de/lageso/gesundheit/infektionsepidemiologie-infektionsschutz/corona/tabelle-indikatoren-gesamtuebersicht/index.php/index/today.json')

print(r.json()['index'][0],"\n")  # print the latest info in the terminal.
#print("")

# 7 tage inzidenz abfragen
Daten = float(r.json()['index'][0]['7_tage_inzidenz'])
if Daten >= 30:  # wenn über 30
    print("7_tage_inzidenz - ", float(r.json()['index'][0]['7_tage_inzidenz']), " - ROT","\n")
elif 20 <= Daten <= 30:  # wenn unter 30
    print("7_tage_inzidenz - ", float(r.json()['index'][0]['7_tage_inzidenz']), " - GELB","\n")
elif Daten <= 19:  # wenn unter 20
    print("7_tage_inzidenz - ", float(r.json()['index'][0]['7_tage_inzidenz']), " - GRÜN","\n")



#its_belegung
Daten = float(r.json()['index'][0]['its_belegung'])
if Daten >= 25:
    print("its_belegung - ", float(r.json()['index'][0]['7_tage_inzidenz']), " - ROT","\n")
elif 15 <= Daten <= 25:
    print("its_belegung - ", float(r.json()['index'][0]['7_tage_inzidenz']), " - GELB","\n")
elif Daten <= 14:
    print("its_belegung - ", float(r.json()['index'][0]['7_tage_inzidenz']), " - GRÜN","\n")



#R-wert von letzter veränderung
index = 1
while float(r.json()['index'][index]['4_tage_r_wert_berlin_rki']) == 0:
    index = index + 1
if float(r.json()['index'][index]['4_tage_r_wert_berlin_rki']) != 0:
    Daten = float(r.json()['index'][index]['4_tage_r_wert_berlin_rki'])
    if Daten >= 1.2:
        print("4_tage_r_wert_berlin_rki - ", float(r.json()['index'][index]['4_tage_r_wert_berlin_rki']), " - ROT","\n")
    elif 1.1 <= Daten <= 1.2:
        print("4_tage_r_wert_berlin_rki - ", float(r.json()['index'][index]['4_tage_r_wert_berlin_rki']), " - GELB","\n")
    elif Daten <= 1.0:
        print("4_tage_r_wert_berlin_rki - ", float(r.json()['index'][index]['4_tage_r_wert_berlin_rki']), " - GRÜN","\n")










# while RWert == 0:
#       index + 1
# if float(r.json()['index'][0]['4_tage_r_wert_berlin_rki']
#     Daten = float(r.json()['index'][0]['4_tage_r_wert_berlin_rki'])

# Daten = float(r.json()['index'][0]['4_tage_r_wert_berlin_rki'])
# if Daten >= 1.2:
#     print("ROT")
# elif 1.1 <= Daten <= 1.2:
#     print("GELB")
# elif Daten <= 1.0:
#     print("GRÜN")

# layout = [[sg.Text()], [sg.Button("Close")]]

# # Create the window
# window = sg.Window("Coronazahlen in Berlin vom:" + str(spl_word), layout)

# # Create an event loop
# while True:
#     event, values = window.read()
#     # End program if user closes window or
#     # presses the OK button
#     if event == "Close" or event == sg.WIN_CLOSED:
#         break


#{"id":"877","datum":"2021-01-02","fallzahl":"98109","neue_faelle":"460","genesene":"79050","todesfaelle":"1285","7_tage_inzidenz":"130.7","rel_veraenderung_der_7_tage_inzidenz":"-21","its_belegung":"33.8","4_tage_r_wert_berlin_rki":"0"}],"item":[]}