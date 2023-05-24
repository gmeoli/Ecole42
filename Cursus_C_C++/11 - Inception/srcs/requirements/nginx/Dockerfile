# Utilizza l'immagine Alpine Linux
FROM	alpine:3.13

# Aggiorna il sistema operativo e installa i pacchetti necessari per NGINX e OPENSSL senza memorizzare la cache dei pacchetti
RUN	apk update && apk upgrade && apk add --no-cache nginx openssl

# Crea la cartella all'interno del container per archiviare i certificati SSL
RUN	mkdir -p /etc/nginx/ssl 

# Crea la cartella all'interno del container per archiviare i file temporanei di NGINX
RUN	mkdir -p /run/nginx

# Crea la cartella all'interno del container che sarà la directory radice dei file del sito web servito da NGINX
RUN	mkdir -p /var/www/html

# Copia il file di configurazione principale per NGINX
COPY	conf/nginx.conf /etc/nginx/conf.d/default.conf

# Utilizzando Openssl, viene generato un certificato SSL autofirmato con paramentri predefiniti, specificando dove salvarlo ed il nome utente intestatario
RUN	openssl req -newkey rsa:2048 \
	-x509 \
	-sha256 \
	-days 365 \
	-nodes \
	-keyout /etc/nginx/ssl/gmeoli.key \
	-out /etc/nginx/ssl/gmeoli.pem \
	-subj "/C=IT/ST=Italy/L=Rome/O=42Rome/OU=$gmeoli/CN=$gmeoli"

# Imposta l'entrypoint, quindi il comando predefinito quando si avvia il container
ENTRYPOINT	[ "nginx", "-g", "daemon off;" ]
