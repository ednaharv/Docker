FROM ubuntu:24.04

RUN  apt-get update; \
apt-get install -y gcc libfcgi-dev spawn-fcgi nginx; \
rm -rf /var/lib/apt/lists

RUN useradd -m nginx

COPY mini_server.c mini_server.c

COPY ./nginx/nginx.conf /etc/nginx/

COPY start.sh start.sh

RUN gcc -o mini_server mini_server.c -lfcgi; \
chmod +x start.sh; \
mkdir -p /var/lib/nginx/body; \
chown -R nginx:nginx /var/lib/nginx; \
chmod -R 777 /var/log/nginx/; \
chmod -R 777 /var/run/; \
chmod u-s /usr/bin/umount; \
chmod u-s /usr/bin/chsh; \
chmod u-s /usr/bin/passwd; \
chmod g-s /usr/bin/chage; \
chmod g-s /usr/bin/expiry; \
chmod u-s /usr/bin/gpasswd; \
chmod u-s /usr/bin/newgrp; \
chmod g-s /usr/sbin/unix_chkpwd; \
chmod u-s /usr/bin/chfn; \
chmod u-s /usr/bin/mount; \
chmod u-s /usr/bin/su; \
chmod g-s /usr/sbin/pam_extrausers_chkpwd || true

EXPOSE 80

HEALTHCHECK --interval=30s --timeout=10s --retries=3 CMD curl -f http://localhost/ || exit 1

USER nginx

CMD ["./start.sh"]
