#!/bin/sh

# Controlla se il file wp-config.php gia esiste, altrimenti esegue lo script
if [ -f ./wp-config.php ]
then
	echo "WordPress already exists!"
else

	# Scarica l'archivio di WordPress, lo estrae, rinomina i file di configurazione di esempio
	wget http://wordpress.org/latest.tar.gz
	tar xfz latest.tar.gz # Questo comando estrae l'archivio compresso di WordPress utilizzando il comando tar. L'opzione xfz specifica l'estrazione (x), l'archivio compresso con formato gzip (f), e la modalità silenziosa (z).
	mv wordpress/* .
	rm -rf latest.tar.gz
	rm -rf wordpress

	# Importa le variabili .env nel file di configurazione
	sed -i "s/username_here/$DB_ADMIN/g" wp-config-sample.php
	sed -i "s/password_here/$DB_PASSWORD/g" wp-config-sample.php
	sed -i "s/localhost/$DB_HOSTNAME/g" wp-config-sample.php
	sed -i "s/database_name_here/$DB_NAME/g" wp-config-sample.php
	cp wp-config-sample.php wp-config.php

fi

echo "WordPress starting..."

exec "$@"
