FROM debian:bullseye


RUN apt-get update && apt-get install -y nginx openssl && apt-get clean && \
    openssl req -x509 -nodes -days 365 -newkey rsa:2048 \
    -keyout /etc/ssl/private/self-signed.key \
    -out /etc/ssl/certs/self-signed.crt \
    -subj "/C=DE/ST=Berlin/L=Berlin/O=42/OU=Inception/CN=hdorado-.42.fr"

RUN ls -l /etc/ssl/certs/self-signed.crt /etc/ssl/private/self-signed.key

RUN chmod 644 /etc/ssl/certs/self-signed.crt && chmod 600 /etc/ssl/private/self-signed.key

COPY ./conf/nginx.conf /etc/nginx/nginx.conf

EXPOSE 443

ENTRYPOINT ["nginx", "-g", "daemon off;"]
