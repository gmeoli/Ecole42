#!/bin/sh

# Inizializza il database di MariaDB
mysql_install_db

# Avvia il servizio MariaDB
/etc/init.d/mysql start

# Controlla se la directory del database specificato ($MYSQL_DATABASE) esiste già
if [ -d "/var/lib/mysql/$MYSQL_DATABASE" ]
then 
	echo "Database already exists"
else

# Avvia l'interfaccia di configurazione sicura di MariaDB
mysql_secure_installation << _EOF_

Y
user1234
user1234
Y
n
Y
Y
_EOF_

# Concede tutti i privilegi all'utente root e imposta una password per l'accesso
echo "GRANT ALL ON *.* TO 'root'@'%' IDENTIFIED BY '$MYSQL_ROOT_PASSWORD'; FLUSH PRIVILEGES;" | mysql -uroot

# Crea un database se non esiste già e concede tutti i privilegi all'utente specificato ($MYSQL_USER) su quel database
echo "CREATE DATABASE IF NOT EXISTS $MYSQL_DATABASE; GRANT ALL ON $MYSQL_DATABASE.* TO '$MYSQL_USER'@'%' IDENTIFIED BY '$MYSQL_PASSWORD'; FLUSH PRIVILEGES;" | mysql -u root

# Importa il file wordpress.sql nel database specificato
mysql -uroot -p$MYSQL_ROOT_PASSWORD $MYSQL_DATABASE < /usr/local/bin/wordpress.sql

# Fine condizione
fi

# Arresta il servizio MariaDB
/etc/init.d/mysql stop

# Esegue il comando specificato quando viene avviato il container. Questo consente di sovrascrivere il punto di ingresso predefinito dello script quando viene avviato il container
exec "$@"
