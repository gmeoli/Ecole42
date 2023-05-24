# Utilizza l'immagine più recente di Alpine Linux
FROM alpine:latest

# Aggiorna il sistema, installa le dipendenze necessarie ed elimina la cache
RUN apk update && apk upgrade && apk add --no-cache mariadb mariadb-client

# Copia il file di configurazione per MariaDB nella directory corrente
COPY tools/mariadb.sh .

# Imposta lo script mariadb.sh come punto di ingresso dell'immagine Docker. Quindi quando viene avviato il container
# verrà eseguito lo script per la configurazione per MariaDB
ENTRYPOINT	[ "sh", "mariadb.sh" ]
