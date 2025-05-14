COMPOSE	= ./docker-compose.yml
DATA	= /home/vboxuser/data


all:	up

install:
	@echo "Initializing, getting updates and installing docker..."
	@sudo apt-get update
	@sudo apt-get install -y docker.io
	@echo "Setting up Docker Compose v2..."
	@mkdir -p ~/.docker/cli-plugins/
	@curl -SL https://github.com/docker/compose/releases/latest/download/docker-compose-linux-x86_64 -o ~/.docker/cli-plugins/docker-compose
	@chmod +x ~/.docker/cli-plugins/docker-compose
	@echo "Verifying Docker and Docker Compose installation..."
	@docker --version
	@docker compose version
	@echo "Installation complete."

up:
	@docker compose -f $(COMPOSE) up -d

down:
	@docker compose -f $(COMPOSE) down -v

prune:
	@docker system prune -af

backup:
	@if [ -d $(DATA) ]; then \
		sudo tar -czvf ~/backup_data.tar.gz -C $(DATA) && echo "Backup created: ~/backup_data.tar.gz"; \
	else \
		echo "No data directory found, check the Makefile"; \
	fi

clean:	down prune

# This deletes the volumes, do not do unless the evaluation is over
fclean:	clean
		sudo rm -rf $(DATA)/wordpress_db/* $(DATA)/wordpress_files/*

status:
	@clear
	@echo "\nCONTAINERS\n"
	@docker ps -a
	@echo "\nIMAGES\n"
	@docker image ls
	@echo "\nVOLUMES\n"
	@docker volume ls
	@echo "\nNETWORKS\n"
	@docker network ls

re:	fclean up

.PHONY: all up down prune backup clean fclean status re
