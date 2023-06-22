# Utilizza l'immagine di Alpine Linux
FROM	alpine:latest

# Aggiorna il sistema, installa le dipendenze necessarie senza memorizzare la cache dei pacchetti
RUN	apk update && apk upgrade && apk add --no-cache \
	mariadb \
	mariadb-client

# Copia il file di configurazione per MariaDB nella directory corrente
COPY	tools/configure.sh .

# Imposta l'entrypoint, quindi il comando predefinito quando si avvia il container
ENTRYPOINT	[ "sh", "configure.sh" ]
