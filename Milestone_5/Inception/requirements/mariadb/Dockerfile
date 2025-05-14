FROM debian:bullseye

RUN apt-get update -y && apt-get install mariadb-server -y && apt-get clean

COPY ./conf/50-server.cnf /etc/mysql/mariadb.conf.d/

COPY ./tools/entrypoint.sh /entrypoint.sh

RUN mkdir -p /var/run/mysqld && chown -R mysql:mysql /var/run/mysqld && \
    mkdir -p /var/lib/mysql && chown -R mysql:mysql /var/lib/mysql && \
    chmod +x /entrypoint.sh

ENTRYPOINT ["/entrypoint.sh"]
