#!/bin/sh

# Controlla se il file wp-config.php esiste
if [ -f ./wp-config.php ]
then
	echo "wordpress already downloaded"
else

####### MANDATORY #########

	#Scarica WordPress e i file di configurazione
	wget http://wordpress.org/latest.tar.gz
	tar xfz latest.tar.gz
	mv wordpress/* .
	rm -rf latest.tar.gz
	rm -rf wordpress

	# Importa le variabile env nei file di configurazione
	sed -i "s/username_here/$MYSQL_USER/g" wp-config-sample.php
	sed -i "s/password_here/$MYSQL_PASSWORD/g" wp-config-sample.php
	sed -i "s/localhost/$MYSQL_HOSTNAME/g" wp-config-sample.php
	sed -i "s/database_name_here/$MYSQL_DATABASE/g" wp-config-sample.php
	cp wp-config-sample.php wp-config.php
###########################
