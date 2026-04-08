# CashManagement-System
Software gestionale in C++ per l'automazione dei flussi di cassa, bilancio giornaliero e persistenza dati.

Questo applicativo è nato da un'esigenza reale: ottimizzare e automatizzare la gestione della cassa per una rete di punti vendita retail.

## 🚀 Funzionalità principali
- **Gestione Apertura/Chiusura:** Verifica automatica del fondo cassa e calcolo discrepanze.
- **Persistenza Dati:** Lettura e scrittura su file (`cassa.txt`) per mantenere lo storico delle operazioni.
- **Sistema di Backup:** Generazione automatica di file di backup per la sicurezza dei dati finanziari.
- **Reportistica:** Generazione di un file `report.txt` con il riepilogo dettagliato di incassi, buste ed esterni.

## 🛠️ Note Tecniche
Il software è scritto in **C++** e utilizza strutture dati personalizzate (`struct`) e gestione avanzata degli stream di input/output (`fstream`).
