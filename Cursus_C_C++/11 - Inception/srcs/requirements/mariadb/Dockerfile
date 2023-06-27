# Utilizza la penultima immagine di Alpine Linux
FROM	alpine:3.17

# Aggiorna il sistema, installa le dipendenze necessarie senza memorizzare la cache dei pacchetti
RUN	apk update && apk upgrade && apk add --no-cache \
	mariadb \
	mariadb-common \
	mariadb-client \
	openrc

# Start OpenRC
RUN	openrc && touch /run/openrc/softlevel

# Copia il file di configurazione ed assegna i permessi di esecuzione
COPY	./tools/configure.sh /
RUN	chmod +x /configure.sh

# Imposta l'entrypoint, quindi all'avvio del container il file di setup
ENTRYPOINT	["sh", "/configure.sh"]
