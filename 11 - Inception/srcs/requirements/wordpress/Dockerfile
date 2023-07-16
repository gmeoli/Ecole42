FROM debian:buster

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

# I need to install wp_cli command and put it in the right directory /usr/local/bin
RUN curl -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar \
  && chmod +x wp-cli.phar \
  && mv wp-cli.phar /usr/local/bin/wp

<<<<<<< HEAD
# Copy the .conf in the html directory
COPY ./conf/www.conf /etc/php/7.3/fpm/pool.d/
=======
# Copia il file di configurazione principale per PHP-FPM nella directory corretta all'interno del container
# COPY	conf/php-fpm.conf	/etc/php7/php-fpm.conf
>>>>>>> inception

#Create the folder to enable php start
RUN mkdir /run/php

<<<<<<< HEAD
#we copy the script, give the right to launch it in local on our computer
COPY ./tools/create_wordpress.sh /usr/local/bin/
RUN chmod +x /usr/local/bin/create_wordpress.sh
ENTRYPOINT ["/usr/local/bin/create_wordpress.sh"]

#We go the html directory
WORKDIR /var/www/html/
=======
# Imposta la directory di lavoro all'interno del container in cui saranno posizionati i file del servizio WordPress

# Scarica il file eseguibile WP-CLI, uno strumento per la gestione di WordPress da riga di comando, e lo rende eseguibile. Successivamente, sposta il file nella directory /usr/local/bin per renderlo disponibile nel percorso di esecuzione
RUN	wget https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar && chmod +x wp-cli.phar && mv wp-cli.phar /usr/bin/wp

WORKDIR	/var/www/html/wordpress
>>>>>>> inception

#We expose the 9000 port
EXPOSE 9000

#Launch PHP FPM in foreground and ignore deamonize from conf file (-F)
CMD ["/usr/sbin/php-fpm7.3", "-F"]
