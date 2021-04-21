from gpiozero import TrafficLights
import json
import requests
from datetime import date, timedelta         #Time is important
import time

Ampel1 = TrafficLights(3, 2, 4) #ampel eins defenieren

Ampel2 = TrafficLights(27,17,22)  # ampel zwei defenieren

Ampel3 = TrafficLights(19, 13, 26)  # ampel drei defenieren

# Get the date from yesterday, so the printout is more organiesd even after a long time of running.
yesterday = date.today() - timedelta(days=1)
spl_word = yesterday                        #
print("Coronazahlen vom: " + str(spl_word), "\n")

# get the API data.
r = requests.get('https://www.berlin.de/lageso/gesundheit/infektionsepidemiologie-infektionsschutz/corona/tabelle-indikatoren-gesamtuebersicht/index.php/index/today.json')

print(r.json()['index'][0], "\n")  # print the latest info in the terminal.

# 7 tage inzidenz abfragen
tage = float(r.json()['index'][0]['7_tage_inzidenz'])
if tage >= 30:  # wenn über 30
    print("7_tage_inzidenz -", float(r.json()['index'][0]['7_tage_inzidenz']), "- ROT","\n")
    Ampel1.red.on()
    Ampel1.green.off()
    Ampel1.amber.off()
elif 20 <= tage <= 30:  # wenn unter 30
    print("7_tage_inzidenz -", float(r.json()['index'][0]['7_tage_inzidenz']), "- GELB","\n")
    Ampel1.red.off()
    Ampel1.green.off()
    Ampel1.amber.on()
elif tage <= 19:  # wenn unter 20
    print("7_tage_inzidenz -", float(r.json()['index'][0]['7_tage_inzidenz']), "- GRÜN","\n")
    Ampel1.red.off()
    Ampel1.green.on()
    Ampel1.amber.off()



#its_belegung
its = float(r.json()['index'][0]['its_belegung'])
if its >= 25:
    print("its_belegung -", float(r.json()['index'][0]['7_tage_inzidenz']), "- ROT","\n")
    Ampel2.red.on()
    Ampel2.green.off()
    Ampel2.amber.off()
elif 15 <= its <= 25:
    print("its_belegung -", float(r.json()['index'][0]['7_tage_inzidenz']), "- GELB","\n")
    Ampel2.red.off()
    Ampel2.green.off()
    Ampel2.amber.on()
elif its <= 14:
    print("its_belegung -", float(r.json()['index'][0]['7_tage_inzidenz']), "- GRÜN","\n")
    Ampel2.red.off()
    Ampel2.green.on()
    Ampel2.amber.off()



#R-wert von letzter veränderung
index = 1
while float(r.json()['index'][index]['4_tage_r_wert_berlin_rki']) == 0:
    index = index + 1
if float(r.json()['index'][index]['4_tage_r_wert_berlin_rki']) != 0:
    rWert = float(r.json()['index'][index]['4_tage_r_wert_berlin_rki'])
    if rWert >= 1.2:
        print("4_tage_r_wert_berlin_rki -", float(r.json()['index'][index]['4_tage_r_wert_berlin_rki']), "- ROT","\n")
        Ampel1.red.on()
        Ampel1.green.off()
        Ampel1.amber.off()
    elif 1.1 <= rWert <= 1.2:
        print("4_tage_r_wert_berlin_rki -", float(r.json()['index'][index]['4_tage_r_wert_berlin_rki']), "- GELB","\n")
        Ampel2.red.off()
        Ampel2git .green.off()
        Ampel2.amber.on()
    elif rWert <= 1.0:
        print("4_tage_r_wert_berlin_rki -", float(r.json()['index'][index]['4_tage_r_wert_berlin_rki']), "- GRÜN","\n")
        Ampel3.red.off()
        Ampel3.green.on()
        Ampel3.amber.off()

 
time.sleep(100)



#{"id":"877","datum":"2021-01-02","fallzahl":"98109","neue_faelle":"460","genesene":"79050","todesfaelle":"1285","7_tage_inzidenz":"130.7","rel_veraenderung_der_7_tage_inzidenz":"-21","its_belegung":"33.8","4_tage_r_wert_berlin_rki":"0"}],"item":[]}
