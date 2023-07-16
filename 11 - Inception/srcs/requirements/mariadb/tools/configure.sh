#!/bin/sh

if [ ! -d "/run/mysqld" ]; then
	mkdir -p /run/mysqld
	chown -R mysql:mysql /run/mysqld
fi

if [ ! -d "/var/lib/mysql/mysql" ]; then
	chown -R mysql:mysql /var/lib/mysql
	mysql_install_db --basedir=/usr --datadir=/var/lib/mysql --user=mysql --rpm > /dev/null

	temp='temp'
	if [! -f "$temp"]; then
		return 1
	fi

	cat << EOF > $temp

USE mysql;
FLUSH PRIVILEGES;
DELETE FROM mysql.user WHERE User = '';
DROP DATABASE test;
DELETE FROM mysql.db WHERE Db = 'test';
DELETE FROM mysql.user WHERE User = 'root' AND Host NOT IN ('localhost', '127.0.0.1', '::1');
ALTER USER 'root'@'localhost' IDENTIFIED BY '$DB_ROOT_PWD';
CREATE DATABASE $DB_NAME CHARACTER SET utf8 COLLATE utf8_general_ci;
CREATE USER '$DB_ADMIN'@'%' IDENTIFIED by '$DB_ADMIN_PWD';
GRANT ALL PRIVILEGES ON $DB_NAME.* TO '$DB_ADMIN'@'%';
FLUSH PRIVILEGES;
EOF

	/usr/bin/mysqld --user=mysql --bootstrap < $temp
	rm -f $temp
fi

sed -i "s|skip-networking|# skip-networking|g" /etc/my.cnf.d/mariadb-server.cnf
sed -i "s|.*bind-address\s*=.*|bind-address=0.0.0.0|g" /etc/my.cnf.d/mariadb-server.cnf

exec /usr/bin/mysqld --user=mysql --console


# #!/bin/sh

# # Verifica se la directory esiste. Se non esiste, la crea e imposta i permessi di proprietà per l'utente mysql
# if [ ! -d "/run/mysqld" ];
# then
# 	mkdir -p /run/mysqld
# 	chown -R mysql:mysql /run/mysqld
# fi

# if [ ! -d "/var/lib/mysql/mysql" ];
# then
# 	chown -R mysql:mysql /var/lib/mysql
# 	# Inizializza database
# 	mysql_install_db --basedir=/usr --datadir=/var/lib/mysql --user=mysql --rpm > /dev/null

# 	# Esegue lo script SQL di configurazione direttamente su MariaDB
# 	mysql -u root <<-EOF
# 		USE mysql;
# 		FLUSH PRIVILEGES;
# 		DELETE FROM mysql.user WHERE User='';
# 		DROP DATABASE test;
# 		DELETE FROM mysql.db WHERE Db='test';
# 		DELETE FROM mysql.user WHERE User='root' AND Host NOT IN ('localhost', '127.0.0.1', '::1');

# 		ALTER USER 'root'@'localhost' IDENTIFIED BY '$DB_ROOT_PWD';

# 		CREATE DATABASE $DB_NAME DEFAULT CHARACTER SET utf8 DEFAULT COLLATE utf8_general_ci;
# 		CREATE USER '$DB_ADMIN'@'%' IDENTIFIED BY '$DB_ADMIN_PWD';
# 		GRANT ALL PRIVILEGES ON $DB_NAME.* TO '$DB_ADMIN'@'%';
# 		FLUSH PRIVILEGES;
# 	EOF
# fi


# sed -i 's/skip-networking/# skip-networking/g' /etc/my.cnf.d/mariadb-server.cnf
# sed -i "s/#bind-address=.*/bind-address=0.0.0.0/g" /etc/my.cnf.d/mariadb-server.cnf

# echo "MariaDB starting..."

# exec /usr/bin/mysqld --user=mysql --console
