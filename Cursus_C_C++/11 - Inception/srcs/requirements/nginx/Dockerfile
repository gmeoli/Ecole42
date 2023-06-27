# Utilizza la penultima immagine di Alpine Linux
FROM	alpine:3.17

# Aggiorna il sistema operativo e installa i pacchetti necessari per NGINX e OPENSSL senza memorizzare la cache dei pacchetti
RUN	apk update && apk upgrade && apk add --no-cache nginx openssl

# Crea la cartella all'interno del container che sarà la directory radice dei file del sito web servito da NGINX
RUN	mkdir -p /var/www/html

# Copia il file di configurazione principale per NGINX
COPY	conf/nginx.conf /etc/nginx/conf.d/default.conf

COPY	tools/configure.sh /
RUN	chmod +x /configure.sh

# Apre l'unica porta consentita
EXPOSE	443

# Imposta l'entrypoint, quindi avvia il file di configurazione
ENTRYPOINT	["sh", "./tools/configure.sh"]
