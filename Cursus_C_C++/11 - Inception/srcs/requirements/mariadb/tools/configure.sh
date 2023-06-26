#!/bin/sh

# Inizializza il database MariaDB
mysql_install_db

# Avvia il servizio MariaDB
/etc/init.d/mysql start

# Controlla se già esiste il database $DB_NAME, altrimenti esegue lo script
if [ -d "/var/lib/mysql/$DB_NAME" ]
then 
	echo "Database already exists!"
else

# Imposta la password di root, rimuove gli utenti anonimi, disabilita il login remoto per l'utente root e ricarica i privilegi per rendere effettive le modifiche
mysql_secure_installation << _EOF_

Y
root1234
root1234
Y
n
Y
Y
_EOF_

# Crea un utente di root con privilegi di accesso da qualsiasi host, specifica la pswd e garantisce che le modifiche ai privilegi abbiano effetto immediato
echo "GRANT ALL ON *.* TO 'root'@'%' IDENTIFIED BY '$DB_ROOT_PASSWORD'; FLUSH PRIVILEGES;" | mysql -uroot

# Crea il database specificato, concede tutti i privilegi all'utente specificato con la relativa pswd e garantisce che le modifiche ai privilegi abbiano effetto immediato
echo "CREATE DATABASE IF NOT EXISTS $DB_NAME; GRANT ALL ON $DB_NAME.* TO '$DB_USER'@'%' IDENTIFIED BY '$DB_PASSWORD'; FLUSH PRIVILEGES;" | mysql -u root

# Importa il file wordpress.sql nel database spcificato. Il file contiene le istruzioni SQL per creare le tabelle e i dati necessari per il funzionamento di WordPress
mysql -uroot -p$DB_ROOT_PASSWORD $DB_DATABASE < /usr/local/bin/wordpress.sql

fi

echo "WordPress starting..."
/etc/init.d/mysql stop

exec "$@"
