import json
import requests
from datetime import date, timedelta         #
import re
yesterday = date.today() - timedelta(days=1) # Get the date from yesterday, so the printout is more organiesd even after a long time of running. 
spl_word = yesterday                         # 
print("Corona zahlen vom: " + str(spl_word)) #

r = requests.get('https://www.berlin.de/lageso/gesundheit/infektionsepidemiologie-infektionsschutz/corona/tabelle-indikatoren-gesamtuebersicht/index.php/index/today.json') #get the API data.

print(r.json()['index'][0]) #print the latest info in the terminal.

print("7_tage_inzidenz:")
Daten = float(r.json()['index'][0]['7_tage_inzidenz']) # 7 tage inzidenz amfragen
if Daten >= 30: # wenn über 30
    print("ROT")
elif 20 <= Daten <= 30:  # wenn unter 30
    print("GELB")
elif Daten <= 19: # wenn unter 20 
    print("GRÜN")

print("its_belegung:")
Daten = float(r.json()['index'][0]['its_belegung'])
if Daten >= 25:
    print("ROT")
elif 15 <= Daten <= 25:
    print("GELB")
elif Daten <= 14:
    print("GRÜN")

print("4_tage_r_wert_berlin_rki:")
Daten = float(r.json()['index'][0]['4_tage_r_wert_berlin_rki'])
if Daten >= 1.2:
    print("ROT")
elif 1.1 <= Daten <= 1.2:
    print("GELB")
elif Daten <= 1.0:
    print("GRÜN")

#{"id":"877","datum":"2021-01-02","fallzahl":"98109","neue_faelle":"460","genesene":"79050","todesfaelle":"1285","7_tage_inzidenz":"130.7","rel_veraenderung_der_7_tage_inzidenz":"-21","its_belegung":"33.8","4_tage_r_wert_berlin_rki":"0"}],"item":[]}
