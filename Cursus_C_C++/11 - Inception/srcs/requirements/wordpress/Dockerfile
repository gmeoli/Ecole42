# Utilizza l'immagine baseDebian Buster
FROM debian:buster

# Aggiorna il sistema, installa le dipendenze necessarie
# e viene pulita la cache dei pacchetti per ridurre la dimensione dell'immagine
RUN apt-get update && apt-get -y install \
	wget \
	curl \
	bash \
	php \
	php-cgi \
	php-mysql \
	php-fpm \
	php-pdo \
	php-gd php-cli \
	php-mbstring \
	redis \
	php-redis \
	&& rm -rf /var/lib/apt/lists/*

# Scarica il file eseguibile di WP-CLI, uno strumento a linea di comando per la gestione di Wordpress
# e lo sposta nella directory /usr/local/bin rendendolo eseguibile
RUN curl -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar \
  && chmod +x wp-cli.phar \
  && mv wp-cli.phar /usr/local/bin/wp

# Copia il file di configurazione all'interno del container
COPY ./conf/www.conf /etc/php/7.3/fpm/pool.d/

# Creazione cartella per gestire i socket e i file temporanei
RUN mkdir /run/php

# Copiano lo script nel container e impostano i permessi per l'esecuzione. Infine viene specificato che lo script è
# il punto di ingresso per l'esecuzione del servizio
COPY ./tools/create_wordpress.sh /usr/local/bin/
RUN chmod +x /usr/local/bin/create_wordpress.sh
ENTRYPOINT ["/usr/local/bin/create_wordpress.sh"]

# Crea la cartella root dove Wordpress sarà installato
WORKDIR /var/www/html/

# Esponi la porta 9000 per la comunicazione con NGINX
EXPOSE 9000

# Imposta il comando di avvio per PHP-FPM in modalità foreground, quindi gestire le richieste PHP in modo continuo
CMD ["php-fpm7.3", "-F"]
