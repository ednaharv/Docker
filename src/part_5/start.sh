#!/bin/sh
# Запуск mini_server через spawn-fcgi
spawn-fcgi -p 8080 ./mini_server

# Запуск Nginx
nginx -g 'daemon off;'
