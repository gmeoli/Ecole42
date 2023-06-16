#!/bin/bash

# Verifica se la directory esiste. Se non esiste, la crea e imposta i permessi di proprietà per l'utente mysql
if [ ! -d "/run/mysqld" ]; then
	mkdir -p /run/mysqld
	chown -R mysql:mysql /run/mysqld
fi

if [ ! -d "/var/lib/mysql/$DATABASE_NAME" ]; then
	chown -R mysql:mysql /var/lib/mysql
	# Inizializza database
	mysql_install_db --basedir=/usr --datadir=/var/lib/mysql --user=mysql --rpm > /dev/null

	# Esegue lo script SQL di configurazione direttamente su MariaDB
	mysql -u root <<-EOSQL
		USE mysql;
		FLUSH PRIVILEGES;
		DELETE FROM mysql.user WHERE User='';
		DROP DATABASE test;
		DELETE FROM mysql.db WHERE Db='test';
		DELETE FROM mysql.user WHERE User='root' AND Host NOT IN ('localhost', '127.0.0.1', '::1');

		ALTER USER 'root'@'localhost' IDENTIFIED BY '$DB_ROOT_PWD';

		CREATE DATABASE $DB_NAME DEFAULT CHARACTER SET utf8 DEFAULT COLLATE utf8_general_ci;
		CREATE USER '$DB_ADMIN'@'%' IDENTIFIED BY '$DB_ADMIN_PWD';
		GRANT ALL PRIVILEGES ON $DB_NAME.* TO '$DB_ADMIN'@'%';
		FLUSH PRIVILEGES;
	EOSQL
fi

sed -i 's/skip-networking/# skip-networking/g' /etc/my.cnf.d/mariadb-server.cnf
sed -i "s/#bind-address=.*/bind-address=0.0.0.0/g" /etc/my.cnf.d/mariadb-server.cnf

echo "MariaDB starting..."

exec /usr/bin/mysqld --user=mysql --console
