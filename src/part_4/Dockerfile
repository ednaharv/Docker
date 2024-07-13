FROM nginx

RUN apt-get update && apt-get install -y gcc libfcgi-dev spawn-fcgi nginx

COPY mini_server.c mini_server.c

COPY ./nginx/nginx.conf /etc/nginx/

COPY start.sh start.sh

RUN gcc -o mini_server mini_server.c -lfcgi && chmod +x start.sh

EXPOSE 80

CMD ["./start.sh"]
