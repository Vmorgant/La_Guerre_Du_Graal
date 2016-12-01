#La Guerre Du Graal
# Projet Algorithmique et programmation
#L2 SPI
LEBOURDAIS Martin PETIT Corentin MORGANT Victor

Règle du jeu : 2 équipes composées de différents personnages combattent (le nombre de personnages est limité par le nombre de points d’équipe défini dans les règles). Chaque joueur place ses personnages en début de partie de son coté de la map. Les joueurs contrôlent leurs personnages un à un et choisissent une ou plusieurs actions à effectuer pour un total de point d’action défini à l’avance. Chaque personnage gagne un nombre de point d’action pour chaque tour.
La partie se termine lorsque l’une des équipes est éliminée(tous les personnages sont morts).
Les personnage sont basés sur l’anime  et le jeu Fate Stay Night.

#Installation de la SDL : 

*Télécharger les sources sur le site de la SDL http://libsdl.org/download-2.0.php et les extraire.

*Ouvrir un terminal.

*Entrez la commande "cd" pour vous placer à la racine puis "mkdir SDL" pour créer le dossier de la SDL.

*Déplacer vers le dossier où vous avez extrait l'archive.

*Entrez la commande : 

-"./configure " si vous êtes super-utilisateur
-"./configure --prefix=$HOME/SDL" sinon 

*Entrez la commande "make"

*Entrez la commande :

-"sudo make install" si vous êtes super-utilisateur
-"make install" sinon

