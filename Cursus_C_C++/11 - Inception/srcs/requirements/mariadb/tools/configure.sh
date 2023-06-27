#!/bin/sh

# Inizializzazione e creazione database
if [ ! -f "/var/lib/mysql/ib_buffer_pool" ];
then
	/etc/init.d/mariadb setup
	rc-service mariadb start
	
	# Crea un nuovo database se non esiste
	echo "DROP DATABASE test;" | mysql -u root
	echo "CREATE DATABASE IF NOT EXISTS ${DB_NAME};" | mysql -u root

	# Crea un nuovo utente e assegna tutti i privilegi
	echo "CREATE USER '${DB_USER}'@'%' IDENTIFIED BY '${DB_PASSWORD}';" | mysql -u root
	echo "GRANT ALL PRIVILEGES ON wordpress.* TO '${DB_USER}'@'%' IDENTIFIED BY '${DB_PASSWORD}';" | mysql -u root
	echo "FLUSH PRIVILEGES;" | mysql -u ${DB_ROOT_PASSWORD}
	
	# Cambia la pswd per l'utente root
    mysql -u root -e "ALTER USER 'root'@'localhost' IDENTIFIED BY '${MYSQL_ROOT_PASS}';"
fi

# Comment skip-networking
sed -i 's/skip-networking/# skip-networking/g' /etc/my.cnf.d/mariadb-server.cnf
sed -i 's/#bind-address=0.0.0.0/bind-address=0.0.0.0/g' /etc/my.cnf.d/mariadb-server.cnf

rc-service mariadb restart
rc-service mariadb stop

# Esegue queto comando "/usr/bin/mariadbd" per lasciarlo in foreground
/usr/bin/mariadbd --basedir=/usr --datadir=/var/lib/mysql --plugin-dir=/usr/lib/mariadb/plugin --user=mysql --pid-file=/run/mysqld/mariadb.pid
