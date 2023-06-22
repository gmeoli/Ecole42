all:
	@docker compose -f ./srcs/docker-compose.yml up -d

start:
	@docker compose -f ./srcs/docker-compose.yml start

stop:
	@docker compose -f ./srcs/docker-compose.yml stop

clean:
	@docker stop $$(docker ps -qa);\
	docker rm $$(docker ps -qa);\
	docker rmi -f $$(docker images -qa);\
	docker volume rm $$(docker volumes ls -q);\
	docker network rm $$(docker network ls -q) 2>/dev/null;\

.PHONY: all start stop clean
