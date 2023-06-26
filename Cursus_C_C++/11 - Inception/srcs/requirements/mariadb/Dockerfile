# Utilizza la penultima immagine di Alpine Linux
FROM	alpine:3.17

# Aggiorna il sistema, installa le dipendenze necessarie senza memorizzare la cache dei pacchetti
RUN	apk update && apk upgrade && apk add --no-cache \
	mariadb \
	mariadb-client

# Crea la directory, imposta i permessi di proprietà per l'utente 'mysql' e imposta i permessi di scrittura per tutti gli utenti sulla directory
# Questo è necessario per consentire l'avvio corretto di MariaDB
RUN	mkdir -p /var/run/mysqld \
	&& chown -R mysql:mysql /var/run/mysqld \
	&& chmod 777 /var/run/mysqld

# Copia i file di configurazione ed imposta i permessi di esecuzione
COPY	./tools/configure.sh /usr/local/bin/
COPY	./conf/wordpress.sql /usr/local/bin/
RUN	chmod +x /usr/local/bin/mariadb.sh
RUN	chmod +x /usr/local/bin/wordpress.sql

# Apre la porta per consentire la connessione
EXPOSE	3306

# Imposta l'entrypoint, quindi il comando predefinito quando si avvia il container
ENTRYPOINT	["/usr/local/bin/configure.sh"]

# Comando default per il container, che avvia MariaDB e consente le connessioni da qualsiasi indirizzo IP
CMD	["mysqld", "--bind-address=0.0.0.0"]
