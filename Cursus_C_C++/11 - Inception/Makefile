<<<<<<< HEAD
all:
	@docker compose -f ./srcs/docker-compose.yml up -d --build
=======
all: first start

first:
	@sudo mkdir -p /home/gmeoli/Desktop/inception/wordpress
	@sudo mkdir -p /home/gmeoli/Desktop/inception/mariadb
	@echo "127.0.0.1 gmeoli.42.fr" > /etc/hosts
	@echo "127.0.0.1 www.gmeoli.42.fr" >> /etc/hosts
	@echo "localhost gmeoli.42.fr" >> /etc/hosts
	@echo "localhost www.gmeoli.42.fr" >> /etc/hosts
>>>>>>> inception

start:
	@docker compose -f ./srcs/docker-compose.yml build
	@docker compose -f ./srcs/docker-compose.yml up

stop:
	@docker compose -f ./srcs/docker-compose.yml stop

<<<<<<< HEAD
clean:
	@docker stop $$(docker ps -qa);\
	docker rm $$(docker ps -qa);\
	docker rmi -f $$(docker images -qa);\
	docker volume rm $$(docker volumes ls -q);\
	docker network rm $$(docker network ls -q);\
=======
fclean:
	@docker compose -f ./srcs/docker-compose.yml down
	docker system prune -af
	sudo rm -fr /home/gmeoli/Desktop/inception

re: fclean first start
>>>>>>> inception

.PHONY: all first start stop fclean re
