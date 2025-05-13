FROM debian:bullseye

RUN apt-get update -y && apt-get install mariadb-server -y

COPY ./tools/50-server.cnf /etc/mysql/mariadb.conf.d/

COPY ./tools/script.sh /

RUN mkdir -p /var/run/mysqld && chown -R mysql:mysql /var/run/mysqld && \
    mkdir -p /var/lib/mysql && chown -R mysql:mysql /var/lib/mysql

CMD ["/script.sh"]
