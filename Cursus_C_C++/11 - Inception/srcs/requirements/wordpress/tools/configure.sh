#!/bin/sh

# Aspetta MariaDB, quindi si connette con le credenziali
# Questo loop assicura che lo script non proceda oltre finché MariaDB non è pronto per accettare le connessioni
while ! mariadb -h$DB_HOSTNAME -u$DB_ADMIN -p$DB_ADMIN_PWD $DB_NAME &>/dev/null;
do
    sleep 3
done

# Se il file esiste (WordPress non installato), non vengono eseguite le istruzioni
if [ ! -f "/var/www/html/wordpress/index.php" ];
then
	# Scarica la versione più recente di WordPress nella directory corrente
	wp core download --allow-root
	# Crea un file di configurazione con le credenziali specificate tramite le variabili di ambiente
	wp config create --dbname=$DB_NAME --dbuser=$DB_ADMIN --dbpass=$DB_ADMIN_PWD --dbhost=$DB_HOSTNAME --dbcharset="utf8" --dbcollate="utf8_general_ci" --allow-root 
	# Installa WordPress con le credenziali specifiche
	wp core install --url=$DOMAIN_NAME/wordpress --title="Inception" --admin_user=$WP_ADMIN_USR --admin_password=$WP_ADMIN_PWD --admin_email=$WP_ADMIN_EMAIL --skip-email --allow-root
	# Crea un nuovo utente con il ruolo di "autore" 
	wp user create $WP_USR $WP_EMAIL --role=author --user_pass=$WP_PWD --allow-root
	# Imposta il tema
	wp theme activate twentyseventeen --allow-root
else
	echo "Wordpress already installed!";
fi

echo "Wordpress starting..."

# viene eseguito il comando per avviare PHP-FPM in modalità foreground (-F) e con il reset delle statistiche (-R)
/usr/sbin/php-fpm7 -F -R
