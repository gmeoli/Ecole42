# Utilizza l'immagine baseDebian Buster
FROM debian:buster

# Aggiorna il sistema e installa le dipendenze necessarie
RUN apt-get update && apt-get install -y \
    php7.3-fpm \
    php7.3-mysql \
    && rm -rf /var/lib/apt/lists/*

# Copia il file di configurazione PHP-FPM nel container
COPY conf /etc/php/7.3/fpm/php-fpm.conf

# Crea una directory per il codice di WordPress
RUN mkdir -p /var/www/html

# Cambia il proprietario della directory a www-data (utente PHP-FPM)
RUN chown -R www-data:www-data /var/www/html

# Esponi la porta 9000 per la comunicazione con NGINX
EXPOSE 9000

# Imposta il comando di avvio per PHP-FPM
CMD ["php-fpm7.3", "-F"]
