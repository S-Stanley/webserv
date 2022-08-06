# How socket works

### Server

1. socket: creation de la socket
1. setsockopt: definir des options pour cette socket
1. bind: lie la socket avec l'ip et le port souhaiteé
1. listen: fais le serveur attendre une connexion
1. accept: traite la requete client

### Client

1. connect: met en relation la socket et le fd via l'adresse ip

[Voir article a ce sujet](https://fr.acervolima.com/programmation-de-sockets-en-c-c/)