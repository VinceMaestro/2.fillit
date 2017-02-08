# fillit
42 project fillit

:INFO: Algo (ft_getbestshape) en cours de debug


Rappel Git :
	Tu viens de modifier le fichier : "file.c"

	Avant de push :
	- git status
		- Si c'est marque : " On branch master
							  Your branch is up-to-date with 'origin/master'.
							  Changes not staged for commit:
  								(use "git add <file>..." to update what will be committed)
  								(use "git checkout -- <file>..." to discard changes in working directory)

								modified:		file.c "

			-> Alors tu peux :
				- git add .
				- git commit -m "Your message"
				- git push origin master


		- Si c'est marque : " On branch master
							  Your branch is behind master by x commit
							  You have unmerged paths.
								(fix conflicts an run "git commit")

							  Unmerged paths:
								(use "git add <file.c>" to mark resolution)

									both modified :		file.c "

			-> Ca veut dire que tu as modifié une ancienne version du fichier file.c
				(Meme si tu avais pull avant de commencer a modifier le fichier, c'est
				possible que le temps que tu le modifie, j'en ai push une autre version,
				auquel cas il considere que tu est en retard par rapport a la branche master)

			-> La le plus facile c'est:
			 	- deplacer ton (ou tes) fichier(s) listés dans le git status, en dehors du depot git
			 	- git pull
			 	- /!\ /!\ Les fichier que tu as pull sont different des tiens = quelqu'un a travaillé dessus /!\ /!\
			 	- Tu dois ouvrir les 2 versions de chaque fichier modifié (ta version et celle de git),
					et faire une fusion des 2 versions toi meme:
					 	- integrer tes changement au code du depot git
						 	OU
						- integrer les changement du depot git dans ton code && replacer ton fichier dans le depot git
				- Quand les changement pour chaque fichier ont integres:

					-> Alors tu peux :
						- git add .
						- git commit -m "Your message"
						- git push origin master

	CONGRATS : TU MAITRISES LES BASES DE GIT !!

MAKEFILE:

	all:

	clean:

	fclean:

	re

lancer:
./fillit test.txt

	ou

./fillit test2.txt
