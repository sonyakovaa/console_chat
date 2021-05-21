﻿# Консольный чат (C++, Qt)
При запуске приложение спрашивает, как запуститься: как сервер или как клиент.

Если приложение запускается как сервер, то далее спрашивает порт и сервер начинает слушать порт.
Если приложение запускается как клиент, то спрашивает IP-адрес и порт, пытаясь подключиться к серверу.

При успешном подключении и сервер, и клиент выводят сообщение об успешном подключении. В противном случае выводится ошибка.

Далее начинается бесконечный цикл обмена сообщениями. Клиент запрашивает у пользователя ввод текста, а сервер ждет входящее сообщение. После ввода текста клиент отправляет сообщение серверу. Сервер выводит сообщение на экран и предлагает пользователю ввести ответ, клиент тем временем ждет. После ввода сообщения сервер отправляет его клиенту, клиент выводит сообщение на экран. Цикл повторяется.

Считается что размер одного сообщения не более 1000 символов.
