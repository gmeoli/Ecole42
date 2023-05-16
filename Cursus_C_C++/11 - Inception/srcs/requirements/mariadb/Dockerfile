# Utilizza l'immagine baseDebian Buster
FROM debian:buster

# Aggiorna il sistema, installa le dipendenze necessarie ed elimina la cache
RUN apt-get update && apt-get install -y mariadb-server mariadb-client vim && rm -rf /var/lib/apt/lists/*

# Imposta i corretti permessi e proprietà per il corretto funzionamento del server MariaDB
RUN mkdir -p /var/run/mysqld && chown -R mysql:mysql /var/run/mysqld && chmod 777 /var/run/mysqld

# Espone la porta per la comunicazione con WordPress
EXPOSE 3306

# Copia i file e imposta i permessi per l'esecuzione
COPY ./tools/mariadb.sh /usr/local/bin/
COPY ./conf/wordpress.sql /usr/local/bin/
RUN chmod +x /usr/local/bin/mariadb.sh
RUN chmod +x /usr/local/bin/wordpress.sql

# Viene specificato che lo script è il punto di ingresso per l'esecuzione del servizio
ENTRYPOINT [ "/usr/local/bin/mariadb.sh" ]

# Imposta il comando di avvio per il container, che avvia il server MariaDB con l'opzione 
# --bind-address=0.0.0.0 per consentire le connessioni da qualsiasi indirizzo IP
CMD ["mysqld", "--bind-address=0.0.0.0"]
