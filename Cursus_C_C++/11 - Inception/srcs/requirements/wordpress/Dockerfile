# Utilizza l'immagine Alpine Linux
FROM	debian:buster

# Aggiorna il sistema operativo e installa i pacchetti necessari per WordPress e PHP-FPM senza memorizzare la cache dei pacchetti
RUN	apt-get update && apt-get -y install \
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

# Installa la CLI di WordPress, concede i permessi di esecuzione al file wp-cli.phar e lo sposta nella directory
RUN	curl -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar \
	&& chmod +x wp-cli.phar \
	&& mv wp-cli.phar /usr/local/bin/wp

# Copia il file di configurazione per il pool di processi PHP-FPM nella directory corretta all'interno del container
COPY	conf/www.conf		/etc/php7/php-fpm.d/www.conf

# Crea la directory dove starta php
RUN	mkdir /run/php

# Copia lo script di configurazione per WordPress, cambia i permessi per l'esecuzione ed imposta l'entrypoint all'avvio del container
COPY	./tools/configure.sh /usr/local/bin/
RUN	chmod +x /usr/local/bin/configure.sh
ENTRYPOINT	["/usr/local/bin/configure.sh"]

# Tutti i comandi successivi verranno eseguiti in questa directory
WORKDIR	/var/www/html/

# Espone la porta per comunicare con il servizio PHP-FPM
EXPOSE	9000

# Lancia PHP-FPM in modalità foreground (-F)
CMD	["/usr/sbin/php-fpm7.3", "-F"]
