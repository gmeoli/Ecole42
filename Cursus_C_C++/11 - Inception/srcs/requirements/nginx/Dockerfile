# Utilizza l'immagine base Debian Buster
FROM debian:buster

# Aggiorna il sistema operativo e installa i pacchetti necessari per NGINX e OPENSSL
RUN apt-get update && apt-get install -y nginx && apt-get update && apt-get install -y openssl

# Crea la cartella e genera i certificati SSL/TLS e la chiave privata
RUN mkdir /etc/nginx/ssl
RUN openssl req -newkey rsa:4096 -x509 -sha256 -days 365 -nodes \
       -out /etc/nginx/ssl/gmeoli.crt \
       -keyout /etc/nginx/ssl/gmeoli.key \
       -subj "/C=IT/ST=Italy/L=Rome/O=42 School/OU=gmeoli/CN=gmeoli/"

# Copia il file di configurazione NGINX all'interno del container
COPY ./conf/nginx.conf /etc/nginx/nginx.conf

# Esponi la porta 443 per comunicare con Internet
EXPOSE 443

# Archiviare i file di log, i file temporanei e altre informazioni necessarie per il funzionamento del server
RUN mkdir -p /run/nginx

# Start NGINX
CMD ["nginx", "-g", "daemon off;"]
