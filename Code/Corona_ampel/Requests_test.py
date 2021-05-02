from phue import Bridge
import json
import requests
from datetime import date, timedelta, datetime  # Time is important
import logging
from apscheduler.schedulers.blocking import BlockingScheduler
from gpiozero import TrafficLights
Ampel1 = TrafficLights(4, 3, 2) #ampel eins defenieren

Ampel2 = TrafficLights(22 ,27,17)  # ampel zwei defenieren

Ampel3 = TrafficLights(26, 19, 13)  # ampel drei defenieren

logging.basicConfig(filename='Requests.log', level=logging.INFO,format='%(message)s')  # logging conf
def Corona_ampel():
    # get the API data.
    r = requests.get('https://www.berlin.de/lageso/gesundheit/infektionsepidemiologie-infektionsschutz/corona/tabelle-indikatoren-gesamtuebersicht/index.php/index/today.json')

    abfrage = ("Daten abgefragt: " + datetime.now().strftime('%Y-%m-%d %H:%M:%S'))
    logging.info(abfrage)
    print("Daten abgefragt: " + datetime.now().strftime('%Y-%m-%d %H:%M:%S'), "\n") # Get the date for the Request, so the printout is more organiesd even after a longer time of running.

    print("Daten vom:", r.json()['index'][0]['datum'], "\n") # Get the date for the Data thats being used, so the printout is more organiesd even after a longer time of running.

    raw = ("Raw Data: ", r.json()['index'][0])  # print the latest info in the terminal.
    logging.info(raw)


    # 7 tage inzidenz abfragen
    tage = float(r.json()['index'][0]['7_tage_inzidenz'])
    if tage >= 30:  # wenn über 30
        data = ("7_tage_inzidenz -", float(r.json()['index'][0]['7_tage_inzidenz']), "- ROT")
        logging.info(data) 
        print("7_tage_inzidenz -", float(r.json()['index'][0]['7_tage_inzidenz']), "- ROT", "\n")
        Ampel1.red.on()
        Ampel1.green.off()
        Ampel1.amber.off()
    elif 20 <= tage <= 30:  # wenn unter 30
        data = ("7_tage_inzidenz -", float(r.json()['index'][0]['7_tage_inzidenz']), "- GELB")
        logging.info(data)
        print("7_tage_inzidenz -", float(r.json()['index'][0]['7_tage_inzidenz']), "- GELB", "\n")
        Ampel1.red.off()
        Ampel1.green.off()
        Ampel1.amber.on()
    elif tage <= 19:  # wenn unter 20
        data = ("7_tage_inzidenz -", float(r.json()['index'][0]['7_tage_inzidenz']), "- GRUEN")
        logging.info(data)
        print("7_tage_inzidenz -", float(r.json()['index'][0]['7_tage_inzidenz']), "- GRÜN", "\n")
        Ampel1.red.off()
        Ampel1.green.on()
        Ampel1.amber.off()



    #its_belegung
    its = float(r.json()['index'][0]['its_belegung'])
    if its >= 25:
        data = ("its_belegung -", float(r.json()['index'][0]['7_tage_inzidenz']), "- ROT")
        logging.info(data)
        print("its_belegung -", float(r.json()['index'][0]['7_tage_inzidenz']), "- ROT", "\n")
        Ampel2.red.on()
        Ampel2.green.off()
        Ampel2.amber.off()
    elif 15 <= its <= 25:
        data = ("its_belegung -", float(r.json()['index'][0]['7_tage_inzidenz']), "- GELB")
        logging.info(data)
        print("its_belegung -", float(r.json()['index'][0]['7_tage_inzidenz']), "- GELB", "\n")
        Ampel2.red.off()
        Ampel2.green.off()
        Ampel2.amber.on()
    elif its <= 14:
        data = ("its_belegung -", float(r.json()['index'][0]['7_tage_inzidenz']), "- GRUEN")
        logging.info(data)
        print("its_belegung -", float(r.json()['index'][0]['7_tage_inzidenz']), "- GRÜN", "\n")
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
            data = ("4_tage_r_wert_berlin_rki -", float(r.json()['index'][index]['4_tage_r_wert_berlin_rki']), "- ROT")
            logging.info(data)
            print("4_tage_r_wert_berlin_rki -", float(r.json()['index'][index]['4_tage_r_wert_berlin_rki']), "- ROT","\n")
            Ampel1.red.on()
            Ampel1.green.off()
            Ampel1.amber.off()
        elif 1.1 <= rWert <= 1.2:
            data = ("4_tage_r_wert_berlin_rki -", float(r.json()['index'][index]['4_tage_r_wert_berlin_rki']), "- GELB")
            logging.info(data)
            print("4_tage_r_wert_berlin_rki -", float(r.json()['index'][index]['4_tage_r_wert_berlin_rki']), "- GELB","\n")
            Ampel2.red.off()
            Ampel2 .green.off()
            Ampel2.amber.on()
        elif rWert <= 1.0:
            data = ("4_tage_r_wert_berlin_rki -", float(r.json()['index'][index]['4_tage_r_wert_berlin_rki']), "- GRUEN")
            logging.info(data)
            print("4_tage_r_wert_berlin_rki -", float(r.json()['index'][index]['4_tage_r_wert_berlin_rki']), "- GRÜN","\n")
            Ampel3.red.off()
            Ampel3.green.on()
            Ampel3.amber.off()

    print("done")
    print("----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------")
    print("")
    logging.info("--------------------------------------------------------------------------------------------------------------------------------------------------")

scheduler = BlockingScheduler()
scheduler.add_job(Corona_ampel, 'cron', hour=19)
scheduler.start()
#{"id":"877","datum":"2021-01-02","fallzahl":"98109","neue_faelle":"460","genesene":"79050","todesfaelle":"1285","7_tage_inzidenz":"130.7","rel_veraenderung_der_7_tage_inzidenz":"-21","its_belegung":"33.8","4_tage_r_wert_berlin_rki":"0"}],"item":[]}
