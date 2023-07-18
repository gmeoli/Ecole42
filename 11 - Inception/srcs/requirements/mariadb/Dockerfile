# Utilizza l'immagine di Alpine Linux
FROM alpine:3.13

# Aggiorna il sistema, installa le dipendenze necessarie senza memorizzare la cache dei pacchetti
RUN apk update && apk upgrade && \
    apk add --no-cache mariadb mariadb-client

# Copia il file di configurazione per MariaDB nella directory corrente
COPY tools/configure.sh /tmp/configure.sh

# Imposta l'entrypoint, quindi il comando predefinito quando si avvia il container
ENTRYPOINT [ "sh", "/tmp/configure.sh" ]
