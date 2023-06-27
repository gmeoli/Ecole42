#!/bin/sh

# Creazione directory per storare i certificati
mkdir /etc/ssl/private
chmod 700 /etc/ssl/private

# Creazione certificati SSL
openssl req -x509 -nodes -days 365 -newkey rsa:2048 -keyout ${CERTS_NGINX_KEY} -out ${CERTS_NGINX_CRT} -subj "/C=IT/ST=Italy/O=42/CN=Inception"

# Imposta le credenziali tramite le variabili di ambiente per la creazione database
sed -i 's|DOMAIN_NAME|'${DOMAIN_NAME}'|g' /etc/nginx/nginx.conf
sed -i 's|CERTS_NGINX_CRT|'${CERTS_NGINX_CRT}'|g' /etc/nginx/nginx.conf
sed -i 's|CERTS_NGINX_KEY|'${CERTS_NGINX_KEY}'|g' /etc/nginx/nginx.conf

# Runnando queto comando: "nginx -g daemon off;" mantiene Nginx in foreground (senza daemonizzazione)
nginx -g "daemon off;"
