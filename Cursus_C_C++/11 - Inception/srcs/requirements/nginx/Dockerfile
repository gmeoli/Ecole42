# Utilizza l'immagine base Debian Buster
FROM debian:buster

# Aggiorna il sistema operativo, installa i pacchetti necessari per NGINX e OPENSSL
RUN apt-get update && apt-get install -y nginx && apt-get update && apt-get install -y openssl

# Genera i certificati SSL/TLS e la chiave privata
RUN openssl req -newkey rsa:2048 -nodes -keyout /etc/nginx/server.key -x509 -days 365 -out /etc/nginx/server.crt -subj "/CN=mydomain.com"

# Copia il file di configurazione NGINX all'interno del container
COPY conf /etc/nginx/nginx.conf

# Esponi la porta 9000 per comunicare con il container di WordPress
EXPOSE 9000

# Esponi la porta 443 per comunicare con Internet
EXPOSE 443

# Imposta la direzione di lavoro predefinita
WORKDIR /var/www/html

# Avvia NGINX al momento dell'avvio del container
CMD ["nginx", "-g", "daemon off;"]
