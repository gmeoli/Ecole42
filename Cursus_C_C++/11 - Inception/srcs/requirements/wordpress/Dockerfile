# Utilizza l'immagine Alpine Linux
FROM	alpine:3.13

# Aggiorna il sistema operativo e installa i pacchetti necessari per WordPress e PHP-FPM senza memorizzare la cache dei pacchetti
RUN	apk update && apk upgrade && apk add --no-cache \
	wget \
	mariadb-client \
	tar \
	redis \
	php7 \
	php7-fpm \
	php7-bcmath \
	php7-bz2 \
	php7-calendar \
	php7-ctype \
	php7-curl \
	php7-dom \
	php7-exif \
	php7-fileinfo \
	php7-gd \
	php7-gmagick \
	php7-gmp \
	php7-iconv \
	php7-imap \
	php7-intl \
	php7-json \
	php7-mbstring \
	php7-mcrypt \
	php7-memcache \
	php7-mysqli \
	php7-mysqlnd \
	php7-openssl \
	php7-pcntl \
	php7-pdo \
	php7-pdo_mysql \
	php7-pdo_pgsql \
	php7-pdo_sqlite \
	php7-pgsql \
	php7-phar \
	php7-posix \
	php7-session \
	php7-shmop \
	php7-simplexml \
	php7-soap \
	php7-sockets \
	php7-sodium \
	php7-sqlite3 \
	php7-sysvsem \
	php7-sysvshm \
	php7-tokenizer \
	php7-xml \
	php7-xmlreader \
	php7-xmlwriter \
	php7-xsl \
	php7-zip \
	php7-zlib

# Aggiunge un utente e un gruppo chiamati "nginx" all'interno del container. Questo verrà utilizzato per eseguire il servizio PHP-FPM in modo sicuro
RUN	adduser -S nginx && addgroup -S nginx

# Copia il file di configurazione principale per PHP-FPM nella directory corretta all'interno del container
COPY	conf/php-fpm.conf	/etc/php7/php-fpm.conf

# Copia il file di configurazione per il pool di processi PHP-FPM nella directory corretta all'interno del container
COPY	conf/www.conf		/etc/php7/php-fpm.d/www.conf

# Scarica il file eseguibile WP-CLI, uno strumento per la gestione di WordPress da riga di comando, e lo rende eseguibile. Successivamente, sposta il file nella directory /usr/local/bin per renderlo disponibile nel percorso di esecuzione
RUN	wget https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar && chmod +x wp-cli.phar && mv wp-cli.phar /usr/local/bin/wp

# Imposta la directory di lavoro all'interno del container in cui saranno posizionati i file del servizio WordPress
WORKDIR	/var/www/html/wordpress

# Copia il file configure.sh nella directory temporanea /tmp all'interno del container
COPY	tools/configure.sh /tmp/configure.sh

# Imposta l'entrypoint, quindi il comando predefinito quando si avvia il container
ENTRYPOINT	["sh", "/tmp/configure.sh"]
